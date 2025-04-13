#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE* fp = fopen("in1-1.txt", "r");
	if (fp == NULL)
	{
		printf("파일 열기실패");
	}
	else {
		printf("파일 열기 성공");
	}
	int a,b;
	printf("%d",fscanf(fp, "%d %d", &a, &b));   /* fscanf 사용할때 "fp" 아니고 scanf처럼 꼭 & 붙이기.
	                         fscanf 반환값은 읽은 갯수를 반환함.  "%d %d" 이렇게 하면 2 반환
							 파일을 다 읽었으면 EOF (-1) 반환 아무것도 못 읽었으면 0반환 (형식불일치 등).
	                         */
	printf("%d", a);  



	return 0;
}