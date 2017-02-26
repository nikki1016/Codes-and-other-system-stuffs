#include <stdio.h>
#include<stdlib.h>
struct link {
	char info;
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
int hash(char a);
void display (struct link *start[]){
	int i;
	struct link *tmp;
	for(i = 0; i<26; i++){
		tmp = start[i];
		while(tmp != NULL){
			printf("%c ->",tmp->info);
			tmp = tmp->next;
		}
		if(start[i] != NULL){
			printf(" NULL -> %d\n",count(start[i]));
		}
	}
}

struct link *insert (char letter, struct link *start){
	struct link *tmp;
	tmp = (struct link *)malloc(sizeof(struct link));
	tmp->info = letter;
	tmp->next = start;
	start = tmp;
//	printf("hi\n");
	return start;
}
struct link *delete(char letter, struct link *start){
	struct link *tmp = start;
	start = tmp->next;
//	printf("hi\n");
	free(tmp);
	return start;
}
int hash(char a){
	int i;
	if( a>='A' && a<='Z')
		i = (a- 'A')%26;
	else if( a>='a' && a<='z')
		i = (a- 'a')%26;
	return i;
}
int main(){
	struct link *start[26];
	char letter[100],ch;
	int i,n,j,k;
	for(i =0; i<26; i++){
		start[i] = NULL;
	}
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%s",letter);	
		for(k =0; letter[k] != '\0'; k++){
			j = hash(letter[k]);
			start[j] = insert(letter[k], start[j]);
		}
	}
	display(start);
	getch();
	scanf("%c",&ch);
	start[hash(ch)] = delete(ch,start[hash(ch)]);
	display(start);
	return 0;
}
