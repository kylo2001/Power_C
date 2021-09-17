/*
    [문제 28]
    [문제 27-1]를 구조체를 활용해서 구현해보자.

    다음 구조체를 사용하자.

    typedef struct __bookInfo
    {
        char bookTitle[STR_LEN];
        char bookPub[STR_LEN];
        int bookPrice;
    } bookInfo;

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
#define BOOK_INFO_NUM 3
#define STR_LEN 50

typedef struct __bookInfo
{
    char bookTitle[STR_LEN];
    char bookPub[STR_LEN];
    int bookPrice;
} bookInfo;

bookInfo bookInfoList[BOOK_INFO_NUM];

int main(void)
{

    for (int i = 0; i < BOOK_INFO_NUM; i++)
    {
        fputs("********** 도서 정보 입력 **********\n", stdout);
        printf("%d번째 도서 정보 입력.\n", i + 1);

        fputs("도서 제목 : ", stdout);
        gets(bookInfoList[i].bookTitle);

        fputs("출판사 명 : ", stdout);
        gets(bookInfoList[i].bookPub);

        fputs("도서 가격 : ", stdout);
        scanf("%d", &bookInfoList[i].bookPrice);
        fflush(stdin);
        printf("%d번째 입력 완료.....................\n", i + 1);
    }

    fputs("********** 도서 정보 출력 **********", stdout);

    for (int i = 0; i < BOOK_INFO_NUM; i++)
    {
        printf("%d번째 도서 정보 출력.\n", i + 1);
        printf("도서 제목 : %s\n", bookInfoList[i].bookTitle);
        printf("출판사 명 : %s\n", bookInfoList[i].bookPub);
        printf("도서 가격 : %d\n\n", bookInfoList[i].bookPrice);
    }

    return 0;
}