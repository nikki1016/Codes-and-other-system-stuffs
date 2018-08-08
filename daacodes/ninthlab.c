// Program to print path from root node to destination node
// for N*N -1 puzzle algorithm using Branch and Bound
// The solution assumes that instance of puzzle is solvable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT_MAX 9999999
#define N 3

// state space tree nodes
struct Node
{
	// stores parent node of current node
	// helps in tracing path when answer is found
	struct Node* parent;

	// stores matrix
	int mat[N][N];

	// stores blank tile cordinates
	int x, y;

	// stores the number of misplaced tiles
	int cost;

	// stores the number of moves so far
	int level;
};

// Function to print N x N matrix
int printMatrix(int mat[N][N])
{
    int i, j;
	for ( i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

void memcpy1(int m1[][3], int m2[][3]) {
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            m1[i][j]=m2[i][j];
                
}

// Function to allocate a new node
struct Node* newNode(int mat[N][N], int x, int y, int newX,
			int newY, int level,struct Node* parent)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));

	// set pointer for path to root
	node->parent = parent;

	// copy data from parent node to current node
	memcpy1(node->mat, mat);

	// move tile by 1 postion
	int p=node->mat[x][y];
	node->mat[x][y] = node->mat[newX][newY];
	node->mat[newX][newY]=p;

	// set number of misplaced tiles
	node->cost = INT_MAX;

	// set number of moves so far
	node->level = level;

	// update new blank tile cordinates
	node->x = newX;
	node->y = newY;

	return node;
}

// botton, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the the number of misplaced tiles
// ie. number of non-blank tiles not in their goal position
int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0, i , j;
	for (i = 0; i < N; i++)
	for ( j = 0; j < N; j++)
		if (initial[i][j] && initial[i][j] != final[i][j])
		count++;
	return count;
}

// Function to check if (x, y) is a valid matrix cordinate
int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

// print path from root node to destination node
void printPath(struct Node* root)
{
	if (root == NULL)
		return;
	printPath(root->parent);
	printMatrix(root->mat);

	printf("\n");
}


int eq(int m1[][3],int m2[][3]) {
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(m1[i][j]!=m2[i][j])
                return 0;
    return 1;
}

int funct(int m[3][3],struct Node* arr[], int i) {
    int j;
    for(j=0; j<i; j++) {
        if(eq(m,arr[j]->mat)==1)
            return 1;
    }
    return 0;
}

void sort(struct Node *pri[], int n) {
    int i,j, flag;
    for(i=0; i<n-1; i++) {
        flag=0;
        for(j=i+1; j<n; j++) {
            if((pri[i]->cost)+(pri[i]->level) < (pri[j]->cost)+(pri[j]->level)) {
                struct Node * temp=pri[i];
                pri[i]=pri[j];
                pri[j]=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}

void enque(struct Node *root, struct Node *pri[], int *a) {
    pri[(*a)++]=root;
    sort(pri, *a);
}

struct Node * deque(struct Node *pri[], int *a) {
    struct Node *temp=pri[(*a)-1];
    (*a)--;
    return temp;
}

// Function to solve N*N - 1 puzzle algorithm using
// Branch and Bound. x and y are blank tile coordinates
// in initial state
void solve(int initial[N][N], int x, int y,
		int final[N][N])
{
	// Create a priority queue to store live nodes of
	// search tree;
	struct Node * pri[100000];
	int ind=0;

	// create a root node and calculate its cost
	struct Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);
    struct Node * arr[10000];
    int index=0;
    
	// Add root to list of live nodes;
	enque(root, pri, &ind);
	
    arr[index++]=root;
	// Finds a live node with least cost,
	// add its childrens to list of live nodes and
	// finally deletes it from the list.
	while (ind!=0)
	{
		// Find a live node with least estimated cost
		struct Node* min = deque(pri, &ind);

		// The found node is deleted from the list of
		// live nodes
		arr[index++]=min;

		// if min is an answer node
		if (min->cost == 0)
		{
			// print the path from root to destination;
			printPath(min);
			return;
		}

		// do for each child of min
		// max 4 children for a node
		int i;
		for (i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{
				// create a child node and calculate
				// its cost
				struct Node* child = newNode(min->mat, min->x,
							min->y, min->x + row[i],
							min->y + col[i],
							min->level + 1, min);
				child->cost = calculateCost(child->mat, final);
                if(funct(child->mat, arr, index)==0) {
				// Add child to list of live nodes
				    enque(child, pri, &ind);
				    printf("Hi! I am at level %d with cost %d\n", child->level, child->level + child->cost);
                }
			}
		}
	}
}

// Driver code
int main()
{
	// Initial configuration
	// Value 0 is used for empty space
	int initial[N][N] =
	{
		{1, 2, 3},
		{5, 6, 0},
		{7, 8, 4}
	};

	// Solvable Final configuration
	// Value 0 is used for empty space
	int final[N][N] =
	{
		{1, 2, 3},
		{5, 8, 6},
		{0, 7, 4}
	};

	// Blank tile coordinates in initial
	// configuration
	int x = 1, y = 2;

	solve(initial, x, y, final);

	return 0;
}

