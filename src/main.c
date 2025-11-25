#include "../include/student.h"
#include <stdio.h>
int main() {
    Student s;
    int button;

    while(1) {
        printf("1: 등록 2: 삭제 3: 학생조회 0: 종료\n");
        printf("선택: ");
        scanf("%d", &button);
        while(getchar() != '\n');
        if (button == 1) {
        insert_student(&s);
    } else if (button == 2) {
        printf("삭제할 회원의 핸드폰 번호를 입력하세요 :"); // 고유 번호가 핸드폰번호밖에없음 
        fgets(s.phone,sizeof(s.phone), stdin); // 빈 구조체에 내가 찾을 핸드폰번호만 저장
        while(getchar() != '\n');
        delete_student(&s);
    } else if (button == 3) {
        printf("학생을 전체 조회합니다.\n");
        allList_student();
    } else if (button == 0) {
        printf("프로그램 종료\n");
        break;
    } else {
        printf("잘못된 번호입니다.");
    }
} 
  return 0;   
}