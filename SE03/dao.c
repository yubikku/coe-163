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

void fill_random(float** M, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            M[i][j] = (float)rand() / RAND_MAX;
}

void free_matrix(float **mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Row Major
void transpose_ij(float **A, float **B,int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

// Column Major
void transpose_ji(float **A, float **B,int n){
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            A[i][j] = B[j][i];
        }
    }
}

void transpose_uj_m4(float **A, float **B, int n){
    int m = 4;
    int i, j;

    // Main unrolled loop
    for (i = 0; i <= n - m; i += m) {
        for (j = 0; j < n; j++) {
            A[i][j]   = B[j][i];
            A[i+1][j] = B[j][i+1];
            A[i+2][j] = B[j][i+2];
            A[i+3][j] = B[j][i+3];
        }
    }

    // Remainder loop
    for (; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

void transpose_uj_m8(float **A, float **B,int n){
    int m = 8;
    int i, j;

    // Main unrolled loop
    for (i = 0; i <= n - m; i += m) {
        for (j = 0; j < n; j++) {
            A[i][j]   = B[j][i];
            A[i+1][j] = B[j][i+1];
            A[i+2][j] = B[j][i+2];
            A[i+3][j] = B[j][i+3];
            A[i+4][j] = B[j][i+4];
            A[i+5][j] = B[j][i+5];
            A[i+6][j] = B[j][i+6];
            A[i+7][j] = B[j][i+7];
        }
    }

    // Remainder loop
    for (; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

void transpose_uj_m10(float **A, float **B,int n){
    int m = 10;
    int i, j;

    // Main unrolled loop
    for (i = 0; i <= n - m; i += m) {
        for (j = 0; j < n; j++) {
            A[i][j]   = B[j][i];
            A[i+1][j] = B[j][i+1];
            A[i+2][j] = B[j][i+2];
            A[i+3][j] = B[j][i+3];
            A[i+4][j] = B[j][i+4];
            A[i+5][j] = B[j][i+5];
            A[i+6][j] = B[j][i+6];
            A[i+7][j] = B[j][i+7];
            A[i+8][j] = B[j][i+8];
            A[i+9][j] = B[j][i+9];
        }
    }

    // Remainder loop
    for (; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

void transpose_uj_m12(float **A, float **B,int n){
    int m = 12;
    int i, j;

    // Main unrolled loop
    for (i = 0; i <= n - m; i += m) {
        for (j = 0; j < n; j++) {
            A[i][j]   = B[j][i];
            A[i+1][j] = B[j][i+1];
            A[i+2][j] = B[j][i+2];
            A[i+3][j] = B[j][i+3];
            A[i+4][j] = B[j][i+4];
            A[i+5][j] = B[j][i+5];
            A[i+6][j] = B[j][i+6];
            A[i+7][j] = B[j][i+7];
            A[i+8][j] = B[j][i+8];
            A[i+9][j] = B[j][i+9];
            A[i+10][j] = B[j][i+10];
            A[i+11][j] = B[j][i+11];
        }
    }

    // Remainder loop
    for (; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

void transpose_uj_m14(float **A, float **B,int n){
    int m = 14;
    int i, j;

    // Main unrolled loop
    for (i = 0; i <= n - m; i += m) {
        for (j = 0; j < n; j++) {
            A[i][j]   = B[j][i];
            A[i+1][j] = B[j][i+1];
            A[i+2][j] = B[j][i+2];
            A[i+3][j] = B[j][i+3];
            A[i+4][j] = B[j][i+4];
            A[i+5][j] = B[j][i+5];
            A[i+6][j] = B[j][i+6];
            A[i+7][j] = B[j][i+7];
            A[i+8][j] = B[j][i+8];
            A[i+9][j] = B[j][i+9];
            A[i+10][j] = B[j][i+10];
            A[i+11][j] = B[j][i+11];
            A[i+12][j] = B[j][i+12];
            A[i+13][j] = B[j][i+13];
        }
    }

    // Remainder loop
    for (; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

// may mali sa code
void transpose_uj_m16(float **A, float **B,int n){
    int m = 16;
    int i, j;

    // Main unrolled loop
    for (i = 0; i <= n - m; i += m) {
        for (j = 0; j < n; j++) {
            A[i][j]   = B[j][i];
            A[i+1][j] = B[j][i+1];
            A[i+2][j] = B[j][i+2];
            A[i+3][j] = B[j][i+3];
            A[i+4][j] = B[j][i+4];
            A[i+5][j] = B[j][i+5];
            A[i+6][j] = B[j][i+6];
            A[i+7][j] = B[j][i+7];
            A[i+8][j] = B[j][i+8];
            A[i+9][j] = B[j][i+9];
            A[i+10][j] = B[j][i+10];
            A[i+11][j] = B[j][i+11];
            A[i+12][j] = B[j][i+12];
            A[i+13][j] = B[j][i+13];
            A[i+14][j] = B[j][i+14];
            A[i+15][j] = B[j][i+15];
        }
    }

    // Remainder loop
    for (; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = B[j][i];
        }
    }
}

void transpose_blocked(float **A, float **B, int n, int block) {
    for (int i = 0; i < n; i += block) {
        for (int j = 0; j < n; j += block) {
            // Processing the blocks
            for (int ii = i; ii < i + block && ii < n; ii++) {
                for (int jj = j; jj < j + block && jj < n; jj++) {
                    A[ii][jj] = B[jj][ii];
                }
            }
        }
    }
}


void transpose_blocked_uj_m12(float **A, float **B, int n, int block) {

    int m = 12;

    for (int i = 0; i < n; i += block) {
        for (int j = 0; j < n; j += block) {

            int i_end = (i + block < n) ? i + block : n;
            int j_end = (j + block < n) ? j + block : n;

            int ii;

            // Unrolled region inside block
            for (ii = i; ii <= i_end - m; ii += m) {
                for (int jj = j; jj < j_end; jj++) {

                    A[ii][jj]     = B[jj][ii];
                    A[ii+1][jj]   = B[jj][ii+1];
                    A[ii+2][jj]   = B[jj][ii+2];
                    A[ii+3][jj]   = B[jj][ii+3];
                    A[ii+4][jj]   = B[jj][ii+4];
                    A[ii+5][jj]   = B[jj][ii+5];
                    A[ii+6][jj]   = B[jj][ii+6];
                    A[ii+7][jj]   = B[jj][ii+7];
                    A[ii+8][jj]   = B[jj][ii+8];
                    A[ii+9][jj]   = B[jj][ii+9];
                    A[ii+10][jj]  = B[jj][ii+10];
                    A[ii+11][jj]  = B[jj][ii+11];
                }
            }

            // Remainder Case
            for (; ii < i_end; ii++) {
                for (int jj = j; jj < j_end; jj++) {
                    A[ii][jj] = B[jj][ii];
                }
            }

        }
    }
}

int main(){
    int n_max = 2048;
    // int n = 1;
    int N = 128;
    int trials = 30;

    double bandwidth, walltime, start, end, ave_wt;
    
    for(int n=16; n<=n_max; n += 16){
        
        // Allocate memory
        float **A = malloc(n * sizeof(float *));
        float **B = malloc(n * sizeof(float *));
        for(int i = 0; i < n; i++) {
            A[i] = malloc(n * sizeof(float));
            B[i] = malloc(n * sizeof(float));
        }
        
        fill_random(A,n);
        fill_random(B,n);

        double total = 0, bytes_processed=0;

        // 2 matrices * nxn matrix * 4 bytes (for float)
        bytes_processed = 2 * n * n * 4;  
        // printf("nagsimula na (main)\n");
        for (int t=0; t<trials; t++ ){
                get_walltime(&start);
                // transpose_blocked_uj_m12(A,B,n,N);
                transpose_blocked(A,B,n,N);
                get_walltime(&end);

                total += (end - start);
        }
        
        ave_wt = total/trials;
        bandwidth = (bytes_processed/1e6)/ave_wt; // in Effective bandwidth in MB/s

        printf("n size: %d\n", n);
        printf("Average runtime: %f\n", ave_wt);
        printf("Effective Bandwidth: %f\n", bandwidth);

        free_matrix(A, n);
        free_matrix(B, n);
    }
}

