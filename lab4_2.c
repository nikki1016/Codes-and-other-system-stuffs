#include <stdio.h>
#include<stdlib.h>
struct link {
	int info;
	struct link *next;
};
int count(struct link *tmp){
	int c = 0;
	while(tmp!= NULL){
		c++;
		tmp = tmp->next;
	}
	return c;
}
int hash(int a);
void display (struct link *start[]){
	int i;
	struct link *tmp;
	for(i = 0; i<11; i++){
		tmp = start[i];
		if(tmp != NULL){
			printf)("%d   :  ",i);
			while(tmp != NULL){
				printf("%d ->",tmp->info);
				tmp= tmp->next;
		//		printf("%d\n",count(tmp));
			}
			printf("\n");
		}
	}
}
int search(struct link *start,int data){
	struct link *ptr = start;
	while(ptr!= NULL){
		if(ptr->info == data)
			return 1;
		ptr= ptr->next;
	}
	return 0;
}
struct link *insert (int letter, struct link *start){
	struct link *tmp;
	tmp = (struct link *)malloc(sizeof(struct link));
	tmp->info = letter;
	tmp->next = start;
	start = tmp;
//	printf("hi\n");
	return start;
}

int hash(int  a){
	int i;
	i = a % 11;
	return i;
}
int main(){
	struct link *start[11];
	int  letter;
	int i,n,j,k;
	for(i =0; i<11; i++){
		start[i] = NULL;
	}
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&letter);	
		j = hash(letter);
		if(!search(start[j],letter))
			start[j] = insert(letter, start[j]);
	}
	display(start);
	return 0;
}
