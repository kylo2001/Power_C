/*
    [문제 7-1]
    실수(정수가 아닌 실수이다) 두 개를 입력 받아서, 두 실수의 사칙연산 결과를 출력하는 프로그램을 작성하여라.

    [실행의 예]
    두 개의 실수 입력 : 3.7 2.5
    덧셈 결과 : 6.200000
    뺄셈 결과 : 1.200000
    곱셈 결과 : 9.250000
    나눗셈 결과 : 1.480000
*/

#include <stdio.h>

int main(void)
{
    double x, y;

    fputs("두 개의 실수 입력 : ", stdout);
    scanf("%lf%lf", &x, &y);

    printf("덧셈 결과 : %lf\n", x + y);
    printf("뺄셈 결과 : %lf\n", x - y);
    printf("곱셈 결과 : %lf\n", x * y);
    printf("나눗셈 결과 : %lf\n", x / y);
    return 0;
}