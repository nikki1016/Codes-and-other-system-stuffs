#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct node {
	struct node *next;
	int wo;
};
struct hash {
	struct hash *next;
	struct node *link;
	int data;
};
struct tree *newnode(struct tree *p,int data){
	p = (struct tree *)malloc(sizeof(struct tree));
	p->info = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
struct tree *insert(struct tree * start, int data){
	struct tree *tmp;
	if(start ==  NULL){
		tmp = (struct tree *)malloc(sizeof(struct tree));
		tmp->info = data;
		tmp->left = NULL;
		tmp->right = NULL;
		start = tmp;
		return start;
	}
	if(data > start->info)
		start->right = insert(start->right ,data);
	else if(start->info >data)
		start->left = insert(start->left,data);
	return start;
}
void inorder(struct tree *start){
	if(start != NULL){
		inorder(start->left);
		printf("%d -> ",start->info);
		inorder(start->right);
	}
}	
struct hash *search(struct hash *table,int n){
	struct hash *p = table;
	while(p != NULL){	
		if(p->data ==  n){
			return p;
		}
		p = p->next;
	}
	return p;
}
struct hash *vertical_order(struct tree *start, struct hash *table,int n){
	if(start == NULL)   return table;
//printf("hii\n");
	struct hash *tmp,*p = table;
	struct node *ptr,*pp;
	pp = (struct node *)malloc(sizeof(struct node));
	pp->wo = start->info;
	pp->next = NULL;
	tmp = search(table,n);
//printf("tmp->\n");
	if(tmp == NULL){
		tmp = (struct hash *)malloc(sizeof(struct hash));
		tmp->data = n;
		tmp->link = pp;
		tmp->next = NULL;
		if(table == NULL || table->data > n){
			tmp->next = table;
			table = tmp;

		}
		else {
			p = table;
			while(p->next != NULL){	
				if(p->next->data > n){
					tmp->next = p->next;
					p->next = tmp;
					break;
				}
				p = p->next;
			}
			if(p->next == NULL){
				tmp->next = p->next;
				p->next = tmp;
			}
		}
	}
	else {
	//printf("%d\n",tmp->data);
		ptr = tmp->link;
		while(ptr->next != NULL)
			ptr= ptr->next;
		ptr->next = pp;
	}//printf("hiilo\n");
	table = vertical_order(start->left,table,n-1);
	//printf("lllmo\n");
	table = vertical_order(start->right,table,n+1);
	return table;
}
void display(struct hash *table){
	struct hash *p = table;
	struct node *ptr;
	while(p != NULL){
		//printf("%d---",p->data);
		ptr = p->link;
		while(ptr != NULL){
			printf("%d  ",ptr->wo);
			ptr = ptr->next;
		}
		printf("\n");
		p = p->next;
	}
}		
int main(){
	struct hash *table = NULL,*p;
	/*struct tree *root = newnode(root,1);
    root->left = newnode(root->left,2);
    root->right = newnode(root->right,3);
    root->left->left = newnode(root->left->left,4);
    root->left->right = newnode( root->left->right,5);
    root->right->left = newnode( root->right->left,6);
    root->right->right = newnode(root->right->right,7);
    root->right->left->right = newnode(root->right->left->right,8);
    root->right->right->right = newnode( root->right->right->right,9);
	inorder(root);
	printf("\n");
	//p = search(table,n);


	table = vertical_order(root,table,0);
	display(table);
    return 0;*/
	struct tree *start = NULL;
	int i,j,n,data;
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&data);
		start = insert(start,data);
	}
	inorder(start);
	printf("\n");
	table = vertical_order(start,table,0);
	display(table);
	return 0;
}
