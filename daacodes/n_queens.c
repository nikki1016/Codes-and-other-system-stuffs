/* C/C++ program to solve N Queen Problem using
   backtracking */
#define N 4
#include<stdio.h>
#include<stdlib.h>
 
/* A utility function to print solution */
void printSolution(int **board,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
 
/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
int isSafe(int **board, int row, int col,int n)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return 0;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return 0;
 
    return 1;
}
 
/* A recursive utility function to solve N
   Queen problem */
int solveNQUtil(int ** board, int col,int n)
{
    /* base case: If all queens are placed
      then return 1 */
    if (col >= n)
        return 1;
 
    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < n; i++)
    {
        /* Check if queen can be placed on
          board[i][col] */
        if ( isSafe(board, i, col,n) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
 
            /* recur to place rest of the queens */
            if ( solveNQUtil(board, col + 1,n) )
                return 1;
//to print all solutions  
//  solveNQUtil(board, col + 1,n) 
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
 
     /* If queen can not be place in any row in
        this colum col  then return 0 */
    return 0;
}
 
/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns 0 if queens
   cannot be placed, otherwise return 1 and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
int solveNQ(int **board,int n)
{

    if ( solveNQUtil(board, 0,n) == 0 )
    {
      printf("Solution does not exist");
      return 0;
    }
 
    printSolution(board,n);
    return 1;
}
 
// driver program to test above function
int main()
{
	int i,j,n;
	scanf("%d",&n);
	int **board;
	board=(int **)malloc(n*sizeof(int *));
	for(i =0; i<n; i++){
		board[i]=(int *)malloc(n*sizeof(int));
	}
	solveNQ(board,n);
    return 0;
}
