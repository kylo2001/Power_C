/*
    [문제]
    7개의 숫자를 정수 형태로(반드시 정수 형태로 입력 받는다) 입력 받아서 입력 받은 수들의 최대값, 최소값, 전체 합 그리고 평균을 구하는 프로그램을 작선한다. 
    단, 평균은 정확히 계산하여 소수점 이하까지 출력한다.
    또한, 7개의 변수 또는 배열을 사용하지 않는다.

    [실행의 예]
    정수형 데이터 입력 : 3
    정수형 데이터 입력 : 4
    정수형 데이터 입력 : 2
    정수형 데이터 입력 : 3
    정수형 데이터 입력 : 5
    정수형 데이터 입력 : 7
    정수형 데이터 입력 : -12
    최대값 : 7
    최소값 : -12
    전체합 : 12
    평균 : 1.714286
*/

#include <stdio.h>
#define MAX_DATA_COUNT 7
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a > b) ? b : a

int main(void)
{
    int number, max, min, total;

    for (int i = 0; i < MAX_DATA_COUNT; i++)
    {
        fputs("정수형 데이터 입력 : ", stdout);
        scanf("%d", &number);

        if (i == 0)
        {
            max = number;
            min = number;
            total = number;
        }
        else
        {
            max = MAX(number, max);
            min = MIN(number, max);
            total += number;
        }
    }

    printf("최대값 : %d\n", max);
    printf("최소값 : %d\n", min);
    printf("전체합 : %d\n", total);
    printf("평 균 : %lf\n", total / (double)MAX_DATA_COUNT);

    return 0;
}