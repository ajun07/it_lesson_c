#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define size 100

int InitArray(int arr[]);
int BubbleSort(int arr[], int mode); 
int PrintArray(int arr[]);

int main(void) {

    Start(0);
    return 0;
}


int InitArray(int arr[]) {
    for (int i = 0; i < size; i++) arr[i] = rand() % 90 + 10;
    printf("\n--- 배열이 초기화되었습니다 ---\n");
}


int BubbleSort(int arr[], int mode) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if ((mode == 1 && arr[j] > arr[j + 1]) || (mode == 2 && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int PrintArray(int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}

int Start(void)
{
    int numArray[size];
    char input;

    srand((unsigned int)time(NULL));
    InitArray(numArray);

    while (1) {
        printf("\n[A]오름 [D]내림 [R]섞기 [Q]종료: ");
        scanf_s(" %c", &input, 1);

        if (input == 'q' || input == 'Q') break;

        if (input == 'a' || input == 'A') BubbleSort(numArray, 1);
        else if (input == 'd' || input == 'D') BubbleSort(numArray, 2);
        else if (input == 'r' || input == 'R') InitArray(numArray);

        PrintArray(numArray);
          }
}