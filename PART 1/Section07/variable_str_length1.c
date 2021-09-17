/*
    [문제 26-1]
    길이가 정해지지 않은 문자열을 5개를 입력받고 오름차순으로 정렬하여 출력하자.
    최종적인 구현에 앞서 ExtendMemForString 함수를 구현한다.
    입력된 문자열크기를 담기에 모자른다면 EXT_SIZE 만큼 확장된 공간을 다시 할당하며 문자열을 받는다.

    함   수 : int ExtendMemForString(char **pStr, int strLen);
    기   능 : 문자열 저장을 위해 메모리 공간을 확장
    입   력 : 
    반   환 : 확장된 길이, 오류시 -1 반환
    특이사항 : 반드시 반환된ㄴ 포인터를 대상으로 free 함수를 호출해야 함

    [실행의 예 (EXT_SIZE가 5일 경우)]
    문자열 입력 : Best
    입력된 문자열 : Best, 문자열의 길이 : 5
    문자열 입력 :  Guy!
    확장된 문자열의 길이 : 10
    입력된 문자열 : Best Guy!, 문자열의 길이 : 10
    문자열 입력 : ^D
*/

/*
    ! ExtendMemForString 함수에서 왜 문자 단위의 복사가 이뤄 졌을까?
    ! strcpy 함수가 떠올랐다.. 하지만 strcpy를 사용하면 에러가 나온다.
    ! 여기서 확장하려는 배열은 char형 배열이지 문자열이 아니다.
    ! 문자열이 아니라니?????
    ! 문자열은 마지막에 널 문자까지 저장되어야 인정받는다.
    ! strcpy는 문자열이 저장되어 있을때 가능하다.. 명심하자.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXT_SIZE 5

int ExtendMemForString(char **pStr, int strLen);

int ExtendMemForString(char **pStr, int strLen)
{
    char *newStr = (char *)malloc(sizeof(char) * (strLen + EXT_SIZE));

    if (newStr == NULL)
        return -1;

    for (int i = 0; i < strLen; i++)
        newStr[i] = (*pStr)[i];

    free(*pStr);
    *pStr = newStr;
    return strLen + EXT_SIZE;
}

int main(void)
{
    int strlen = 5;
    char *str = (char *)malloc(sizeof(char) * strlen);

    strcpy(str, "Best");
    puts(str);

    strlen = ExtendMemForString(&str, strlen);
    printf("확장된 문자열의 길이 : %d\n", strlen);
    strcat(str, " Guy!");
    puts(str);

    return 0;
}