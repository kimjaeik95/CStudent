#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insert_student(Student* s) {
    char buffer[20];
    printf("학생 정보를 입력하세요\n");
    printf("이름: ");
    fgets(s->name, sizeof(s->name), stdin);
    while(getchar() != '\n');
    // fgets 문자열 공백 가능, 문자열 단위입력, 버퍼크기지정 
    printf("번호: ");
    fgets(s->phone, sizeof(s->phone), stdin);
    while(getchar() != '\n');

    printf("전공: ");
    fgets(s->major, sizeof(s->major), stdin);
    while(getchar() != '\n');

    printf("학점: ");
    fgets(buffer, sizeof(buffer), stdin);
    s->grade = atoi(buffer); // 숫자입력시 문자열로 버퍼임시 저장후 문자열을 숫자형을 변경후 구조체저장 

    printf("재학상황 {0: 재학, 1: 휴학, 2: 졸업} : ");
    fgets(buffer, sizeof(buffer), stdin); // 임시 버퍼 포인터에 저장
    s->state = atoi(buffer); // 변환후 저장

    printf("담당교수: ");
    fgets(s->advisor, sizeof(s->advisor), stdin);

    FILE* fp = fopen("student.dat", "ab");
    if (fp == NULL) {
        perror("파일이 없습니다.");
        return;
    } 
    fwrite(s, sizeof(Student),1, fp);
    fclose(fp);
};
