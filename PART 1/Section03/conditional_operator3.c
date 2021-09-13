/*
    [문제 3]
    정수 n을 입력 받는다. 그리고 1부터 입력 받은 정수 n가지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하자.
    예를 들어서 5를 입력 받는다면, 1+2+3+4+5 즉, 15를 출력해야한다.

    [실행의 예]
    1 이상의 정수 입력 : -10
    1 이상의 정수를 입력해야 합니다.
    1 이상의 정수 입력 : 10
    1부터 10까지의 합은 55.
*/

#include <stdio.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n + factorial(n - 1);
}

int main(void)
{
    int n, result;

    fputs("1 이상의 정수 입력 : ", stdout);
    scanf("%d", &n);
    while (1)
    {
        if (n < 1)
        {
            fputs("1 이상의 정수를 입력해야 합니다.\n", stdout);
            continue;
        }
        else
        {
            result = factorial(n);
            break;
        }
    }

    printf("1부터 %d까지의 합은 %d.\n", n, result);

    return 0;
}