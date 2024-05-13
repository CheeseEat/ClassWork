#include <stdio.h>
#include <time.h>

void scaleColumn(int n, int m, int array[][9], int scale); 
void scaleRow(int n, int m, int array[][9], int scale); 

int main()
{
    
    clock_t start = clock();

    int tempArray[][9] = 
    {
        {4, 5, 12, 8, 9, 13, 6, 6, 5},
        {2, 9, 12, 8, 9, 13, 7, 5, 2},
        {3, 5, 14, 8, 2, 14, 6, 4, 5},
        {4, 5, 17, 6, 3, 13, 5, 6, 1},
        {3, 5, 10, 8, 4, 16, 5, 5, 5},
        {5, 5, 17, 7, 5, 11, 7, 4, 4},
        {4, 5, 18, 8, 9, 13, 3, 3, 6},
        {4, 5, 13, 9, 2, 18, 2, 1, 4},
        {1, 5, 15, 9, 9, 13, 7, 0, 5}
    };

    for(int i = 0; i < 1000; i++)
    {
        scaleRow(9, 9, tempArray, 3);
    }

    printf("done!\n");

    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    
    printf("Time measured: %.3f seconds.\n", elapsed);

    return 0;

}

void scaleColumn(int n, int m, int array[][9], int scale)
{
    for(int k = 0; k < n; k++)
    {
        for(int j = 0; j < m; j++)
        {
            array[k][j] = array[k][j] * scale;
            printf("%d ", array[k][j]);
        }
        printf("\n");
    }
}

void scaleRow(int n, int m, int array[][9], int scale)
{
    for(int j = 0; j < m; j++)   //Column incrementer
    {
        for(int k = 0; k < n; k++)
        {
            array[k][j] = array[k][j] * scale;
            printf("%d ", array[k][j]);
        }
        printf("\n");
    }
}

