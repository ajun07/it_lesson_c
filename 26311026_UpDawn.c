#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int user, computer;
int GameSet(void);
int Win = 0, Lose = 0;
int Game(void);
int count = 0;

int main() 
{
	srand((unsigned int)time(NULL));
    computer = rand() % 81 + 10;
	GameSet();

    if (Win == 3)
    {
        printf("\n축하합니다! 당신이 이겼습니다!\n");
        return 0;
    }
    else if (Lose == 3)
    {
        printf("\n아쉽지만, 컴퓨터가 이겼습니다. 다음에 다시 도전하세요!\n");
        return 0;
    }
}

int GameSet(void)
{
    while (Win < 3 && Lose < 3)
    {
        printf("\nUp Dawn 게임 숫자를 입력하세요 (10~90)(5판 3선승): ");
        scanf_s("%d", &user);
        if (user < 10 || user > 90)
        {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            continue;
        }
        int result = Game();
        if (result == 1) {
            ++Win;
            printf("현재 스코어 - 사용자: %d, 컴퓨터: %d\n", Win, Lose);
			count = 0;
            computer = rand() % 81 + 10;
        }
        else if (result == -1) {
            ++Lose;
            printf("현재 스코어 - 사용자: %d, 컴퓨터: %d\n", Win, Lose);
            count = 0;
            computer = rand() % 81 + 10;
        }
        
    }
    return 0;
}
    int Game(void)
    {
        if (user == computer)
        {
            printf("승리\n");
            return 1;
        }
        else if (count >= 5)
        {
            printf("패배\n");
            return -1;
        }
        else if (user < computer)
        {
            printf("Up\n");
            ++count;
            return 0;
        }
        else
        {
            printf("Down\n");
            ++count;
            return 0;
        }

    }


