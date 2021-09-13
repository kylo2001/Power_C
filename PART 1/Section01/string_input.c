/*
    [문제 2]
    이름을 입력 받아서 출력하는 프로그램을 작성하자. 단, 다음과 같은 형태의 입력을 모두 혀요해야 한다.
    * "홍빛나"
    * "홍 빛 나"
    * "빛나는 홍"
    
    [실행의 예]
    문자열 입력 : 빛나는 횽!
    입력된 문자열 : 빛나는 홍!
*/

#include <stdio.h>
#define STR_LEN 50

int main(void)
{
    char string[STR_LEN];

    fputs("문자열 입력 : ", stdout);
    gets(string);

    fputs("입력된 문자열 : ", stdout);
    puts(string);
    return 0;
}

/*
    ! 8행과 11행에서 포맷을 지정하지 않을 거라면 printf보다 puts가 더 효율적이다.
    ! 또한, puts는 문장 끝에 개행 문자를 삽입한다.
    ! gets 함수를 사용해야 공백을 포함하는 하나의 문장을 입력 받을 수 있다.
*/
