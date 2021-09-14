/*
    [문제 18]
    네 개의 문자열(단어 문자열)을 입력 받아서 사전편찬 순서대로 정렬된 하나의 문자열을
    구성하자. 그리고 이렇게 정렬된 문자열을 출력하는 프로그램을 작성하자.

    1. 길이가 20인 char형 1차원 배열 4개로 총 4개의 단어 문자열을 입력받고, 
        길이가 80인 char형 1차원 배열 1개로 네 개의 문자열을 하나로 묻는다.
        2차원 배열은 사용하지 않는다.
    2. 단어와 단어 사이에 공백 문자를 포함하도록 하자.

    
    [실행의 예]
    문자열 입력 1 : CCC
    문자열 입력 2 : AAA
    문자열 입력 3 : BBB
    문자열 입력 4 : DDD
    정렬된 문자열 : AAA BBB CCC DDD
*/

#include <stdio.h>
#include <string.h>
#define STR_LEN 20
#define STR_NUM 4
#define TOTAL_STR_LEN (STR_LEN * STR_NUM)

int main(void)
{
    char word1[STR_LEN], word2[STR_LEN], word3[STR_LEN], word4[STR_LEN], dictionary[TOTAL_STR_LEN] = {0};
    char *call_numbers[STR_NUM] = {word1, word2, word3, word4};

    for (int i = 0; i < STR_NUM; i++)
    {
        printf("문자열 입력 %d : ", i + 1);
        scanf("%s", call_numbers[i]);
    }

    for (int i = STR_NUM - 1; i >= 0; i--)
    {
        char *temp_word;

        for (int j = 0; j < i; j++)
        {
            if (strcmp(call_numbers[j], call_numbers[j + 1]) > 0)
            {
                temp_word = call_numbers[j + 1];
                call_numbers[j + 1] = call_numbers[j];
                call_numbers[j] = temp_word;
            }
        }
    }

    for (int i = 0; i < STR_NUM; i++)
    {
        strcat(dictionary, call_numbers[i]);
        // strcat(dictionary, " ");
        dictionary[strlen(dictionary)] = ' ';
    }

    printf("%s\n", dictionary);
    return 0;
}