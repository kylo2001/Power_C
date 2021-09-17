/*
    [문제 26-3]
    길이가 정해지지 않은 문자열을 5개를 입력받고 오름차순으로 정렬하여 출력하자.
    최종적인 구현에 앞서 ExtendMemForString 함수를 구현한다.
    입력된 문자열크기를 담기에 모자른다면 EXT_SIZE 만큼 확장된 공간을 다시 할당하며 문자열을 받는다.

    [실행의 예 (EXT_SIZE가 5일 경우)]
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_NUM 5
#define EXT_SIZE 5

char *ReadString(void);
int ExtendMemForString(char **pStr, int strLen);
void SortString(char *strArr[STR_NUM]);

char *ReadString(void)
{
    int maxStringLen = 10;
    char *str = (char *)malloc(sizeof(char) * maxStringLen);
    int idx = 0;

    while (1)
    {
        if (idx >= maxStringLen)
            maxStringLen = ExtendMemForString(&str, maxStringLen);

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

void SortString(char *strArr[STR_NUM])
{
    int i, j;
    char *tempStr;

    for (i = 0; i < STR_NUM - 1; i++)
    {
        for (j = 0; j < (STR_NUM - i) - 1; j++)
        {
            if (strlen(strArr[j]) > strlen(strArr[j + 1]))
            {
                tempStr = strArr[j];
                strArr[j] = strArr[j + 1];
                strArr[j + 1] = tempStr;
            }
        }
    }
}

int main(void)
{
    char *strArr[STR_NUM];
    int i;

    for (i = 0; i < STR_NUM; i++)
    {
        printf("문자열 입력 %d : ", i + 1);
        strArr[i] = ReadString();
    }

    SortString(strArr);

    for (i = 0; i < STR_NUM; i++)
        puts(strArr[i]);

    for (i = 0; i < STR_NUM; i++)
        free(strArr[i]);

    return 0;
}