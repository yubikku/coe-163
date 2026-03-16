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

void free_matrix(float **mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
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
    int n_max = 1000;
    // int n = 1500;
    int N = 128;
    int trials = 10;
    
    double start, end, time;
    printf("MMM ORDERING KJI:\n");

    for(int n=0; n<=n_max; n += 16){
        float **A = allocate_matrix(n);
        float **B = allocate_matrix(n);
        float **C = allocate_matrix(n);

        fill_random(A,n);
        fill_random(B,n);
        
        double total = 0;

        for(int t=0; t<trials; t++) {
            zero_matrix(C,n);
            get_walltime(&start);
            mmm_kji(A,B,C,n);
            get_walltime(&end);

            total += (end-start);
            // printf("%f\n", (end-start));
        }
        // Print Run time average per n matrix size
        printf("%f\n", total/trials);

        float checksum = 0.0f;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                checksum += C[i][j];

        printf("Checksum: %f\n", checksum);

        free_matrix(A, n);
        free_matrix(B, n);
        free_matrix(C, n);
       
    }

}
