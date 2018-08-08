#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int matrix[3][3];
	struct node *next;
	struct node *parent;
}*head=NULL,*tail=NULL,*answer=NULL,*top=NULL;
long int hash[2000000];
int now=0;

void enqueue(struct node *p)
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
}

struct node* dequeue()
{
	if(head==NULL)
	{
		tail=NULL;
		return NULL;
	}
	else
	{
		struct node *p=(struct node *)malloc(sizeof(struct node));
		p=head;
		head=head->next;
		return p;
	}
}

void push(struct node *p)
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

struct node * pop()
{
	if(top==NULL)
	{
		return NULL;
	}
	struct node *temp=top;
	top=top->next;
	return temp;
}

int assign(struct node *t)
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
	for(i=0;i<now;i++)
	{
		if(hash[i]==x)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		hash[now++]=x;
	}
	else
	{
		return 0;
	}
}

void store(struct node *p)
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
		if(assign(temp))
		{
			enqueue(temp);
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
		if(assign(temp))
		{
			enqueue(temp);
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
		if(assign(temp))
		{
			enqueue(temp);
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
		if(assign(temp))
		{
			enqueue(temp);
		}
	}
}

int check(struct node *p, struct node *target)
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

int main()
{
	struct node *start=(struct node *)malloc(sizeof(struct node));
	struct node *target=(struct node *)malloc(sizeof(struct node));
	int i,j;
	printf("Enter the source:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&start->matrix[i][j]);
		}
	}
	printf("Enter the target:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&target->matrix[i][j]);
		}
	}
	start->next=NULL;
	start->parent=NULL;
	target->next=NULL;
	target->parent=NULL;
	enqueue(start);
	int r=assign(start);
	struct node *p=head;
	while(p!=NULL)
	{
		if(check(p,target))
			store(p);
		else
			break;
		p=dequeue();
	}
	printf("\n");
	if(answer!=NULL)
	{
		p=answer;
		while(p!=NULL)
		{
			push(p);
			p=p->parent;
		}
		printf("From source to destination:\n");
		p=pop();
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
			p=pop();
		}
	}
	else
	{
		printf("Unsolvable.\n");
	}
	return 0;
}
