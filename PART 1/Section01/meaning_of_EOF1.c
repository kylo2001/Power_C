/*
    [문제 1]
    키보드로부터 EOF가 입력될 때까지 문자를 입력 받아서, 입력된 문자의 총 개수를 출력하는 
    프로그램을 작성하자. 그저 입력된 문자의 개수만 출력하면 된다. 입력 받은 문자들
    을 저장해 둘 필요가 없다는 뜻이다.
    
    [문제 1의 실행의 예]

    Data input (Ctrl+Z to exit) : a
    Data input (Ctrl+Z to exit) : b
    Data input (Ctrl+Z to exit) : c
    Data input (Ctrl+Z to exit) : d
    Data input (Ctrl+Z to exit) : e
    Data input (Ctrl+Z to exit) : ^D
    입력된 문자의 수 : 5
*/

#include <stdio.h>

int main(void)
{
    char input;
    int count = 0;

    while (1)
    {
        fputs("Data input (Ctrl+Z to exit) : ", stdout);
        input = getchar();

        if (input == EOF)
        {
            printf("\n입력된 문자의 수 : %d\n", count);
            break;
        }
        else
        {
            fflush(stdin);
            count++;
        }
    }

    return 0;
}

/*
    ! 모든 콘솔 입출력 함수는 파일 입출력 함수를 조금 고쳐서(확장해서) 만든 거다.
    ! 파일 입출력 함수는 파일의 끝을 만났을 때 EOF을 반환하는데,
    ! 콘솔 입출력 함수는 언제 EOF를 반환할까????

    ! 윈도우즈 -> Ctrl+Z // 유닉스 -> Ctrl+D

    ! 키보드 입력 문자열 -> 키보드 입력 버퍼 -> 키보드 입력 버퍼에 Enter키 입력 시 
    !    -> 프로세스 입력 버퍼 -> getchar 함수 호출에 의한 반환

    ! 입력과정을 보면 두가지 버퍼가 존재한다. 첫 번째는 키보드 입력 버퍼, 두 번째 프로세스 입력 버퍼
    ! 키보드로 쭉 입력하며 Enterㅣ를 입력하기 전에는 키보드 입력 버퍼에 저장된다. 
    ! Enter키가 입력된다. 프로그램 안으로 들어가 프로세스 입력 버퍼에 저장되는데
    ! 이때부터 콘솔 입출력 함수들은 데이터를 가져갈 수 있게 된다.
*/
