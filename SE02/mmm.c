#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


// Wall time function provided in the preliminaries
void get_walltime_(double* wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (double) (tp.tv_sec + tp.tv_usec/1000000.0);
}
void get_walltime(double* wcTime) {
    get_walltime_(wcTime);
}

float** allocate_matrix(int n) {
    float **mat = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        mat[i] = (float *)malloc(n * sizeof(float));
    }
    return mat;
}

// Fill up Matrix with RNG 
void fill_random(float** M, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            M[i][j] = (float)rand() / RAND_MAX;
}


void zero_matrix(float** M, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            M[i][j] = 0.0f;
}

// 1. MMM IJK
void mmm_ijk(float **A, float **B, float **C, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                C[i][j] += A[i][k] * B[k][j];
}

// 2. MMM IKJ
void mmm_ikj(float **A, float **B, float **C, int n) {
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                C[i][j] += A[i][k] * B[k][j];
}

// 3. MMM JIK
void mmm_jik(float **A, float **B, float **C, int n) {
    for(int j=0;j<n;j++)
        for(int i=0;i<n;i++)
            for(int k=0;k<n;k++)
                C[i][j] += A[i][k] * B[k][j];
}

// 4. MMM JKI
void mmm_jki(float **A, float **B, float **C, int n) {
    for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                C[i][j] += A[i][k] * B[k][j];
}

// 5. MMM KIJ
void mmm_kij(float **A, float **B, float **C, int n) {
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                C[i][j] += A[i][k] * B[k][j];
}

// 6. MMM KJI
void mmm_kji(float **A, float **B, float **C, int n) {
    for(int k=0;k<n;k++)
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                C[i][j] += A[i][k] * B[k][j];
}

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
    int n = 800;
    int N = 16;
    int trials = 30;

    float **A = allocate_matrix(n);
    float **B = allocate_matrix(n);
    float **C = allocate_matrix(n);

    fill_random(A,n);
    fill_random(B,n);

    double start, end, time, total = 0;

    //for(int x=0; x<)

    for(int t=0; t<trials; t++) {
        zero_matrix(C,n);

        get_walltime(&start);
        mmm_ijk(A,B,C,n);
        get_walltime(&end);

        time = end-start;
        total += (end-start);
        //printf("Trial %i: %f sec\n", t+1, time);
        printf("%f\n",time);
    }

    printf("Average runtime: %f sec\n", total/trials);
}
