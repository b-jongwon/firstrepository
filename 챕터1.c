#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* fp = fopen("in1-1.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기실패");
	}
	else {
		printf("파일 열기 성공");
	}
	int a, b;

	fscanf(fp, "%d", &a);   /* fscanf 사용할때 "fp" 아니고 scanf처럼 꼭 & 붙이기.
							 fscanf 반환값은 읽은 갯수를 반환함.  "%d %d" 이렇게 하면 2 반환
							 파일을 다 읽었으면 EOF (-1) 반환 아무것도 못 읽었으면 0반환 (형식불일치 등).
							 */
	printf("n:%d\n", a);
	int* L = (int*)malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++)
	{
		fscanf(fp, "%d", &b);
		L[i] = b;
	}
	printf("L: ");
	for (int i = 0; i < a; i++)
	{
		printf(" %d", L[i]);
	}
	printf("n:%d\n", a);
	int temp;


	for (int i = 0; i < a-1; i++)                //L+1 이니까 a까지 하게되면 a가 됐을때 즉 첨자를 넘어 버리기 떄문에 a-1을 해준다.
	{
		for (int j = 0; j < a-1-i; j++)     // j가 한바퀴를 돌게되면 제일 큰 수는 제일 뒤에있다 -->> but 모든게 순서대로 정렬돼있지는 않음 
			                                // 따라서 -i를 하면서 제일뒤에있는 수만큼 반복을 덜하게 된다.
		{
			if (L[j]>L[j+1])
			{
				temp = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp;
			}
			
		}
	}
	for (int i = 0; i < a; i++)
	{
		printf(" %d", L[i]);
	}




	return 0;
}