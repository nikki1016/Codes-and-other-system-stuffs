#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define N 3
using namespace std;
struct Node
{
	Node* parent; 
	int mat[N][N];    
	int x, y;
	int cost;
	int level;
};

int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i+1; j < 9; j++)
			// Value 0 is used for empty space
			if (arr[j] && arr[i] &&  arr[i] > arr[j])
				inv_count++;
	return inv_count;
}
int printMatrix(int mat[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}
Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent)
{
	Node* node = new Node;
	node->parent = parent;
	memcpy(node->mat, mat, sizeof node->mat);
	swap(node->mat[x][y], node->mat[newX][newY]);
	node->cost = INT_MAX;
	node->level = level;
	node->x = newX;
	node->y = newY;
	return node;
}
int movl[] = { 1, 0, -1, 0 };
int movr[] = { 0, -1, 0, 1 };


int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (initial[i][j] && initial[i][j] != final[i][j])
				count++;
	return count;
}
int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}
void printPath(Node* root)
{
	if (root == NULL)
		return;
	printPath(root->parent);
	printMatrix(root->mat);

	printf("\n");
}

struct comp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};


void Mainsolve(int initial[N][N], int x, int y, int final[N][N])
{

	priority_queue<Node*, std::vector<Node*>, comp> pq;
	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);
	pq.push(root);
	while (!pq.empty())
	{   
		Node* min = pq.top();
		pq.pop();
		if (min->cost == 0)
		{

			printPath(min);
			return;
		}


		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + movl[i], min->y + movr[i]))
			{

				Node* child = newNode(min->mat, min->x,
						min->y, min->x + movl[i],
						min->y + movr[i],
						min->level + 1, min);
				child->cost = calculateCost(child->mat, final);


				pq.push(child);
			}
		}
	}
}



void solve(int **);
int main()
{
	int i,**board;
	board = (int **)malloc(3*sizeof(int *));
	board[0] = (int *)malloc(3*sizeof(int));
	board[1] = (int *)malloc(3*sizeof(int));
	board[2] = (int *)malloc(3*sizeof(int));
	for(i=0;i<3;i=i+1) {
		scanf("%d%d%d",&board[i][0],&board[i][1],&board[i][2]);
	}
	solve(board);
	return 0;
}

void solve(int **board)
{
	int i,j,x,y;
	int final[N][N];
	for(i=0;i<3;i=i+1) 
		for(j=0;j<3;j++)
			final[i][j]=3*i+j; 
	int initial[N][N];
	for(i=0;i<3;i=i+1) {
		for(j=0;j<3;j++) {
			if(board[i][j]==0) {
				x=i;
				y=j;
			}
			initial[i][j]=board[i][j];
		}	

	}
	int k=0,arr[9];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			arr[k++]=initial[i][j];
	int c=getInvCount( arr);
	if(c%2)
	{
		printf("Cant solve\n");
		return ;
	}

	Mainsolve(initial,x,y,final);

}
