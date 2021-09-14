/*
    [문제 24-1]
    strtok 함수 예제

    [실행의 예]
    010
    1111
    3333
*/

/*
    ! strtok 함수의 반환값은 첫 번째 토큰의 주소이다.
    ! 29행에서 첫 번째 전달인자로 NULL을 지정하는 것은 
    ! 25행에서 지정해 놓은 토큰관련 정보를 가지고 두 번째 이후의 토큰 주소 값을 얻기 위함이다.
    ! strtok 함수는 토큰을 구분하여 별도의 메모리 공간에 저장하는 행위는 하지 않는다.
    ! 단지 원본 문자열을 기준으로 토큰이 되는 위치의 주소 값만을 반환할 뿐이다.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "010-1111-3333"; //토큰을 나눌 문자열
    char *delim = "-";            //토큰을 나누는 기준
    char *token;

    token = strtok(str, delim);

    while (token != NULL)
    {
        puts(token);
        token = strtok(NULL, delim);
    }

    return 0;
}