/*
    [문제 14]
    총 다섯 개의 숫자를 입력 받아서 작은 수에서 큰 수의 순으로 정렬하여 출력하는 프로그램을 작성하자.
    
    1. 총 다섯 개의 숫자를 입력 받기 위해 길이가 5인 배열을 선언
    2. 오름차순으로 정렬할 것
    3. 버블 정렬을 구현한다.

    [실행의 예]
    숫자 1 입력 : 3
    숫자 2 입력 : 2
    숫자 3 입력 : 5
    숫자 4 입력 : 1
    숫자 5 입력 : 4
    정렬된 출력 : 1 2 3 4 5
*/

#include <stdio.h>
#define ARR_LEN 5

int main(void)
{
    int ary[ARR_LEN];

    for (int i = 0; i < ARR_LEN; i++)
    {
        fputs("숫자 입력 : ", stdout);
        scanf("%d", &ary[i]);
    }

    for (int i = ARR_LEN - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            int temp;

            if (ary[j] > ary[j + 1])
            {
                temp = ary[j + 1];
                ary[j + 1] = ary[j];
                ary[j] = temp;
            }
        }
    }

    fputs("정렬된 출력 : ", stdout);

    for (int i = 0; i < ARR_LEN; i++)
    {
        printf("%d ", ary[i]);
    }

    return 0;
}