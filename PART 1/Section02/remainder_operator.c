/*
    [문제 6]
    정수형 데이터를 10진수로 입력 받아서 해당 데이터의 2진수 표현을 출력하는 프로그램을 구현해보자.
    배열을 쓰지 않고 구현해보자.

    [실행의 예]
    10진수 정수 입력 : 12
    12를 2진수로 변환하면 : 1100
*/

#include <stdio.h>

int decimal_to_Binary(int decimal)
{
    int binary = 0;

    for (int i = 0; decimal > 0; i++)
    {
        int digit = 1;
        for (int j = i; j > 0; j--)
            digit *= 10;

        binary += (decimal % 2) * digit;
        decimal /= 2;
    }

    return binary;
}

int main(void)
{
    int num;

    fputs("10진수 정수 입력 : ", stdout);
    scanf("%d", &num);

    printf("%d를 2진수로 변환하면 : %d\n", num, decimal_to_Binary(num));

    return 0;
}