/*
    [문제 27]
    개인이 보유하고 있는 도서목록을 저장 및 출력할 수 있는 프로그램을 작성하자. 
    도서목록을 저장할 때에는 도서 제목, 출판사 이름 그리고 가격 정보를 저장할 수 있어야 한다.

    1. 총 3개의 도서 목록을 입력 받는다. 
        입력 받은 데이터를 그대로 출력하고 종료하는 형태로 프로그램을 구현하자.
    2. 절대로 구조체를 사용하지 말자! 
    3. 도서 목록과 출판사 이름은 그 길이를 최대 50으로 제한하자. 가격 정보는 정수의 형태로 저장한다. 
    4. malloc과 free 함수를 이용한 동적 할당을 하지 않기로 하자. 
        저장할 수 있는 목록 개수(3개)를 지정하였으니, 굳이 동적 할당을 할 이유도 없다.

    아아아아 쓰고 시팓 구조체!!!!!를 느끼는 것에 집중하자.

    [실행의 예]
    ********** 도서 정보 입력 **********
    1번째 도서 정보 입력.
    도서 제목 : 아침형 인간
    출판사 명 : 아침일찍 출판사
    도서 가격 : 15000
    1번째 입력 완료.....................

    ********** 도서 정보 입력 **********
    2번째 도서 정보 입력.
    도서 제목 : 프로그래밍 만세
    출판사 명 : 오렌지미디어
    도서 가격 : 10000
    2번째 입력 완료.....................

    ********** 도서 정보 입력 **********
    3번째 도서 정보 입력.
    도서 제목 : 오렌지요리법
    출판사 명 : 오렌지미디어
    도서 가격 : 20000
    3번째 입력 완료.....................

    ********** 도서 정보 출력 **********
    1번째 도서 정보 출력.
    도서 제목 : 아침형 인간
    출판사 명 : 아침일찍 출판사
    도서 가격 : 15000

    2번째 도서 정보 출력.
    도서 제목 : 프로그래밍 만세
    출판사 명 : 오렌지미디어
    도서 가격 : 10000

    3번째 도서 정보 출력.
    도서 제목 : 오렌지요리법
    출판사 명 : 오렌지미디어
    도서 가격 : 20000
*/

#include <stdio.h>
#define BOOK_NUM 3
#define STR_LEN 50

int main(void)
{
    char title[3][STR_LEN];
    char publisher[3][STR_LEN];
    int price[3];

    for (int i = 0; i < BOOK_NUM; i++)
    {
        fputs("********** 도서 정보 입력 **********\n", stdout);
        printf("%d번째 도서 정보 입력.\n", i + 1);

        fputs("도서 제목 : ", stdout);
        gets(title[i]);

        fputs("출판사 명 : ", stdout);
        gets(publisher[i]);

        fputs("도서 가격 : ", stdout);
        scanf("%d", &price[i]);
        fflush(stdin);
        printf("%d번째 입력 완료.....................\n", i + 1);
    }

    fputs("********** 도서 정보 출력 **********", stdout);

    for (int i = 0; i < BOOK_NUM; i++)
    {
        printf("%d번째 도서 정보 출력.\n", i + 1);
        printf("도서 제목 : %s\n", title[i]);
        printf("출판사 명 : %s\n", publisher[i]);
        printf("도서 가격 : %d\n\n", price[i]);
    }

    return 0;
}