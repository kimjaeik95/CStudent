#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insert_student(Student* s) {
    // 엔터를치는것도 \n 버퍼에 담기기때문에 제거해야한다.
    char buffer[20];
    printf("학생 정보를 입력하세요\n");
    printf("이름: ");
    fgets(s->name, sizeof(s->name), stdin);
    while(getchar() != '\n');
    // fgets 문자열 공백 가능, 문자열 단위입력, 버퍼크기지정 
    printf("번호: ");
    fgets(s->phone, sizeof(s->phone), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("전공: ");
    fgets(s->major, sizeof(s->major), stdin);
    while(getchar() != '\n');

    printf("학점: ");
    fgets(buffer, sizeof(buffer), stdin);
    s->grade = atoi(buffer); // 숫자입력시 문자열로 버퍼임시 저장후 문자열을 숫자형을 변경후 구조체저장 

    printf("재학상황 {0: 재학, 1: 휴학, 2: 졸업} : ");
    fgets(s->state, sizeof(s->state), stdin); // 임시 버퍼 포인터에 저장
    while(getchar() != '\n');

    printf("담당교수: ");
    fgets(s->advisor, sizeof(s->advisor), stdin);

    FILE* fp = fopen("student.dat", "ab");
    if (fp == NULL) {
        perror("파일이 없습니다.");
        return;
    }
    
    fwrite(s, sizeof(Student),1, fp);
    fclose(fp);

    printf("학생 등록이 완료되었습니다.\n");
};

void delete_student(Student* s) {
    /* 기존파일 조회 
       새로운파일 덮혀씌우기
    */ 
    FILE* fp = fopen("student.dat", "rb");
    FILE* temp = fopen("temp.dat", "wb");
    if (fp == NULL) {
        perror("파일이 없습니다.");
        return;
   }
   
   char deleteKey[10]; // 바로 대입하면 배열 통째로 저장되서 안됨
   strcpy(deleteKey, s->phone); // 배열 하나하나 복사 

   Student tempStudent; // 임시구조체 생성
   while (fread(&tempStudent, sizeof(Student),1, fp) == 1) { // 데이터저장주소, 레코드크기, 레코드 읽을 수, 읽는파일
    if (strcmp(tempStudent.phone, deleteKey) == 0) { // 찾으면 0 반환 
        continue;
    } 
    fwrite(&tempStudent,sizeof(Student),1, temp);
}
   fclose(fp);
   fclose(temp);
   
   remove("student.dat"); // 원본삭제
   rename("temp.dat", "student.dat"); // 다음 조회도위해 파일이름 변경

   printf("학생 정보가 삭제되었습니다.\n");
};


void allList_student() {
    FILE* fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        perror("파일이 없습니다.");
        return;
    }
    Student tempStudent; // 읽어온 학생을 담을 빈 구현체
    int count = 0; // 학생 수 카운트
    while(fread(&tempStudent, sizeof(Student),1,fp) == 1) {
        count++;
        printf("이름: %s 핸드폰: %s 전공: %s 학점: %.1f 재학상황: %s 담당교수: %s  \n"
            ,tempStudent.name,tempStudent.phone,tempStudent.major,tempStudent.grade,tempStudent.state,tempStudent.advisor);
    }

    fclose(fp);
    printf("학생의 총수 %d\n", count);
    
}
