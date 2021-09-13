/*
    [문제 9-2]
    정수 n1과 n2를 입력 받는다. 그리고 n1부터 n2까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하자.
    예를 들어서 2와 5를 입력 받는다면, 2+3+4+5 즉, 14를 출력해야한다.
    또한, 5와 2를 입력 받더라도, 14를 출력해야한다.

    [실행의 예]
    두 개의 정수 입력 : 12 7
    12와 7을 포함하여 그 사이에 있는 정수들의 합 : 57
*/

#include <stdio.h>
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

int factorial(int n1, int n2)
{
    if (n2 == n1)
        return n1;
    return n2 + factorial(n1, n2 - 1);
}

int main(void)
{
    int n1, n2, result;

    fputs("두 개의 정수 입력 : ", stdout);
    scanf("%d%d", &n1, &n2);

    result = factorial(MIN(n1, n2), MAX(n1, n2));

    printf("%d와 %d을 포함하여 그 사이에 있는 정수들의 합 : %d\n", n1, n2, result);

    return 0;
}