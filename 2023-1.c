#include "stdlib.h"
#include "stdio.h"
#include "string.h"


int main(){
    char buff[100], *name, *dept, *studentID;

    printf("이름을 공백없이 영문으로 입력하시오. (예: Honggildong) : ");
    scanf("%s", buff);
    name = (char *)malloc(strlen(buff) + 1);
    strcpy(name, buff);

    printf("학과를 공백없이 영문으로 입력하시오. (예: ComputerScience) : ");
    scanf("%s", buff);
    dept = (char *)malloc(strlen(buff) + 1);
    strcpy(dept, buff);

    printf("학번을 입력하시오. (예: 202334-123456) : ");
    scanf("%s", buff);
    studentID = (char *)malloc(strlen(buff) + 1);
    strcpy(studentID, buff);

    printf("======= 처리 결과 =======\n");
    printf("이름 홀수번째 문자만 순방향 출력 : ");
    for (int i = 0; i < strlen(name); i += 2) {
        printf("%c", name[i]);
    }
    printf("\n");

    printf("학과 짝수번째 문자만 역방향 출력 : ");
    for (int i = strlen(dept) - 1; i >= 0; i -= 1) {
        if (i % 2 == 1) {
            printf("%c", dept[i]);
        }
    }
    printf("\n");

    printf("학번 홀수번째 문자 * 로 출력 : ");
    for (int i = 0; i < strlen(studentID); i++) {
        if (i % 2 == 0) {
            printf("*");
        } else {
            printf("%c", studentID[i]);
        }
    }
    printf("\n");

    printf("-----------------------------\n");
}