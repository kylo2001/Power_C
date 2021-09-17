/*
    [문제 26-2]
    길이가 정해지지 않은 문자열을 5개를 입력받고 오름차순으로 정렬하여 출력하자.
    최종적인 구현에 앞서 ReadString 함수를 구현한다.

    함수는 문자열을 읽어들여 할당된 메모리 공간에 저장한 다음, 할당한 메모리릐 주소 값을 반환한다.


    함   수 : char *ReadString()
    기   능 : 키보드로부터 입력되는 문자열을 읽어 들인다.
    입   력 : 없음
    반   환 : 읽어 들인 문자열을 저장하고 있는 배열의 주소 값
    특이사항 : 1. 문자열을 위해 힙에 메모리 공간을 할당한다.
                따라서 반드시 반환되는 포인터를 대상으로 free 함수를 호출

    [실행의 예]
    java
    C
    C++
    java
    C
    C++
*/

#include <stdio.h>
#include <stdlib.h>

char *ReadString(void);

char *ReadString(void)
{
    int maxStringLen = 10;
    char *str = (char *)malloc(sizeof(char) * maxStringLen);
    int idx = 0;

    while (1)
    {
        // if (idx >= maxStringLen)
        //     maxStringLen = ExtendMemForString(&str, strlen);
        str[idx] = getchar();
        if (str[idx] == '\n')
        {
            str[idx] = 0;
            break;
        }
        idx++;
    }

    return str;
}

int main(void)
{
    char *strArr[3];
    strArr[0] = ReadString();
    strArr[1] = ReadString();
    strArr[2] = ReadString();

    puts(strArr[0]);
    puts(strArr[1]);
    puts(strArr[2]);

    free(strArr[0]);
    free(strArr[1]);
    free(strArr[2]);
    return 0;
}