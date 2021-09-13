/*
    [문제 12-2]
    정수 n을 입력 받는다. 그리고 다음 수식을 만족하는 정수 a, b, c의 모든 조합을 찾아서 출력하는 프로그램을 작성하자.
    단, a, b그리고 c 값의 범위는 0 이상 100 이하로 제한한다.
    
    1. for문을 총 세 번 중첩시켜야 한다.

    [실행의 예]
    정수 입력 : 12
    (1) X (12) - (0) = (12)
    (1) X (13) - (1) = (12)
    (1) X (14) - (2) = (12)
    --- 이하 생략 ---
*/

#include <stdio.h>
#define MIN_VALUE 0
#define MAX_VALUE 100

int main(void)
{
    int number;

    fputs("정수 입력 : ", stdout);
    scanf("%d", &number);

    for (int i = MIN_VALUE; i <= MAX_VALUE; i++)
    {
        for (int j = MIN_VALUE; j <= MAX_VALUE; j++)
        {
            for (int k = MIN_VALUE; k <= MAX_VALUE; k++)
            {
                if (i * j - k == number)
                {
                    printf("(%d) X (%d) - (%d) = (%d)\n", i, j, k, number);
                }
            }
        }
    }

    return 0;
}