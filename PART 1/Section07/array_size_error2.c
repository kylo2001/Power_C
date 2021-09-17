/*
    [문제 25-2]
    [문제 25-1]에서 오류가 발생하는 이유를 수정해보자. 구현 의도는 그대로 유지해야한다.
    
    1. 아주 넉넉한 배열을 선언하는 방식으로 문제를 해결하지 않는다.
    2. 배열의 길이는 사용자가 입력하고자 하는 정수의 개수로 결정되어야 한다.
    3. 문제 해결을 위한 수정 번위를 ReadAndSortPrint 함수로 제한한다.
*/

#include <stdio.h>
#include <stdlib.h>
void SortArr(int *arr, int num);
void ReadAndSortPrint(int number);

void SortArr(int *arr, int num)
{
    int i, j, temp;

    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < (num - i) - 1; j++)
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

void ReadAndSortPrint(int number)
{
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * number);

    for (i = 0; i < number; i++)
    {
        printf("%d 번째 입력 : ", i + 1);
        scanf("%d", &arr[i]);
    }

    SortArr(arr, number);

    puts("입력된 숫자의 정렬된 출력");
    for (i = 0; i < number; i++)
        printf("%d", arr[i]);
    printf("\n");

    free(arr);
}

int main(void)
{
    int num;
    fputs("입력할 정수의 개수 : ", stdout);
    scanf("%d", &num);

    ReadAndSortPrint(num);
    return 0;
}