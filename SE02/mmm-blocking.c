#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Wall time function provided in the preliminaries [cite: 8, 13]
void get_walltime_(double* wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (double) (tp.tv_sec + tp.tv_usec/1000000.0);
}
void get_walltime(double* wcTime) {
    get_walltime_(wcTime);
}

// Helper to allocate n-by-n matrix
float** allocate_matrix(int n) {
    float **mat = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        mat[i] = (float *)malloc(n * sizeof(float));
    }
    return mat;
}

// Part 2: MMM with Blocking
// N is the block size parameter 
void mmm_blocked(float **A, float **B, float **C, int n, int N) {
    for (int i = 0; i < n; i += N) {
        for (int j = 0; j < n; j += N) {
            for (int k = 0; k < n; k += N) {
                // Multiply the blocks
                for (int ii = i; ii < i + N && ii < n; ii++) {
                    for (int kk = k; kk < k + N && kk < n; kk++) {
                        float r = A[ii][kk];
                        for (int jj = j; jj < j + N && jj < n; jj++) {
                            C[ii][jj] += r * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n = 512; // Matrix size 
    int block_N = 32; // Block size 
    double start, end;

    float **A = allocate_matrix(n);
    float **B = allocate_matrix(n);
    float **C = allocate_matrix(n);

    get_walltime(&start);
    mmm_blocked(A, B, C, n, block_N);
    get_walltime(&end);
    printf("Blocked Time: %f seconds\n", end - start);

    return 0;
}