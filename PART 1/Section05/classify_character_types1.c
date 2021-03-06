/*
    [문제 16-1]
    일단 문자열을 입력 받자. 그리고 입력 받은 문자열 중에서 알파벳 대문자는 소문자로,
    소문자는 대문자로 각각 변경하여 출력하는 프로그램을 작성하자.
    단, 알파벳 이외의 문자가 존재하면 특별한 변경 없이 출력하는 것으로 한다.

    1. 두가지 버전으로 구현하자, 
        1-1. 하나는 배열을 사용하여 입력된 문자열을 배열을 통해서 한번에 읽어들인다. 
        1-2. 또 다른 하나는 배열을 사용하지 않는 방법이다. 
            배열을 사용하지 않는다면, 문자열의 길이를 제한할 필요가 없다. 
            그러나 배열을 사용하면 그 길이를 제한할 수 밖에 없다. 
            따라서 배열을 사용할 경우에는 입력되는 문자열의 길이가 256을 넘지 않는다고 가정하자.
    2. 아스키코드 표를 참고하거나, 아스키코드의 숫자 값을 프로그램 코드에 직접 써 넣으면 안된다.

    [실행의 예]
    문자열 입력 : What Is Your Name?
    wHAT iS yOUR nAME?
*/

#include <stdio.h>
#include <string.h>
#define STR_LEN 256

int main(void)
{
    char str[STR_LEN]; // 첫 번째 방법(배열 사용)

    fputs("문자열 입력 : ", stdout);
    fgets(str, STR_LEN, stdin);

    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 'a' - 'A';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
    }

    printf("%s", str);

    return 0;
}