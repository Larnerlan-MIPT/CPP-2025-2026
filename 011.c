#include <stdio.h>
#define MAX 100

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    float A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &A[i][j]);
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &B[i][j]);
    
    multiply(A, B, C, n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.0f ", C[i][j]);
        printf("\n");
    }
    
    return 0;
}