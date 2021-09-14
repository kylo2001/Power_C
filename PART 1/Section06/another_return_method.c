/*
    [문제 20]
    정수 나눗셈 연산의 결과로 몫과 나머지를 반환하는 함수 DivInt를 정의하고, 이를 테스트 할 수 있는 main 함수를 정의하자. 
    DivInt 함수는 정수 나눗셈의 결과로 몫과 나머지 두 가지를 반환해야 하는데 return에 의한 반환이 아닌, 매개 변수 전달을
    통한 값의 반환이 이뤄지도록 정의를 하자(Call By Reference방식의 함수 정의)
    그리고 제수가 0일 때에는(0으로 나누는 잘못된 연산을 하려고 할 때에는) -259을 return 문에 의해 반환하도록 함수를 정의하자. 
    -256은 0으로 나누는 잘못된 연산이 요청되었음을 표현하기 위해서 임의로 정한 숫자이다.
    
    1. 제수가 0일때에는 -256, 정상일때에는 1을 반환
    2. 둘 이상의 값을 반환하기 위해서 구조체를 사용하지 않는다.
    3. 제수가 0이 되면 나눗셈 가능한 숫자가 입력될때까지 재요청하자. 

    [실행의 예]
    나눗셈을 위한 두 정수 입력 : 7 0
    0으로 나누는 오류발생! 숫자 재입력

    나눗셈을 위한 두 정수 입력 : 5 2
    몫 : 2, 나머지 : 1
*/

#include <stdio.h>
#define DIVIDE_BY_ZERO -256

int DivInt(int dividend, int divisor, int *quotient, int *remainder)
{
    if (divisor == 0)
        return DIVIDE_BY_ZERO;
    else
    {
        *quotient = dividend / divisor;
        *remainder = dividend % divisor;
    }

    return 1;
}

int main(void)
{
    int dividend, divisor, quotient, remainder, result;

    while (1)
    {
        fputs("나눗셈을 위한 두 정수 입력 : ", stdout);
        scanf("%d%d", &dividend, &divisor);

        result = DivInt(dividend, divisor, &quotient, &remainder);

        if (result == DIVIDE_BY_ZERO)
        {
            printf("0으로 나누는 오류발생! 숫자 재입력\n\n");
            continue;
        }
        else
        {
            printf("몫 : %d, 나머지 : %d\n", quotient, remainder);
            break;
        }
    }

    return 0;
}