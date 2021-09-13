/*
    [문제 2]
    세 개의 숫자를 입력 받아서 그 중 큰 수를 출력하는 프로그램을 구현하여라. 
    단, if 관련 문장을 사용해야 한다면 이를 대신해서 조건 연산자를 사용하기로 하자. 

    [실행의 예]
    세 개의 숫자를 입력하세요 : 3 7 12
    큰 수는 12
*/

#include <stdio.h>
#define MAX(a, b) (a > b) ? a : b

int main(void)
{
    int num1, num2, num3;

    fputs("세 개의 숫자를 입력하세요 : ", stdout);
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("큰 수는 %d\n", MAX(MAX(num1, num2), num3));

    return 0;
}