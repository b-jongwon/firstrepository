#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* fp = fopen("in1-1.txt", "r");
	if (fp == NULL)
	{
		printf("���� �������");
	}
	else {
		printf("���� ���� ����");
	}
	int a, b;

	fscanf(fp, "%d", &a);   /* fscanf ����Ҷ� "fp" �ƴϰ� scanfó�� �� & ���̱�.
							 fscanf ��ȯ���� ���� ������ ��ȯ��.  "%d %d" �̷��� �ϸ� 2 ��ȯ
							 ������ �� �о����� EOF (-1) ��ȯ �ƹ��͵� �� �о����� 0��ȯ (���ĺ���ġ ��).
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


	for (int i = 0; i < a-1; i++)                //L+1 �̴ϱ� a���� �ϰԵǸ� a�� ������ �� ÷�ڸ� �Ѿ� ������ ������ a-1�� ���ش�.
	{
		for (int j = 0; j < a-1-i; j++)     // j�� �ѹ����� ���ԵǸ� ���� ū ���� ���� �ڿ��ִ� -->> but ���� ������� ���ĵ������� ���� 
			                                // ���� -i�� �ϸ鼭 ���ϵڿ��ִ� ����ŭ �ݺ��� ���ϰ� �ȴ�.
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