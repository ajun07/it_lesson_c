#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int user, computer;
int Game(void);
int Win = 0, Lose = 0;
int GameSet(void);

int main() {

    srand((unsigned int)time(NULL));
    printf("==========가위바위보(5판3선승)=============\n");

    GameSet();

    if (Win == 3) {
        printf("\n축하합니다! 당신이 이겼습니다!\n");
    }
    else if (Lose == 3) {
        printf("\n아쉽지만, 컴퓨터가 이겼습니다. 다음에 다시 도전하세요!\n");
    }

    return 0;
}

int Game(void) 
{
    if (user == computer) 
    {
        printf("비겼습니다.\n");
        return 0;
    }
    else if ((user == 3 && computer == 1) || (user == 1 && computer == 2) || (user == 2 && computer == 3))
    {
        printf("사용자가 이겼습니다.\n");
        return 1;
    }
    else
    {
        printf("컴퓨터가 이겼습니다.\n");
        return -1;
    }
}

int GameSet(void) 
{
    while (Win < 3 && Lose < 3) 
    {
        printf("\n가위(1), 바위(2), 보(3) 중에서 선택하세요: ");
        scanf("%d", &user);
        if (user < 1 || user > 3) 
        {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            continue;
        }
        computer = rand() % 3 + 1;
        int result = Game();
        if (result == 1) {
            Win++;
        }
        else if (result == -1) {
            Lose++;
        }
        printf("현재 스코어 - 사용자: %d, 컴퓨터: %d\n", Win, Lose);
    }
    return 0;
}