/*
    [문제]
    원의 반지름 정보를 입력 받아서, 원의 넓이를 계산해서 출력하는 프로그램을 작성하여라.
    단, 원의 넓이를 계산하는 공식은 다음과 같다. [원의 넓이 = 반지름 * 반지름 * 3.14]

    [실행의 예]
    반지름 입력 : 2.5
    원의 넓이 : 19.625000
*/

#include <stdio.h>
#define PI 3.14
#define AREA_OF_CIRCLE(radius) ((radius) * (radius)*PI)

int main(void)
{
    double radius;

    fputs("반지름 입력 : ", stdout);
    scanf("%lf", &radius);
    printf("원의 넓이 : %lf\n", AREA_OF_CIRCLE(radius));

    return 0;
}