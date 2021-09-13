/*
    [문제 1]
    키보드로부터 데이터를 입력 받고, 입력 받은 데이터를 입력 순서 그대로 출력하는 프로그램을 작성하자.
    단, 반드시 다음 순서와 포맷으로 입력을 받아야 한다(콤마를 포함하여).

    [실행의 예]
    [문자, 정수, 실수, 문자열]의 포맷으로 입력: c, 7, 3.14, Good
    입력된 데이터 출력: c, 7, 3.140000, Good
*/

#include <stdio.h>

int main(void)
{
    char ch;
    int in;
    double dou;
    char string[20];

    printf("[문자, 정수, 실수, 문자열]의 포맷으로 입력: ");
    scanf("%c, %d, %lf, %s", &ch, &in, &dou, string);

    printf("입력된 데이터 출력: %c, %d, %lf, %s\n", ch, in, dou, string);
    return 0;
}