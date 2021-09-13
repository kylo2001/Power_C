/*
    [문제 11-2]
    정수 n을 입력 받는다(단, n은 2 이상이 입력되어야 한다). 
    그리고 1부터 시작해서 다음과 같은 형태로 점진적인 덧셈을 진행한다.
    1+2+3+4+5+6+ ...
    이 때 얼마를 더하는 순간부터 덧셈의 결과가 n보다 커지기 시작하는지, 그리고 n보다 
    커지기 전과 n보다 커진 후의 덧셈 결과를 출력하는 프로그램을 구현하자.

    [실행의 예]
    2 이상 입력 : 20
    6을 더할 때 처음 20을 넘기 시작한다.
    20을 넘기 이전의 합 : 15
    20을 넘은 직후의 합 : 21
*/

#include <stdio.h>

int main(void)
{
    int number, total = 0, i = 0;

    fputs("2 이상 입력 : ", stdout);
    scanf("%d", &number);

    while (1)
    {
        if (number < 2)
            fputs("2 이상 입력해주세요.\n", stdout);
        else
            break;
    }

    while (number > (total + i))
    {
        total += i;
        i++;
    }

    printf("%d을(를) 더할 때 처음 %d을(를) 넘기 시작한다.\n", i, number);
    printf("%d을(를) 넘기 이전의 합 : %d\n", number, total);
    printf("%d을(를) 넘은 이후의 합 : %d\n", number, total + i);

    return 0;
}