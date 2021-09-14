/*
    [문제 19]
    프로그램 사용자로부터 정수 하나를 입력 받아서, 입력 받은 수의 팩토리얼을 계산하여 그 결과를 출력하는 프로그램을 작성한다.
    
    1. Factorial 함수를 정의한다.

    [실행의 예]
    숫자 입력(1이상) : 5
    5! = 120
*/

#include <stdio.h>
#define FATOR_ONEUNDER_ERROR -100

int factorial(int n)
{
    int result = 1;

    if (n < 1)
        return FATOR_ONEUNDER_ERROR;

    for (int i = 1; i <= n; i++)
        result *= i;

    return result;
}

int main(void)
{
    int n, result;

    fputs("숫자 입력(1이상) : ", stdout);
    scanf("%d", &n);

    result = factorial(n);

    if (result == FATOR_ONEUNDER_ERROR)
    {
        puts("입력이 잘못되어 예상치 못한 결과를 얻었습니다.");
    }
    else
    {
        printf("%d! = %d\n", n, result);
    }

    return 0;
}