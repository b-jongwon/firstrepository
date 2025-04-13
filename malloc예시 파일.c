#include <stdio.h>
#include <stdlib.h>

// ����ü ����
typedef struct {
    int id;
    float score;
} Student;

int main() {
    // 1. int �ϳ� �Ҵ�
    int* a = (int*)malloc(sizeof(int));
    *a = 10;
    printf("int �ϳ� �Ҵ�: %d\n", *a);
    free(a);

    // 2. int �迭 �Ҵ�
    int N = 5;
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);

    // 3. ����ü �ϳ� �Ҵ�
    Student* s = (Student*)malloc(sizeof(Student));
    s->id = 1;
    s->score = 95.5;
    printf("����ü �ϳ�: id = %d, score = %.1f\n", s->id, s->score);
    free(s);

    // 4. ����ü �迭 �Ҵ�
    Student* list = (Student*)malloc(sizeof(Student) * N);
    for (int i = 0; i < N; i++) {
        list[i].id = i + 1;
        list[i].score = 80.0 + i;
        printf("list[%d] = {id: %d, score: %.1f}\n", i, list[i].id, list[i].score);
    }
    free(list);

    // 5. 2���� �迭 �Ҵ�
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

    // 6. ���ڿ� �Ҵ�
    char* str = (char*)malloc(sizeof(char) * 100);
    sprintf(str, "Hello, malloc string!");
    printf("���ڿ� �Ҵ�: %s\n", str);
    free(str);

    // 7. calloc ���
    int* zeros = (int*)calloc(N, sizeof(int));
    printf("calloc���� �ʱ�ȭ�� �迭:\n");
    for (int i = 0; i < N; i++) {
        printf("zeros[%d] = %d\n", i, zeros[i]);
    }
    free(zeros);

    // 8. realloc ���
    int* dynArr = (int*)malloc(sizeof(int) * 2);
    dynArr[0] = 1;
    dynArr[1] = 2;
    dynArr = (int*)realloc(dynArr, sizeof(int) * 4);
    dynArr[2] = 3;
    dynArr[3] = 4;
    printf("realloc���� Ȯ��� �迭: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");
    free(dynArr);

    // 9. NULL ������ �ʱ�ȭ
    int* ptr = NULL;
    if (ptr == NULL) {
        printf("ptr�� ���� NULL�Դϴ�.\n");
    }

    return 0;
}