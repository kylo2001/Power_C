/*
    [문제 24-3]
    StringTokenize 함수를 구현하자.
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

/*
    ! 내가 구현한 함수
char *StringTokenize(char *str, char *delim)
{
    int i = 1;
    static char *tokens[3] = {};
    static int token_count = 1;

    if (str == NULL)
    {
        if ((token_count + 1) <= 3)
            return tokens[token_count++];
        else
            return NULL;
    }
    else
    {
        tokens[0] = str;

        while (1)
        {
            if (str[i] == '\0')
                break;
            else
            {
                if (str[i] == *delim)
                {
                    str[i] = '\0';
                    tokens[token_count] = &str[i + 1];
                    token_count++;
                }

                i++;
            }
        }

        token_count = 1;
        return tokens[0];
    }
}

*/

char *StringTokenize(char *str, char *delim)
{
    static char *nextTokenPos; // 정적 변수
    char *curTokenPos;         // 현재 토큰 위치
    char *curStrPos;           // 현재 문자열의 위치

    if (str != NULL)
    {
        curTokenPos = str;         // 첫 번째 토큰 초기화를 해준다.
        curStrPos = str;           // 문자열 위치 초기화
        nextTokenPos = (char *)-1; // 이 변수는에는 문자열의 끝에 도달하면 NULL이 저장되는데 이와 구분 짓기 위해서 -1로 초기화 하였다.
    }
    else
    { //다음 번 토큰을 얻기 위해서 함수가 다시 호출되었을 때 실행되는 영역
        curTokenPos = nextTokenPos;
        curStrPos = nextTokenPos;
    }

    // 모든 토큰이 반환되었을때는 NULL을 반환한다.
    if (nextTokenPos == NULL)
        return NULL;

    // 토큰을 찾기 위해서 문자를 하나씩 비교하는 과정
    while (1)
    {
        // 문자열의 끝에 도달했는지 제일 먼저 검사
        if (*curStrPos == 0)
        {
            nextTokenPos = NULL;
            break;
        }

        // 문자열의 끝이 아니라면, 토큰 구분문자인지 검사
        if (*curStrPos == delim[0])
        {
            *curStrPos = 0;
            nextTokenPos = curStrPos + 1;
            break;
        }

        // 문자열의 끝이 아니고, 토큰 구분 문자가 아니라면 문자열 위치를 하나 증가시킨다.
        curStrPos++;
    }
    return curTokenPos;
}

int main(void)
{
    char str[] = "111-2222-3333"; //토큰을 나눌 문자열
    char *delim = "-";            //토큰을 나누는 기준
    char *token;

    printf("문자열의 주소 : %d\n", str);
    token = StringTokenize(str, delim);

    while (token != NULL)
    {
        printf("토큰의 주소 : %d\n", token);
        puts(token);
        token = StringTokenize(NULL, delim);
    }
    puts(str); // 원본 문자열이 바뀐 것을 확인할 수 있다.
    return 0;
}