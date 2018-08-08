#include<stdio.h>
 #include<stdlib.h>
struct node {
	struct node *parent;
	int x,y;
	int cost,level;
	int child[3][3];
};

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void printSolution(int board[3][3])
{
    int i, j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
            printf(" %d ", board[i][j]);
    	printf("\n");
    }
	printf("\n");
}
void printpath(struct node *tt){
	if(tt == NULL)
		return;
	printpath(tt->parent);
	printSolution(tt->child);
}
int same(int board[][3],int arr[][3])
{
	int i, j;
	//printf("same\n");
	for (i = 0; i < 3; i++){
		for(j =0; j<3; j++){
			if(board[i][j] != arr[i][j])
					return 0;
		}
	}
	return 1;
}
int isSafe(int board[][3],int x,int y,struct node *deadque[],int top2){
	int i, j,flag=0;
	int arr[3][3];
	int a=i,b=j;
	for (i = 0; i < 3; i++){
		for(j =0; j<3; j++){
			arr[i][j] = board[i][j];
			if(board[i][j] == 0 ){
					a=i;b=j;
			}
		}
	}
	if(a + x >= 3 || a+x < 0 || b +y >= 3 || b+y < 0)
		return 0;
	/*swap(&arr[a][b] , &arr[a+x][b+y]);
	//printf("is safe\n");
	//printSolution(arr);

	for(i =0; i<=top2; i++){
		//printf("dead %d i\n",i);
		if(same(deadque[i]->child,arr) == 1){

			//printf("vssv\n");
			return 0;
		}
	}*/
	return 1;
}

int calculateCost(int board[][3],int final[][3]){
	int i,j, cnt=0;
	for(i =0; i<3; i++){
		for(j =0; j<3; j++){
			if(board[i][j] != 0 && board[i][j] != final[i][j])
				cnt++;
		}
	}
	return cnt;
}

void sort(struct node *que[],int n){
	int i,j;
	for(i =0; i<=n-1; i++){
		for(j =i+1; j<=n; j++){
			if(((que[i]->cost) + (que[i]->level)) < ((que[j]->cost) +(que[j]->level))){
				struct node *temp = que[i];
				que[i] =que[j];
				que[j] =temp;
			}
		}
	}
}
void enqueue(struct node *que[],struct node *root,int *top){
	(*top)++;
	if(*top ==1000)
		return;
	que[*top] = root;
	sort(que,*top);
	//printf("%d top\n",*top);
}
struct node *deque(struct node *que[],int *top){
	if(*top == -1)
		return NULL;
	struct node *p = que[*top];
	(*top)--;
	//printf("de top %d\n",*top);
	return p;
}
// Function to allocate a new node
struct node *newnode(int x,int y, struct node* parent)
{
	int i, j,flag=0,board[3][3];
	int a=i,b=j;
	for (i = 0; i < 3; i++){
		for(j =0; j<3; j++){
			board[i][j] = parent->child[i][j] ;
			if(parent->child[i][j] == 0  ){
					a=i;b=j;
			}
		}
	}
	//printSolution(parent->child);
	swap(&board[a][b] , &board[a+x][b+y]);
	//printSolution(board);
   	struct node *root = (struct node *) malloc(sizeof(struct node ));
	for(i =0; i<3; i++){
		for(j =0; j <3; j++){
			root->child[i][j] = board[i][j];
			if(board[i][j] == 0){
				root->x = i;
				root->y = j;
			}
		}
	}
	root->parent = parent;
	root->level = parent->level+1;
    return root;
}
int solve3QUtil(struct node *que[],struct node * deadque[],int final[][3],int *top,int *top2){
	int i,j,arr[3][3];
    while(*top != -1){
		struct node *tt = deque(que,top);
		struct node *kk = (struct node *) malloc(sizeof(struct node ));
		kk->parent = tt->parent;
		kk->x = tt->x;
		kk->y = tt->y;
		kk->cost = tt->cost;
		kk->level= tt->level;
		for(i=0; i<3; i++){
			for(j =0; j<3; j++){
				kk->child[i][j] = tt->child[i][j];
				arr[i][j] = tt->child[i][j];
			}
		}
		enqueue(deadque,kk,top2);
		//printf("%d top2\ndequeue\n",*top2);
		//printSolution(tt->child);
		if(tt->cost == 0){
			printpath(tt);
			//printf("hii\n");
			return 1;
		}
		int row[4] ={1,0,-1,0};
		int col[4] = {0,1,0,-1};
		struct node * ch ;
		for(i =0; i<4; i++){
			if( isSafe(arr ,row[i],col[i],deadque,*top2) == 1){
			 	ch = newnode(row[i],col[i],tt);
            	ch->cost = calculateCost(ch->child, final);
				enqueue(que,ch,top);
			}
		}
	}
    return 0;
}
int solve(int board[3][3],	int final[3][3]){

	struct node *root = (struct node *) malloc(sizeof(struct node ));
	int i,j;
	for(i =0; i<3; i++){
		for(j =0; j <3; j++){
			root->child[i][j] = board[i][j];
			if(board[i][j] == 0){
				root->x = i;
				root->y = j;
			}
		}
	}
	root->parent = NULL;
	root->level = 0;
	root->cost = calculateCost(board,final);
	struct node *que[1000],*deadque[500];
	int top=-1,top2=-1;
	enqueue(que,root,&top);

	if(solve3QUtil(que,deadque,final,&top,&top2) == 1)
		return 1;
	return 0;
}
int main(){
  	int board[3][3] = {0};
	int final[3][3];
 	int i,j;
	for(i  =0;i<3; i++){
		for(j =0; j<3; j++){
			scanf("%d",&board[i][j]);
		}
	}
	for(i =0;i<3; i++){
		for(j =0; j<3; j++){
			scanf("%d",&final[i][j]);
		}
	}
	
    if ( solve(board,final) == 0 ){
   		printf("Solution does not exist");
      	return 0;
	}
	//printSolution(board);
    return 0;
}

