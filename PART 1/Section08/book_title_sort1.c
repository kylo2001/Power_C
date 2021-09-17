/*
    [문제 29]
    문제 28에서 구현한 프로그램의 기능을 확장하자. 문제 28에서 구현한 프로그램은 도서정보를
    입력할 때 입력 순서대로 저장 및 출력되었다. 그러나 이번에는 저장할 때 도서 이름의 순으로(사전 편찬의 순서대로)
    정렬하여 저장하고, 정렬된 상태로 출력이 이뤄지도록 프로그램의 기능을 확장하자.

    1. 데이터를 모두 저장하고 나서 정렬하는 것이 아니라. 저장할 때 정렬되어 저장하는 방식으로 구현해야 한다. 
    2. 입력에 관련된 별도의 함수를 만들어서 활용하자. 이 함수에서 요구사항 1. 기능을 가져야한다.
        단, 키보드로부터 입력 받는 역할을 담당하지 않는다.
    3. 매크로 값 BOOK_INFO_NUM가 변경됨에 따라서 작동해야한다.
    4. 리스트가 아닌 배열로 구현해보자.
    
    함  수 : int InsertList(bookInfo info);
    기  능 : bookInfo 구조체 타입의 변수를 전달받아 정보를 입력 받고 정렬하여 저장한다.
    반  환 : 현재 입력된 책이 몇번째인지 반환한다. 단 오류 발생시 -1을 반환한다.

    [실행의 예]
    ********** 도서 정보 입력 **********
    1번째 도서 정보 입력.
    도서 제목 : aaa
    출판사 명 : 아침일찍 출판사
    도서 가격 : 15000
    1번째 입력 완료.....................

    2번째 도서 정보 입력.
    도서 제목 : ccc
    출판사 명 : 오렌지미디어
    도서 가격 : 10000
    2번째 입력 완료.....................

    3번째 도서 정보 입력.
    도서 제목 : bbb
    출판사 명 : 오렌지미디어
    도서 가격 : 20000
    3번째 입력 완료.....................

    ********** 도서 정보 출력 **********
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
*/

#include <stdio.h>
#include <string.h>
#define BOOK_INFO_NUM 3
#define STR_LEN 50

typedef struct __bookInfo
{
    char bookTitle[STR_LEN];
    char bookPub[STR_LEN];
    int bookPrice;
} bookInfo;

int numOfData = 0;
bookInfo bookInfoList[BOOK_INFO_NUM];

int InsertList(bookInfo *info);

int InsertList(bookInfo *info)
{
    int i;
    int inputIndex = numOfData;
    if (numOfData >= BOOK_INFO_NUM)
        return -1;

    //! 위치 찾기
    for (i = 0; i < numOfData; i++)
    {
        if (strcmp(bookInfoList[i].bookTitle, info->bookTitle) > 0)
        {
            inputIndex = i;
            break;
        }
    }

    //! 자리 만들기
    for (i = numOfData; i > inputIndex; i--)
        bookInfoList[i] = bookInfoList[i - 1];

    bookInfoList[inputIndex] = (*info);

    //! 반환
    return ++numOfData;
}

bookInfo bookInfoList[BOOK_INFO_NUM];

int main(void)
{
    int i, num;
    bookInfo book;

    fputs("********** 도서 정보 입력 **********\n", stdout);

    for (int i = 0; i < BOOK_INFO_NUM; i++)
    {
        printf("%d번째 도서 정보 입력.\n", i + 1);

        fputs("도서 제목 : ", stdout);
        gets(book.bookTitle);

        fputs("출판사 명 : ", stdout);
        gets(book.bookPub);

        fputs("도서 가격 : ", stdout);
        scanf("%d", &book.bookPrice);
        fflush(stdin);

        num = InsertList(&book);

        if (num == -1)
            printf("입력에 실패하였습니다.\n");
        else
            printf("%d번째 입력 완료.....................\n", num);
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