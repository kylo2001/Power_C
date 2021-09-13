/*
    [문제 4]
    입력 받은 정수 n 이하의 자연수 중에서 짝수의 합과, 홀수의 합을 각각 계산하여 출력하는 프로그램 구현하자.
    참고로 자연수라 함은 0보다 큰 정수를 의미한다.

    [실행의 예]
    자연수 입력 : 12
    12이하 홀수 합 : 36
    12이하 짝수 합 : 42
*/

#include <stdio.h>

int main(void)
{
    int number, odd_sum = 0, even_sum = 0;

    fputs("자연수 입력 : ", stdout);
    scanf("%d", &number);

    for (int i = number; i > 0; i--)
    {
        if (!(i % 2))
            even_sum += i;
        else
            odd_sum += i;
    }

    printf("%d 이하 홀수 합 : %d\n", number, odd_sum);
    printf("%d 이하 짝수 합 : %d\n", number, even_sum);

    return 0;
}