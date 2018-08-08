#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int matrix[3][3];
	struct node *next;
	struct node *parent;
};

struct node* enqueue(struct node *head,struct node *tail,struct node *p)
{
	if(head==NULL&&tail==NULL)
	{
		head=p;
		tail=p;
	}
	else
	{
		tail->next=p;
		tail=p;
	}
	return head;
}

struct node* dequeue(struct node *head,struct node *tail)
{
	if(head==NULL)
	{
		tail=NULL;
		return NULL;
	}
	else
	{
		struct node *p=head ;//(struct node *)malloc(sizeof(struct node));
		//p=head;
		head=head->next;
		return p;
	}
}

void push(struct node *top,struct node *p)
{
	if(top==NULL)
	{
		top=p;
		top->next=NULL;
	}
	else
	{
		p->next=top;
		top=p;
	}
}

struct node * pop(struct node *top)
{
	if(top==NULL)
	{
		return NULL;
	}
	struct node *temp=top;
	top=top->next;
	return temp;
}

int assign(struct node *t,long int hash[],int *now)
{
	long int x=0;
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			x=x*10+t->matrix[i][j];
		}
	}
	int flag=0;
	for(i=0;i< *now;i++)
	{
		if(hash[i]==x)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		hash[(*now)++]=x;
	}
	else
	{
		return 0;
	}
}

void store(struct node *head,struct node *tail,struct node *p,long int hash[],int *now)
{
	int i,j,x,y;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(p->matrix[i][j]==0)
			{
				x=i;
				y=j;
			}
		}
	}
	if(x>0)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				temp->matrix[i][j]=p->matrix[i][j];
			}
		}
		int t;
		t=temp->matrix[x][y];
		temp->matrix[x][y]=temp->matrix[x-1][y];
		temp->matrix[x-1][y]=t;
		temp->next=NULL;
		temp->parent=p;
		if(assign(temp,hash,now))
		{
			head = enqueue(head,tail,temp);
		}
	}
	if(x<2)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				temp->matrix[i][j]=p->matrix[i][j];
			}
		}
		int t;
		t=temp->matrix[x][y];
		temp->matrix[x][y]=temp->matrix[x+1][y];
		temp->matrix[x+1][y]=t;
		temp->next=NULL;
		temp->parent=p;
		if(assign(temp,hash,now))
		{
			head = enqueue(head,tail,temp);
		}
	}
	if(y>0)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				temp->matrix[i][j]=p->matrix[i][j];
			}
		}
		int t;
		t=temp->matrix[x][y];
		temp->matrix[x][y]=temp->matrix[x][y-1];
		temp->matrix[x][y-1]=t;
		temp->next=NULL;
		temp->parent=p;
		if(assign(temp,hash,now))
		{
			head = enqueue(head,tail,temp);
		}
	}
	if(y<2)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				temp->matrix[i][j]=p->matrix[i][j];
			}
		}
		int t;
		t=temp->matrix[x][y];
		temp->matrix[x][y]=temp->matrix[x][y+1];
		temp->matrix[x][y+1]=t;
		temp->next=NULL;
		temp->parent=p;
		if(assign(temp,hash,now))
		{
			head= enqueue(head,tail,temp);
		}
	}
}

int check(struct node *p, struct node *target,struct node *answer)
{
	int flag=0;
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(p->matrix[i][j]!=target->matrix[i][j])
			{
				flag=1;
			}
		}
	}
	if(flag==0)
	{
		answer=p;
		return 0;
	}
	return 1;
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
	printSolution(tt->matrix);
}
//void solve(int board[3][3],int final[3][3]){
void solve(struct node*start,struct node * target){
		printf("Enter the t:\n");
	struct node *head=NULL,*tail=NULL,*answer=NULL,*top=NULL;
	long int hash[2000000];
	int now=0;
	int i,j;
	/*struct node *start=(struct node *)malloc(sizeof(struct node));
	struct node *target=(struct node *)malloc(sizeof(struct node));

	for(i =0; i<3; i++){
		for(j =0; j<3; j++){
			start->matrix[i][j] = board[i][j];
			target->matrix[i][j] = final[i][j];
		}
	}
		printf("Enter the target:\n");
	start->next=NULL;
	start->parent=NULL;
	target->next=NULL;
	target->parent=NULL;*/
	printSolution(start->matrix);
	printSolution(target->matrix);
	head = enqueue(head,tail,start);
	int r=assign(start,hash,&now);
	struct node *p=head;
	while(p!=NULL)
	{
		if(check(p,target,answer))
			store(head,tail,p,hash,&now);
		else
			break;
		p=dequeue(head,tail);
	}
	printf("\n");
	if(answer!=NULL)
	{
		p=answer;
		while(p!=NULL)
		{
			push(top,p);
			p=p->parent;
		}
		printf("From source to destination:\n");
		p=pop(top);
		while(p!=NULL)
		{
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					printf("%d ",p->matrix[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			p=pop(top);
		}
	}
	else
	{
		printf("Unsolvable.\n");
	}

	/*printf("\n");
	if(answer!=NULL)
	{
		printpath(answer);
	}
	else
	{
		printf("Unsolvable.\n");
	}*/
}
int main()
{
	/*int board[3][3],final[3][3];
	int i,j;
	printf("Enter the source:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	printf("Enter the target:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&final[i][j]);
		}
	}
	solve(board,final);*/
	struct node *start=(struct node *)malloc(sizeof(struct node));
	struct node *target=(struct node *)malloc(sizeof(struct node));
	int i,j;
	printf("Enter the source:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&(start->matrix[i][j]));
		}
	}
	printf("Enter the target:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&(target->matrix[i][j]));
		}
	}
	start->next=NULL;
	start->parent=NULL;
	target->next=NULL;
	target->parent=NULL;
	printSolution(start->matrix);
	printSolution(target->matrix);
	solve(start,target);
	return 0;
}
