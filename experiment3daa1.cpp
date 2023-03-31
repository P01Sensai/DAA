#include <iostream>
using namespace std;

void matrixMultiply(int a[][4], int b[][4], int c[][4], int n)
{
    if(n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    int i, j;
    int m = n/2;
    int A[m][m], B[m][m], C[m][m], D[m][m], E[m][m], F[m][m], G[m][m], H[m][m];

    // Divide matrix A into 4 sub-matrices
    for(i=0; i<m; i++) {
        for(j=0; j<m; j++) {
            A[i][j] = a[i][j];
            E[i][j] = b[i][j];
        }
    }

    for(i=0; i<m; i++) {
        for(j=m; j<n; j++) {
            B[i][j-m] = a[i][j];
            F[i][j-m] = b[i][j];
        }
    }

    for(i=m; i<n; i++) {
        for(j=0; j<m; j++) {
            C[i-m][j] = a[i][j];
            G[i-m][j] = b[i][j];
        }
    }

    for(i=m; i<n; i++) {
        for(j=m; j<n; j++) {
            D[i-m][j-m] = a[i][j];
            H[i-m][j-m] = b[i][j];
        }
    }

    // Recursively compute the products of sub-matrices
    int P[m][m], Q[m][m], R[m][m], S[m][m];
    matrixMultiply(A, F, P, m);
    matrixMultiply(B, H, Q, m);
    matrixMultiply(C, E, R, m);
    matrixMultiply(D, G, S, m);

    // Combine sub-matrices to get the result matrix
    for(i=0; i<m; i++) {
        for(j=0; j<m; j++) {
            c[i][j] = P[i][j] + Q[i][j];
            c[i][j+m] = R[i][j] + S[i][j];
        }
    }

    for(i=m; i<n; i++) {
        for(j=0; j<m; j++) {
            c[i][j] = C[i-m][j] + D[i-m][j];
            c[i][j+m] = G[i-m][j] + H[i-m][j];
        }
    }
}

int main()
{
    int a[4][4] = { {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16} };

    int b[4][4] = { {17, 18, 19, 20},
                    {21, 22, 23, 24},
                    {25, 26, 27, 28},
                    {29, 30, 31, 32} };

    int c[4][4];

    matrixMultiply(a, b, c, 4);

    
    cout << "Resultant matrix: " << endl;
    for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
        cout << c[i][j] << " ";
    }
    cout << endl;
}
}    
