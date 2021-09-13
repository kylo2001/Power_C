/*
    [문제 1]
    정수 n1과 n2를 입력 받는다. 그리고 n1부터 n2까지의 합을 계산해서 그 결과를 출력하되, 
    3의 배수이거나, 5의 배수이면 총 합에서 제외시키는 프로그램을 작성하자. 이 문제는 문제 9-2를 확장한 것이다. 
    또한, 제외된 수들의 정보를 출력하도록 구현하자.

    [실행의 예]
    두 개의 정수 입력 : 2 10
    3은 합에서 제외.
    5는 합에서 제외.
    6은 합에서 제외.
    9는 합에서 제외.
    10은 합에서 제외.
    2와 10을 포함하여 그 사이에 있는 정수들의 합 : 21
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#define IS_MULTIPLE_OF_3(n) (n % 3 == 0) ? true : false
#define IS_MULTIPLE_OF_5(n) (n % 5 == 0) ? true : false

int factorial(int n1, int n2)
{
    while (IS_MULTIPLE_OF_3(n1) || IS_MULTIPLE_OF_5(n1))
    {
        printf("%d는 합에서 제외.\n", n1);
        n1++;
        if (n1 > n2)
            break;
    }

    if (n1 >= n2)
        return (IS_MULTIPLE_OF_3(n2) || IS_MULTIPLE_OF_5(n2)) ? 0 : n2;

    return n1 + factorial(n1 + 1, n2);
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