#include "../include/student.h"
#include <stdio.h>
int main() {
    Student s;
    int button;

    while(1) {
        printf("1: 등록 0: 종료\n");
        printf("선택: ");
        scanf("%d", &button);
        while(getchar() != '\n');
        if (button == 1) {
        insert_student(&s);
    } else if (button == 0) {
        printf("프로그램 종료\n");
        break;
    } else {
        printf("잘못된 번호입니다.");
    }
} 
  return 0;   
}