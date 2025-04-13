#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
typedef struct {
    int id;
    float score;
} Student;

int main() {
    // 1. int 하나 할당
    int* a = (int*)malloc(sizeof(int));
    *a = 10;
    printf("int 하나 할당: %d\n", *a);
    free(a);

    // 2. int 배열 할당
    int N = 5;
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);

    // 3. 구조체 하나 할당
    Student* s = (Student*)malloc(sizeof(Student));
    s->id = 1;
    s->score = 95.5;
    printf("구조체 하나: id = %d, score = %.1f\n", s->id, s->score);
    free(s);

    // 4. 구조체 배열 할당
    Student* list = (Student*)malloc(sizeof(Student) * N);
    for (int i = 0; i < N; i++) {
        list[i].id = i + 1;
        list[i].score = 80.0 + i;
        printf("list[%d] = {id: %d, score: %.1f}\n", i, list[i].id, list[i].score);
    }
    free(list);

    // 5. 2차원 배열 할당
    int rows = 3, cols = 4;
    int** mat = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            mat[i][j] = i * cols + j;
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    // 6. 문자열 할당
    char* str = (char*)malloc(sizeof(char) * 100);
    sprintf(str, "Hello, malloc string!");
    printf("문자열 할당: %s\n", str);
    free(str);

    // 7. calloc 사용
    int* zeros = (int*)calloc(N, sizeof(int));
    printf("calloc으로 초기화된 배열:\n");
    for (int i = 0; i < N; i++) {
        printf("zeros[%d] = %d\n", i, zeros[i]);
    }
    free(zeros);

    // 8. realloc 사용
    int* dynArr = (int*)malloc(sizeof(int) * 2);
    dynArr[0] = 1;
    dynArr[1] = 2;
    dynArr = (int*)realloc(dynArr, sizeof(int) * 4);
    dynArr[2] = 3;
    dynArr[3] = 4;
    printf("realloc으로 확장된 배열: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");
    free(dynArr);

    // 9. NULL 포인터 초기화
    int* ptr = NULL;
    if (ptr == NULL) {
        printf("ptr은 현재 NULL입니다.\n");
    }

    return 0;
}