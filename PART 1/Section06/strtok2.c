/*
    [문제 24-2]
    아래와 같이 strtok 함수와 똑같이 동작하는 StringTokenize 함수를 구현하자.
    단, strtok와 100% 똑같은 함수를 구현하기에는 조금 힘들수 있기 때문에 개발 범위에 제한을 둔다.

    1. strtok함수는 토큰을 나누는 기준이 두개 이상이 될 수 있다. 하지만 여기서는 한 개로 제한한다.
    2. 토큰을 나누는 기준 문자는 문자열의 앞과 뒤에 등장하지 않는다.
    3. 둥 이상의 토큰 구분 문자가 이어지지도 않는다.

        "-010-1111-3333-"
        "000--1111--2222"

    4. 전역변수는 사용하지 않는다.

    [실행의 예]
    문자열의 주소 : 1245008
    토큰의 주소 : 1245008
    111
    토큰의 주소 : 1245012
    2222
    토큰의 주소 : 1245017
    3333
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "111-2222-3333"; //토큰을 나눌 문자열
    char *delim = "-";            //토큰을 나누는 기준
    char *token;

    printf("문자열의 주소 : %d\n", str);
    token = strtok(str, delim);

    while (token != NULL)
    {
        printf("토큰의 주소 : %d\n", token);
        puts(token);
        token = strtok(NULL, delim);
    }
    puts(str); // 원본 문자열이 바뀐 것을 확인할 수 있다.
    return 0;
}