/*
    [문제 25-1]
    컴파일 에러가 나는 예제
    원인을 찾아보자.
    
    ! 이 예제가 컴파일 오류가 발생하지 않을수도 있다.
    ! C99에서 Variable Length Array(배열 선언에 변수를 허용하는 새로운 표준)를 지원하기 때문이다.
*/

#include <stdio.h>

void SortArr(int *arr, int num);
void ReadAndSortPrint(int number);

void SortArr(int *arr, int num)
{
    int i, j, temp;

    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; i < (num - i) - 1; j++)
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

void ReadAndSortPrint(int number)
{
    int arr[number];
    int i;

    for (i = 0; i < number; i++)
    {
        printf("%d 번째 입력 : ", i + 1);
        scanf("%d", &arr[i]);
    }

    sortArr(arr, number);

    puts("입력된 숫자의 정렬된 출력");
    for (i = 0; i < number; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int main(void)
{
    int num;
    fputs("입력할 정수의 개수 : ", stdout);
    scanf("%d", &num);

    ReadAndSortPrint(num);
    return 0;
}