/*
    [문제 23]
    * 문자열의 길이를 반환하는 함수 strLen
    * 문자열을 복사하는 함수 strCpy
    * 문자열의 뒤에 문자열을 덧붙이는 함수 strCat
    * 두 개의 문자열을 비교하는 함수 strCmp
    
    1. 전달인자의 순서 및 기능이 ANSI 표준함수와 완전히 동일하게 정의하자.

    * int strLen(char *str);
    * int strCpy(char *dest, char *source);
    * int strCat(char *dest, char *source);
    * int strCmp(char *str1, char *str2);
*/

#include <stdio.h>
#define STR_MAX 100

int strLen(char *str);
int strCpy(char *dest, char *source);
int strCat(char *dest, char *source);
int strCmp(char *str1, char *str2);

int strLen(char *str)
{
    int length = 0;
    while (1)
    {
        if (str[length] != '\0')
            length++;
        else
            break;
    }

    return length;
}

int strCpy(char *dest, char *source)
{
    int i = 0;
    while (1)
    {
        if (source[i] != '\0')
        {
            dest[i] = source[i];
            i++;
        }
        else
        {
            dest[i] = '\0';
            break;
        }
    }
    return i;
}

int strCat(char *dest, char *source)
{
    int i = 0;
    while (1)
    {
        if (dest[i] != '\0')
            i++;
        else
            break;
    }

    int j = i;

    while (1)
    {
        if (source[i - j] != '\0')
        {
            dest[i] = source[i - j];
            i++;
        }
        else
            break;
    }

    dest[i] = '\0';

    return i;
}

int strCmp(char *str1, char *str2)
{
    int i = 0;

    while ((str1[i] != '\0') && (str2[i] != '\0'))
    {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else if (str1[i] == '\0' && str2[i] != '\0')
        return 1;
    else
        return -1;
}

int main(void)
{
    char str1[STR_MAX] = "Good Morning?";
    char str2[STR_MAX] = "HaHaHa!";
    char buffString[STR_MAX];

    //! strLen Test
    printf("length of \"%s\" : %d \n", str1, strLen(str1));
    printf("length of \"%s\" : %d \n", str2, strLen(str2));

    //! strCpy Test
    strCpy(buffString, str1);
    printf("copy string : \"%s\" \n", buffString);

    //! strCat Test
    strCat(buffString, str2);
    printf("concat string : \"%s\" \n", buffString);

    //! strCmp Test
    printf("cmp str1, str1 : %d \n", strCmp(str1, str1));
    printf("cmp str2, str2 : %d \n", strCmp(str2, str2));
    printf("cmp str1, str2 : %d \n", strCmp(str1, str2));
    printf("cmp str2, str1 : %d \n", strCmp(str2, str1));

    return 0;
}