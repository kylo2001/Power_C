/*
    [문제 22]
    아래와 같은 유형의 물음에 모두 답할 수 있는 함수를 정의하자.

    ? "이 문자열에는 문자 T가 몇 개 들어있나요?"
    ? "이 문자열에는 문자 m이 몇 개 들어있나요?"
    ? "이 문자열에는 문자 S가 몇 개 들어있나요?"

    1. 최소 두 개의 매개변수 선언이 필요하다.
        1-1. 하나는 문자열이 저장된 배열의 주소 값
        1-2. 검색의 대상이 되는 문자정보
    2. 문자의 개수는 return 문을 통해서 반환하기로 하자. 
    3. 문자열의 길이는 널(NULL) 문자를 포함하여 100을 넘지 않는다고 가정한다.

    [실행의 예]
    대상 문자열 입력 : Ha! Ha! Ha!
    세어 볼 문자 입력 : a
    a의 개수 : 3
*/

#include <stdio.h>
#include <string.h>
#define STR_LEN 100

int find(char *str, int str_len, char ch)
{
    int count = 0;

    for (int i = 0; i < str_len; i++)
        if (str[i] == ch)
            count++;

    return count;
}

int main(void)
{
    char ch;
    char str[STR_LEN];
    int result;

    fputs("대상 문자열 입력 : ", stdout);
    fgets(str, STR_LEN, stdin);

    fputs("세어 볼 문자 입력 : ", stdout);
    ch = getchar();

    result = find(str, strlen(str), ch);
    printf("%c의 개수 : %d\n", ch, result);
    return 0;
}