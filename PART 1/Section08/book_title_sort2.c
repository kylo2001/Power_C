/*
    [문제 30]
    문제 29에서 구현한 프로그램의 기능을 확장하자. 문제 29에는 도서 명을 기준으로 출력하였다. 
    그러나 이번에는 다영한 기준으로 도서 정보를 저열하여 출력할 수 있도록 프로그램의 기능을 확장하자.
    
    1. 도서 이름, 출판사 이름, 낮은 가격 순으로 출력할 수 있도록 프로그램을 확장한다.
    2. 사용자가 종료를 원할 때 종료할 수 있는 방법도 마련한다.
    3. 각각의 정렬 기능을 각각의 함수로 정의하자.
    4. 확장이라고 한 만큼 기존에 구현되어 있는 코드를 가지고 많은 변화 없이 구현해보자.

    ! 소프트웨어 개발에 있어서 확장은 아주 빈번히 일어난다.

    [실행의 예]
    ********** 도서 정보 입력 **********
    1번째 도서 정보 입력.
    도서 제목 : Best Programming
    출판사 명 : 아침일찍 출판사
    도서 가격 : 15000
    1번째 입력 완료.....................

    2번째 도서 정보 입력.
    도서 제목 : Assa Design
    출판사 명 : 오렌지미디어
    도서 가격 : 10000
    2번째 입력 완료.....................

    3번째 도서 정보 입력.
    도서 제목 : C++ Programming
    출판사 명 : 오렌지미디어
    도서 가격 : 20000
    3번째 입력 완료.....................

    *************** 도서 정보 출력 ***************
    1. 도서 제목 순, 2. 출판사 순, 3. 가격 순, 4. 종료
    그대의 선택? 2
    1번째 도서 정보 출력.
    도서 제목 : aaa
    출판사 명 : 아침일찍 출판사
    도서 가격 : 15000

    2번째 도서 정보 출력.
    도서 제목 : bbb
    출판사 명 : 오렌지미디어
    도서 가격 : 20000

    3번째 도서 정보 출력.
    도서 제목 : ccc
    출판사 명 : 오렌지미디어
    도서 가격 : 10000

     *************** 도서 정보 출력 ***************
    1. 도서 제목 순, 2. 출판사 순, 3. 가격 순, 4. 종료
    그대의 선택?
*/

#include <stdio.h>
#include <string.h>
#define STR_LEN 50
#define BOOK_INFO_NUM 3

typedef struct bookInfo
{
    char bookTitle[STR_LEN];
    char bookPub[STR_LEN];
    int bookPrice;
} bookInfo;

enum
{
    SORT_TITLE = 1,
    SORT_PUB,
    SORT_PRICE,
    EXIT
};

int numOfData = 0;

bookInfo bookInfoList[BOOK_INFO_NUM];
bookInfo *bookSortList[BOOK_INFO_NUM];

int InsertList(bookInfo *bookPtr);

void InitSortList(void);
void PrintSortList(void);

void SortByTitle(void);
void SortByPubName(void);
void SortByPrice(void);

int main(void)
{
    int i, num;
    int choice;
    bookInfo book;

    puts("********** 도서 정보 입력 **********");
    for (i = 0; i < BOOK_INFO_NUM; i++)
    {
        printf("%d번째 도서 정보 입력. \n", (i + 1));

        fputs("도서 제목: ", stdout);
        gets(book.bookTitle);

        fputs("출판사 명: ", stdout);
        gets(book.bookPub);

        fputs("도서 가격: ", stdout);
        scanf("%d", &(book.bookPrice));
        fflush(stdin);

        num = InsertList(&book);
        if (num == -1)
            printf("입력에 실패하였습니다. \n");
        else
            printf("%d번재 입력 완료.......\n\n", num);
    }

    InitSortList();
    while (1)
    {
        puts("*************** 도서 정보 출력 ***************");
        puts("정렬방식 선택...... ");
        puts("1. 도서 제목 순, 2. 출판사 순, 3. 가격 순, 4. 종료");
        fputs("그대의 선택? ", stdout);
        scanf("%d", &choice);
        if (choice == EXIT)
            break;

        switch (choice)
        {
        case SORT_TITLE:
            SortByTitle();
            PrintSortList();
            break;

        case SORT_PUB:
            SortByPubName();
            PrintSortList();
            break;

        case SORT_PRICE:
            SortByPrice();
            PrintSortList();
            break;
        }
    }

    return 0;
}

int InsertList(bookInfo *bookPtr)
{
    int idx;
    int inputIdx = numOfData;

    if (numOfData >= BOOK_INFO_NUM)
        return -1;

    for (idx = 0; idx < numOfData; idx++)
    {
        if (strcmp(bookInfoList[idx].bookTitle, bookPtr->bookTitle) > 0)
        {
            inputIdx = idx;
            break;
        }
    }

    for (idx = numOfData; idx > inputIdx; idx--)
        bookInfoList[idx] = bookInfoList[idx - 1];

    bookInfoList[inputIdx] = (*bookPtr);

    return ++numOfData;
}

// 구조체 포인터 배열 bookSortList에 각 구조체를 연결한다.
void InitSortList(void)
{
    int i;
    for (i = 0; i < BOOK_INFO_NUM; i++)
        bookSortList[i] = &bookInfoList[i];
}

void PrintSortList(void)
{
    int i;
    for (i = 0; i < BOOK_INFO_NUM; i++)
    {
        printf("%d번째 도서 정보 출력. \n", (i + 1));
        printf("도서 제목: %s \n", bookSortList[i]->bookTitle);
        printf("출판사 명: %s \n", bookSortList[i]->bookPub);
        printf("도서 가격: %d \n\n", bookSortList[i]->bookPrice);
    }
}

// 입력시 기본으로 도서 이름으로 정렬하므로 bookInfoList는 도서 이름 순으로 정렬되어 있다.
void SortByTitle(void)
{
    InitSortList();
}

void SortByPubName(void)
{
    int i, j;
    bookInfo *temp;

    for (i = 0; i < BOOK_INFO_NUM - 1; i++)
    {
        for (j = 0; j < (BOOK_INFO_NUM - i) - 1; j++)
        {
            if (strcmp(bookSortList[j]->bookPub, bookSortList[j + 1]->bookPub) > 0)
            {
                temp = bookSortList[j];
                bookSortList[j] = bookSortList[j + 1];
                bookSortList[j + 1] = temp;
            }
        }
    }
}

void SortByPrice(void)
{
    int i, j;
    bookInfo *temp;

    for (i = 0; i < BOOK_INFO_NUM - 1; i++)
    {
        for (j = 0; j < (BOOK_INFO_NUM - i) - 1; j++)
        {
            if (bookSortList[j]->bookPrice > bookSortList[j + 1]->bookPrice)
            {
                temp = bookSortList[j];
                bookSortList[j] = bookSortList[j + 1];
                bookSortList[j + 1] = temp;
            }
        }
    }
}