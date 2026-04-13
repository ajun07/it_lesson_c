#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNING
int Gamecheat;
int Strike = 0;
int Ball = 0;
int Win = 0;
int Lose = 0;
int UserNum1[1] = { 0 };
int UserNum2[1] = { 0 };
int UserNum3[1] = { 0 };
int ComputerNum1[1] = { 0 };
int ComputerNum2[1] = { 0 };
int ComputerNum3[1] = { 0 };
int GameSet(void);
int Randomize(int, int);
int Game(void);
int RandomNumder(void);
int StrikeBall(void);
int DoCheat(void);
int count = 0;

int main()
{
    RandomNumder();
	srand((unsigned int)time(NULL));
    printf("==========숫자 야구(5판3선승)=============\n");
    DoCheat();
    GameSet();

    if (Win == 3) {
        printf("\n축하합니다! 당신이 이겼습니다!\n");
    }
    else if (Lose == 3) {
        printf("\n아쉽지만, 컴퓨터가 이겼습니다. 다음에 다시 도전하세요!\n");
    }

    return 0;
}


int Randomize(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int GameSet(void)
{
    while (Win < 3 && Lose < 3)
    {
          
		printf("\n시도 %d / 10\n", ++count );
        printf("\n한자리씩 세번입력 (0: 게임 종료, 1~9 중복 없음): ");
        scanf_s("%d", &UserNum1[0]);
        scanf_s("%d", &UserNum2[0]);
        scanf_s("%d", &UserNum3[0]);
        if ( UserNum1[0] > 9 || UserNum2[0] > 9 || UserNum3[0] > 9)
        {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            continue;
        }
        int result = Game();
        if (result == 1) {
            ++Win; RandomNumder();
        }
        else if (result == -1) {
            ++Lose; RandomNumder();
        }
        printf("현재 스코어 - 사용자: %d, 컴퓨터: %d\n", Win, Lose);
    }
    return 0;
}
int Game(void)
{
	StrikeBall();
    if (Strike == 3) 
    {
        printf("\n사용자가 이겼습니다.\n");
        Strike = 0;
        Ball = 0;
        return 1;
    }
    else if (count >= 10) 
    {
        printf("\n아쉽지만, 컴퓨터가 이겼습니다. 다음에 다시 도전하세요!\n");
        Strike = 0;
        Ball = 0;
		return -1;
    }
    else 
    {
        Strike = 0;
        Ball = 0;
        return 0;
	}
}

int RandomNumder(void)
{
    ComputerNum1[0] = Randomize(1, 9);
    ComputerNum2[0] = Randomize(1, 9);
    ComputerNum3[0] = Randomize(1, 9);
    while (ComputerNum1[0] == ComputerNum2[0] || ComputerNum1[0] == ComputerNum3[0] || ComputerNum2[0] == ComputerNum3[0])
    {
        ComputerNum1[0] = Randomize(1, 9);
        ComputerNum2[0] = Randomize(1, 9);
        ComputerNum3[0] = Randomize(1, 9);
    }
    return 0;
}
int StrikeBall(void)
{
    if (UserNum1[0] == ComputerNum1[0]) ++Strike;
    else if (UserNum1[0] == ComputerNum2[0] || UserNum1[0] == ComputerNum3[0]) ++Ball;
    if (UserNum2[0] == ComputerNum2[0]) ++Strike;
    else if (UserNum2[0] == ComputerNum1[0] || UserNum2[0] == ComputerNum3[0]) ++Ball;
    if (UserNum3[0] == ComputerNum3[0]) ++Strike;
    else if (UserNum3[0] == ComputerNum1[0] || UserNum3[0] == ComputerNum2[0]) ++Ball;
    printf("%d 스트라이크, %d 볼\n", Strike, Ball);
    return 0;
}
static int DoCheat(void)
{
    printf("치트 활성화 (Yes : 1 / No : 0) \n");
    scanf_s("%d", &Gamecheat);
    if (Gamecheat == 1) {
        printf("컴퓨터 숫자: %d %d %d\n", ComputerNum1[0], ComputerNum2[0], ComputerNum3[0]);
    }
    return 0;
}