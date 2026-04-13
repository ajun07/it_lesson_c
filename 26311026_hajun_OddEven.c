#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetRandom(int minVal, int maxVal);
int Wincount = 0;
int Losscount = 0;
char input;
int playerChoice;

int main(void)
{
    srand((unsigned int)time(NULL));
   
    
    printf("홀짝 게임을 시작합니다(5전 3승) (Q 입력 시 종료) =============\n");

    Start();

    return 0;
}

int GetRandom(int minVal, int maxVal)
{
    return minVal + rand() % (maxVal - minVal + 1);
}

int Start(void) {
    while (1) {
        printf("\n홀(O), 짝(E) 중 하나를 선택하세요 (종료: Q): ");

        scanf_s(" %c", &input, 1);


        char choice = input;

        if (choice == 'q' || choice == 'Q')
        {
            printf("게임을 종료합니다. 이용해 주셔서 감사합니다!\n");
            break;
        }

        if (choice == 'o' || choice == 'O')
        {
            playerChoice = 1;
            printf(">> [홀]을 선택하셨습니다.\n");
        }
        else if (choice == 'e' || choice == 'E')
        {
            playerChoice = 0;
            printf(">> [짝]을 선택하셨습니다.\n");
        }
        else {
            printf("잘못된 입력입니다. O, E, Q 중 하나를 입력하세요.\n");
            continue;
        }

        int compValue = GetRandom(10, 90);
        int isOdd = compValue % 2;

        if (isOdd == playerChoice) {
            printf(" 승리 (컴퓨터의 숫자: %d)\n", compValue); ++Wincount;
        }
        else {
            printf(" 패배 (컴퓨터의 숫자: %d)\n", compValue); ++Losscount;
        }
         printf("사용자 :%d 컴퓨터 :%d\n", Wincount, Losscount);
        if (Wincount == 3) {
            printf("\n축하합니다! 당신이 이겼습니다!\n");
            break;
        }
        else if (Losscount == 3) {
            printf("\n아쉽지만, 컴퓨터가 이겼습니다. 다음에 다시 도전하세요!\n");
            break;
		}
    }
}