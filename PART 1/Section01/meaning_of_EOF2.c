/*
    [문제 2]
    키보드로부터 EOF가 입력될 때까지 숫자를 입력 받아서, 입력된 숫자의 총 합을 출력하는
    프로그램을 작성한다.

    [문제 2의 실행의 예]
    Data input (Ctrl+Z to exit) : 10
    Data input (Ctrl+Z to exit) : 20
    Data input (Ctrl+Z to exit) : ^D
    총 합 : 30
*/

#include <stdio.h>

int main(void)
{
    int res, input, total = 0;

    while (1)
    {
        fputs("Data input (Ctrl+Z to exit) : ", stdout);
        res = scanf("%d", &input);

        if (res == EOF)
        {
            printf("\n총 합 : %d\n", total);
            break;
        }
        else
        {
            total += input;
        }
    }

    return 0;
}

/*
    ! scanf 함수가 EOF를 읽게 되면 EOF을 반환한다.
    ! 여기서 fflush(stdin)을 해주지 않는 것일까??
    ! scanf함수에서 숫자를 입력받겠다고 %d로 명시해줬다.
    ! 따라서 화이트 스페이스(탭, 공백, 엔터)를 무시한다.
*/
