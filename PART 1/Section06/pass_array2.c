/*
    [문제 21-2]
    2차원 배열을 인자로 전달받아서 배열에 저장된 모든 요소의 합을 계산하여 그 결과를 반환하는 함수를 정의하고 
    이를 테스트하는 main 함수를 만들자, 테스트에 사용될 배열은 다음과 같다.

    int arr3[2][2] = {1, 3, 5, 7};
    int arr4[2][3] = {1, 2, 3, 4, 5, 6};
    
    1. 21-1과 다르게 필요한 만큼 함수를 만들어도 된다. 
       하나의 함수가 배열 arr3와 arr4의 모든 요소의 합을 각각 계산할 수 있다면 나의 함수만 정의해라.
       그러나 이것이 이치에 맞지 않는다고 판단되면 arr3을 위한 함수와 arr4를 위한 함수를 각각 정의해도 된다.

    [실행의 예]
    1, 3, 5, 7의 합 : 16
    1, 2, 3, 4, 5, 6의 합 : 21
*/

#include <stdio.h>

int sum1(int arr[][2], int col)
{
    int sum = 0;

    for (int i = 0; i < col; i++)
        for (int j = 0; j < 2; j++)
            sum += arr[i][j];

    return sum;
}

int sum2(int (*arr)[3], int col)
{
    int sum = 0;

    for (int i = 0; i < col; i++)
        for (int j = 0; j < 3; j++)
            sum += arr[i][j];

    return sum;
}

int main(void)
{
    int arr3[2][2] = {1, 3, 5, 7};
    int arr4[2][3] = {1, 2, 3, 4, 5, 6};

    printf("1, 3, 5, 7의 합 = %d\n", sum1(arr3, 2));
    printf("1, 2, 3, 4, 5, 6의 합 = %d\n", sum2(arr4, 2));

    return 0;
}