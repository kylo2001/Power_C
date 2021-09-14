/*
    [문제 17]
    총 5개의 단어를 입력 받아서 배열에 저장을 하자(2차원 배열이 필요하다)
    그 다음, 길이가 짧은 단어의 순으로 정렬하자. 그리고 이렇게 정렬이 완료된 문자열들을
    저장된 순서대로 출력하자.
    단!! 길이가 같을 경우에는 먼저 입력된 문자열이 먼저 출력되어야 한다.

    1. 단어의 길이는 20을 넘지 않는다고 가정한다.
    2. 버블정렬을 이용한다.
    
    [실행의 예]
    문자열 입력 1 : Cool
    문자열 입력 2 : And
    문자열 입력 3 : Boy
    문자열 입력 4 : Eight
    문자열 입력 5 : Down
    And
    Boy
    Cool
    Down
    Eight
*/

#include <stdio.h>
#include <string.h>
#define WORD_SIZE 5
#define WORD_LEN 20

int main(void)
{
    char words[WORD_SIZE][WORD_LEN];

    for (int i = 0; i < WORD_SIZE; i++)
    {
        printf("문자열 입력 %d : ", i + 1);
        scanf("%s", words[i]);
    }

    for (int i = WORD_SIZE - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            char temp[WORD_LEN];

            if (strlen(words[j]) > strlen(words[j + 1]))
            {
                strcpy(temp, words[j + 1]);
                strcpy(words[j + 1], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    for (int i = 0; i < WORD_SIZE; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}