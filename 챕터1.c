#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE* fp = fopen("in1-1.txt", "r");
	if (fp == NULL)
	{
		printf("���� �������");
	}
	else {
		printf("���� ���� ����");
	}
	int a,b;
	printf("%d",fscanf(fp, "%d %d", &a, &b));   /* fscanf ����Ҷ� "fp" �ƴϰ� scanfó�� �� & ���̱�.
	                         fscanf ��ȯ���� ���� ������ ��ȯ��.  "%d %d" �̷��� �ϸ� 2 ��ȯ
							 ������ �� �о����� EOF (-1) ��ȯ �ƹ��͵� �� �о����� 0��ȯ (���ĺ���ġ ��).
	                         */
	printf("%d", a);  



	return 0;
}