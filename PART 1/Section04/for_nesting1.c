/*
    [문제 12-1]
    대표적인 for문 중첩 예제인 구구단 출력 프로그램을 작성해보자. 그냥 전체를 출력하는
    프로그램은 너무 단순한 관계로 1이 입력되면 홀수 단을(3, 5, 7, 9), 2가 입력되면 짝수 단을(2, 4, 6, 8) 출력하도록 하자.
    
    1. for문을 사용하자. 
    2. 중첩된 for문을 한번만 사용하자.

    [실행의 예]
    홀수 단(1), 짝수 단(2) : 3
    잘못된 입력입니다. 1 또는 2만 입력하세요.

    홀수 단(1), 짝수 단(2) : 2
    2 X 1 = 2
    2 X 2 = 4
    2 X 3 = 6
    --- 중간 생략 ---
    8 X 7 = 56
    8 X 8 = 64
    8 X 9 = 72
*/

#include <stdio.h>

void print_odd_multiplication_table()
{
    for (int i = 3; i <= 9; i += 2)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d X %d = %d\n", i, j, i * j);
        }
        puts("");
    }
}

void print_even_multiplication_table()
{
    for (int i = 2; i < 9; i += 2)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d X %d = %d\n", i, j, i * j);
        }
        puts("");
    }
}

int main(void)
{
    int menu;

    while (1)
    {
        fputs("홀수 단(1), 짝수 단(2) : ", stdout);
        scanf("%d", &menu);

        if (menu == 1)
        {
            print_odd_multiplication_table();
            break;
        }
        else if (menu == 2)
        {
            print_even_multiplication_table();
            break;
        }
        else
        {
            fputs("잘못된 입력입니다. 1 또는 2만 입력하세요.\n", stdout);
        }
    }

    return 0;
}