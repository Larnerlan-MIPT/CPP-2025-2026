#include <stdio.h>
#define MAX 100

void assign(int A[MAX][MAX], int B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    int temp[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++)
                temp[i][j] += A[i][k] * B[k][j];
        }
    }
    assign(C, temp, n);
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
    int temp[MAX][MAX];
    assign(temp, A, n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = (i == j) ? 1 : 0;
    
    while (k > 0)
    {
        if (k % 2 == 1)
        {
            multiply(C, temp, C, n);
        }
        multiply(temp, temp, temp, n);
        k /= 2;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int A[MAX][MAX], C[MAX][MAX];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    
    power(A, C, n, k);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    
    return 0;
}