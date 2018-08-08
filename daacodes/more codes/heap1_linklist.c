#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *parent,*left,*right;
	int data;
};
struct queue{
	struct node * pp;
};

void enqueue(struct node *root,struct queue q[],int *f,int *r){
	(*r)= ((*r) + 1)%100;
	q[*r].pp = root;
	if(*f == -1) (*f)++;
}
void en_first(struct node *root,struct queue q[],int *f,int *r){
	if(*f == -1) {
		(*r)++;
		(*f)+= 2;
	}
	(*f)= ((*f) - 1)%100;
	q[*f].pp = root;
}

struct node *dequeue(struct queue q[],int *f,int *r){
	struct node *t = q[*f].pp;
	if((*f) == *r) 
		*f = *r = -1;
	else
		(*f) = ((*f)+1)%100;
	return t;
}
struct node *de_last(struct queue q[],int *f,int *r){
	if(*r == -1) return NULL;
	struct node *t = q[*r].pp;
	if((*f) == *r) 
		*f = *r = -1;
	else
		(*r) = ((*r)-1)%100;
	return t;
}
struct node *front(struct queue *q,int *f){
	return q[*f].pp;
}
struct node *max_heapify(struct node *ss){
	if(ss == NULL) return ss;
	int dd = ss->data,i = ss->data;
	//printf("r %d -- ",dd);
	if(ss->left != NULL && ss->data < ss->left->data){
		dd= ss->left->data;
	}
	if(ss->right != NULL && dd < ss->right->data){
		dd = ss->right->data;
	}
	if(ss->data != dd){
		ss->data = dd;
		if(ss->left->data == dd){
			ss->left->data = i;
			ss->left = max_heapify(ss->left);
		}
		else{
			ss->right->data = i;
			ss->right = max_heapify(ss->right);
		}
	}
	return ss;
}
struct node *insert(struct node *root,int b,struct queue q[],int *f,int *r){
	if(root == NULL){
		root = (struct node *)malloc(sizeof(struct node));
		root->data = b;
		root->left = root->right = root->parent = NULL; 
		enqueue(root,q,f,r);
		return root;
	}

	struct node *z = front(q,f);

	if(z->left == NULL){
		z->left = (struct node *)malloc(sizeof(struct node));
		z->left->data = b;
		z->left->left = z->left->right = NULL;
		z->left->parent = z;
		enqueue(z->left,q,f,r);
		z=z->left;
	}
	else if(z->right == NULL){
		z->right = (struct node *)malloc(sizeof(struct node));
		z->right->data = b;
		z->right->left = z->right->right = NULL;
		z->right->parent = z;
		enqueue(z->right,q,f,r);
		struct node *tt=NULL;
		tt=dequeue(q,f,r);
		z=z->right;
	}
	while(z->parent != NULL){
		if(z->parent->data < z->data){
			z->data = z->parent->data;
			z->parent->data = b;
			z=z->parent;
		}
		else break;
	}
	return root;
}

struct node *delete(struct node *root,struct queue q[],int *f,int *r){
	if(root == NULL){
		return root;
	}
	//printf("ggg1\n");
	if(*r ==-1 && *f == -1) {	
		root = NULL;
		return root;
	}
	/*struct node *kk = q[*r].pp;
	 (*r) = ((*r)-1)%100;
	if(*r ==-1 ) 
		*f == -1;*/
	struct node *kk = de_last(q,f,r);
	//printf("last element %d-:",kk->data);
	int i = root->data;
	root->data = kk->data;
	kk->data = i;
	//printf("ggg %d\n",i);
	if(kk->parent == NULL) root=NULL;
	else if(kk->parent->left == kk) kk->parent->left = NULL;
	else {
		kk->parent->right = NULL;
		en_first(kk->parent,q,f,r);
	}
	free(kk);
	root = max_heapify(root);
	return root;
}

int ex_max(struct node * root){
	return root->data;
}

void display(struct node *root){
	if(root== NULL) return;
	struct queue q2[100];
	int f1=-1,r1=-1;
	enqueue(root,q2,&f1,&r1);
	while(r1 != -1 && f1 != -1){
		struct node * tt = dequeue(q2,&f1,&r1);
		printf("%d ",tt->data);
		if(tt->left != NULL)
			enqueue(tt->left,q2,&f1,&r1);
		if(tt->right != NULL) 	
			enqueue(tt->right,q2,&f1,&r1);
	}
}
int count(struct node *root){
	if(root== NULL) return 0;
	struct queue q2[100];
	int f1=-1,r1=-1, c=0;
	enqueue(root,q2,&f1,&r1);
	while(r1 != -1 && f1 != -1){
		struct node * tt = dequeue(q2,&f1,&r1);
		c++;
		if(tt->left != NULL)
			enqueue(tt->left,q2,&f1,&r1);
		if(tt->right != NULL) 	
			enqueue(tt->right,q2,&f1,&r1);
	}
	return c;
}
void heapsort(struct node *root,int arr[],int n,struct queue q[],int *f,int *r){
	int i;
	for(i = n-1;i>=0;i--){
		arr[i] = root->data;
		root = delete(root,q,f,r);
	}
}

int main(){
	int i,j,n,a,b,max,w=0;
	int f=-1,r=-1,arr[100];
	struct node *root=NULL;
	struct queue q[100];
	while(1){
		printf("what to want -- 1.Insert ,2.Delete ,3.Build heap ,4.extrct max, 5. display heap\n");
		scanf("%d",&a);
		switch(a){
			case 1: scanf("%d",&b);
				root=insert(root,b,q,&f,&r);
				display(root);
				printf("\n");
			//	root=increase(root);
				break;
			case 2 : //scanf("%d",&b);
				 root = delete(root,q,&f,&r);
				display(root);
				printf("\n");
				 break;
			case 3 : scanf("%d",&n);
				root = NULL;
				 for(i=0;i<n;i++){
					 scanf("%d",&b);
					 root=insert(root,b,q,&f,&r);
			//	 	 root = increase(root);
				 }
				display(root);
				printf("\n");
				 break;
			case 4 :max = ex_max(root);
				printf("%d is max\n",max);
				break;
			case 5: display(root);
				break;
			case 6: n = count(root);
				heapsort(root,arr,n,q,&f,&r);
				printf("sorted heap\n");
				for(i =0;i<n;i++)
					printf("%d ",arr[i]);
				break;
			default : return 0;
		}
	}
	return  0;
}


