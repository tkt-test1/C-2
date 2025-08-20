#include <stdio.h>
#include <stdlib.h>

/*
 * 行列の掛け算を行うプログラム
 * A(m×n) × B(n×p) = C(m×p)
 * 
 * - 動的メモリ確保を使って可変サイズの行列を扱う
 * - 計算後にメモリ解放
 */

void multiply_matrices(int **A, int **B, int **C, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m = 2, n = 3, p = 2;

    // 行列A, B, Cの動的確保
    int **A = malloc(m * sizeof(int *));
    int **B = malloc(n * sizeof(int *));
    int **C = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) A[i] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) B[i] = malloc(p * sizeof(int));
    for (int i = 0; i < m; i++) C[i] = malloc(p * sizeof(int));

    // 行列A, Bに値を代入
    int counter = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = counter++;

    counter = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            B[i][j] = counter++;

    // 行列の掛け算
    multiply_matrices(A, B, C, m, n, p);

    // 結果表示
    printf("Result:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    // メモリ解放
    for (int i = 0; i < m; i++) free(A[i]);
    for (int i = 0; i < n; i++) free(B[i]);
    for (int i = 0; i < m; i++) free(C[i]);
    free(A); free(B); free(C);

    return 0;
}
