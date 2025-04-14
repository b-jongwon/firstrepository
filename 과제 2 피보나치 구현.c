#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void Iterative(int *ary[], int n)  //�迭�� �Ű������� �ް� �迭�� ������ִ� N���� ������ �����Ѵٴ� ��.
{
	ary[0] = 0;
	ary[1] = 1;
	for (int i = 2; i < n - 1; i++)
	{
		ary[i] = ary[i - 1] + ary[i - 2];
	}
	return 0;
}


int main() {


	int N;
	int *L;
	
	while (1) {
		scanf("%d", &N);
		if (!(0 <= N && N <= 45))
		{
			printf("��� ������ ������ϴ�");
			return 0;
		}

		L = (int*)malloc(sizeof(int) * (N + 1));

		
		Iterative(&L, N);

			printf("%d", L[N - 1]);
	}
	return 0;
}


float rsum(int list[], int n)
{
	if (n) return rsum(list, n - 1) + list[n - 1];
	return 0;
}
