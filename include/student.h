typedef struct student {
    char name[10]; // 이름 
    char phone[16]; // 핸드폰
    char major[10]; // 전공
    float grade; // 학점
    char state[7]; // 재학,졸업 상황
    char advisor[20]; // 담당 교수
} Student;

void insert_student(Student* s); 
void delete_student(Student* s);
void allList_student();