#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(void)
{
	
	MaxMin(0);
	Print(0);
	RepliCation(0);
	return 0;

}




int MaxMin(void)
{

	srand((unsigned int)time(NULL));

	int arr[128] = { 0 };
	int arr_count = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arr_count; ++i)
	{
		arr[i] = rand() % 1000;
	}
	int maxVal = arr[0];
	int minVal = arr[0];
	for (int i = 1; i < arr_count; ++i)
	{
		if (arr[i] > maxVal)
			maxVal = arr[i];

		if (arr[i] < minVal)
			minVal = arr[i];
	}
	printf("최대값: % d\n", maxVal);
	printf("최소값: % d\n", minVal);
}



int Print(void)
{
	int arr1[1000];
	int size = 1000;
	for (int i = 0; i < size; i++) {
		arr1[i] = i;
	}
	printf("--- 배열 역순 출력 ---\n");
	for (int i = size - 1; i >= 0; i--) {
		printf("%d ", arr1[i]);
	}
}


int RepliCation(void)
{
	int source[1000];
	int target[1000];
	int size = 1000;

	for (int i = 0; i < size; i++) {
		source[i] = i + 1;
	}

	for (int i = 0; i < size; i++) {
		target[i] = source[i];
	}

	printf("복사 완료! target[999]의 값: %d\n", target[999]);
}