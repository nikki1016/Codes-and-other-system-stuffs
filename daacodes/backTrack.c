#include <stdio.h>
#include <stdlib.h>
int inp[] = {1,5,7,4,0,2,3,8,6};
void solve(int **);
int moveX[20]={1,0,0,-1};
int moveY[20]={0,1,-1,0};
int main()
{
  int i,**board,j;
  board = (int **)malloc(3*sizeof(int *));
  board[0] = (int *)malloc(3*sizeof(int));
  board[1] = (int *)malloc(3*sizeof(int));
  board[2] = (int *)malloc(3*sizeof(int));
  /*for(i=0;i<3;i=i+1) {
    scanf("%d%d%d",&board[i][0],&board[i][1],&board[i][2]);
  }*/
  int ptr = 0;
  int n = 3;
  for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
  	   board[i][j] = inp[ptr++];
  solve(board);
  return 0;
}

void solve(int **board) {
 int i,j,x,y,n=3; 
 int **visited;
 visited = (int **)malloc(3*sizeof(int *));
 for(i=0;i<n;i++)
    visited[i] = (int *)malloc(3*sizeof(int));
 for(i=0;i<n;i++){
   for(j=0;j<n;j++)
     visited[i][j] = 0;
 }
 /*
    int i=0;int diffX,diffY,temp;
    int r=findRow();
    int c=findCol();
    temp=arr[r][c];
    arr[r][c]=arr[row][col];
    arr[row][col]=temp;
    if(n>=9){
        //print();
        if(isReady())
            printf("Finished");
        depth++;
        return;
    }
    for(i=0;i<4;i++){
        diffX=row+moveX[i];
        diffY=col+moveY[i];
        if(diffX>=0 && diffX<4 && diffY>=0 && diffY<4){
            perm(diffX,diffY,n+1);
        }
    }
    temp=arr[r][c];
    arr[r][c]=arr[row][col];
    arr[row][col]=temp;
}*/
 /*int temp[10];
  int ptr=0;
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        temp[ptr++] = arr[i][j];
  if( inv_count(temp) % 2 == 0)
     return 1;
  return -1;*/
 /*if(issolvable(board) == 1){
   printf("Solvable");
   return;
 } else{
  printf("unsolvable");
  return;
 }*/
 /*for(i=0;i<n;i++)
   for(j=0;j<n;j++){
     if( board[i][j] == 0 ){
      	break;
     }
   }*/

 /*
    int i=0;int diffX,diffY,temp;
    int r=findRow();
    int c=findCol();
    temp=arr[r][c];
    arr[r][c]=arr[row][col];
    arr[row][col]=temp;
    if(n>=9){
        //print();
        if(isReady())
            printf("Finished");
        depth++;
        return;
    }
    for(i=0;i<4;i++){
        diffX=row+moveX[i];
        diffY=col+moveY[i];
        if(diffX>=0 && diffX<4 && diffY>=0 && diffY<4){
            perm(diffX,diffY,n+1);
        }
    }
    temp=arr[r][c];
    arr[r][c]=arr[row][col];
    arr[row][col]=temp;
}*/
 /*int temp[10];
  int ptr=0;
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        temp[ptr++] = arr[i][j];
  if( inv_count(temp) % 2 == 0)
     return 1;
  return -1;*/
printf("0 at 1 1\n");
 if(func(board,3,1,1,-1,-1,visited) == -1){
  if(issolvable(board))
  printf("solvable");
  else
    printf("unsolvable");
  } 
}
void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
   *b = temp;
}
int check(int **arr) {
int i,j,ptr=0;
  for(i=0;i<3;i++)
      for(j=0;j<3;j++)
       if(arr[i][j] != ptr++);
	return -1;
  return 1;
}
int inv_count(int temp[]){
  int i,j,cnt = 0;
  for(i=0;i<8;i++)
     for(j=i+1;j<9;j++)
         if(temp[i]>0 && temp[j]>0 && temp[i]>temp[j])
              cnt++;
  return cnt;
}
int issolvable(int **arr){
  int temp[10];
  int ptr=0;
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
	      temp[ptr++] = arr[i][j];
  if( inv_count(temp) % 2 == 0)
     return 1;
  return -1;
}
int func(int **arr,int n,int x,int y,int px,int py,int **visited){
    if(issolvable(arr) == -1)
       return -1;
    printf("At %d %d\n",x,y);
    int temp,status;
    visited[x][y] = 1;
    //printf("Adsasd");
    if( x-1 >= 0 && visited[x-1][y] == 0){
      //printf("First\n");
  	  swap(&arr[x][y],&arr[x-1][y]);
  	  if( func(arr,n,x-1,y,x,y,visited) > 0)
  	    return 1;
  	  swap(&arr[x][y],&arr[x-1][y]);
    } if(x+1 < n && x+1!=px && y!=py && visited[x+1][y] == 0){
    	swap(&arr[x][y],&arr[x+1][y]);
    	if( func(arr,n,x+1,y,x,y,visited) > 0)
    	 return 1;
    	swap(&arr[x][y],&arr[x+1][y]);
    } if( y-1>=0 && x!=px && y-1 != py && visited[x][y-1] == 0){
    	swap(&arr[x][y],&arr[x][y-1]);
    	if( func(arr,n,x,y-1,x,y,visited) > 0)
    	 return 1;	 
      swap(&arr[x][y],&arr[x][y-1]);
    } if( y+1<n && x!=px && y+1!=py && visited[x][y+1] == 0){
    	swap(&arr[x][y],&arr[x][y+1]);
    	if( func(arr,n,x,y+1,x,y,visited) > 0)
    	 return 1;	 
      swap(&arr[x][y],&arr[x][y+1]);
    }
    visited[x][y] = 0;
    if(x == 0 && y == 0){
      if(check(arr) == 1){
            printf("Solvable");
          return 1;
       }
    } 
    return -1;
}
/*void perm(int **arr,int row,int col,int n){
    int i=0;int diffX,diffY,temp;
    int r=findRow();
    int c=findCol();
    temp=arr[r][c];
    arr[r][c]=arr[row][col];
    arr[row][col]=temp;
    if(n>=9){
        //print();
        if(isReady())
            printf("Finished");
        depth++;
        return;
    }
    for(i=0;i<4;i++){
        diffX=row+moveX[i];
        diffY=col+moveY[i];
        if(diffX>=0 && diffX<4 && diffY>=0 && diffY<4){
            perm(diffX,diffY,n+1);
        }
    }
    temp=arr[r][c];
    arr[r][c]=arr[row][col];
    arr[row][col]=temp;
}*/
































   
