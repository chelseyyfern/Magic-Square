#include <stdio.h>
#include <stdlib.h>

// A program to check if a user inputted Matrix is Magic square or not
int main()
{
    // Initialising the values for the Variables
    int magicSquare[100][100]; //2D array "magicSquare"
    int i; // Index of the rows
    int j; // Index of the columns
    int ROW; // Number of rows
    int COL; // Number of columns
    int sum_rows[10]; // Sum of rows
    int sum_cols[10]; // Sum of columns
    int *p,*q,m,n;
    int d1=0; // Primary diagonal (Top left - Bottom right)
    int d2=0; // Secondary diagonal (Top right - Bottom left)
    int num,x=0,b[100];
    
    // Entering the number of rows and columns in a matrix to check if it is a Square Matrix or not
    printf("Enter grid size \n");
    scanf("%d %d”,&m,&n);
	
	// Assigning the value of m and n as row and column respectively using pointers
    p=&ROW;
    q=&COL;
    *p=m;
    *q=n;
    if (ROW!=COL)
    {
        printf("This is not a square matrix. Try Again!");
        exit(0);
    }
    
    //Inputting elements into the 2D array 
    printf("\n Enter elements of the matrix to check if it is a Magic Square: \n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            scanf("%d",&magicSquare[i][j]);

        }
    }
    
     //Making a duplicate 1D array 
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            b[x++]=magicSquare[i][j];
            
        }
    }
    
     //Checking if the inputted elements are distinct or not
    for (num=0;num<x-1;num++) 
    {
        for (j=num+1;j<x;j++)
        if (b[num]==b[j]){
            printf("Elements are not distinct\n");
            printf("Matrix is not magic");
            exit(0);
        }
    }
    //Comparing the two diagonals 
    for(i=0;i<ROW;i++) 
    {
        d1=d1+magicSquare[i][i];
        d2=d2+magicSquare[i][ROW-i-1];
        
    }
     //Checking if the sum of elements in rows is equal to sum of elements in primary diagonal
    for(i=0;i<ROW;i++)
    {
        sum_rows[i]=0;
        for(j=0;j<COL;j++)
        {
            sum_rows[i]=sum_rows[i]+magicSquare[i][j];
            
        }
        if (sum_rows[i]!=d1)
        {
            printf("The sum of elements in the row is not equal to the sum of elements in the Primary diagonal. \n");
            printf("Here is an example of an auto generated Magic Square grid!\n");
                int last_ele = ROW*COL;
                int i = 0;
                int j = m / 2;
                int num;// Number of elements from 1 to m**2
                for (num = 1; num <= last_ele; ++num)
                
                {
                    magicSquare[i][j] = num;
                    i--;
                    j++;
                    if (num % m == 0) 
                    { 
                        i += 2; 
                        --j; 
                        
                    }
                    else
                    {
                        if(j==m)
                        {
                            j-=m;
                            
                        }
                        else if (i < 0)
                        {
                            i += m;
                            
                        }
                    }
                    
                }
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < m; j++)
                {
                    printf("%d  ", magicSquare[i][j]);
                }
                printf("\n");
            }
            printf("\n");
                
            exit(0);
        }
    }
    //Checking if the sum of elements in columns is equal to sum of elements in primary diagonal
    for(i=0;i<COL;i++)
    {
        sum_cols[i]=0;
        for(j=0;j<ROW;j++)
        {
            sum_cols[i]=sum_cols[i]+magicSquare[j][i];
        }
        if (sum_cols[i]!=d1)
        {
            printf("The sum of elements in the column is not equal to the sum of elements in the Primary diagonal");
            exit(0);
        }
    }
    
    printf("Matrix is Magic\n");
    for (i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%d\t",magicSquare[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    }

