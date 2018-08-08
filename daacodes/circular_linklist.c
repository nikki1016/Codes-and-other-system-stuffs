#include<stdio.h>
#include<stdlib.h>
struct node
{
    	int key;
    	struct node *next;
	struct node *prev; 
};

struct node* sort(struct node *head) {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
	
   for ( i = 0 ; current; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; next ; j++ ) {   
		
         if ( current->key > next->key ) {
            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
         next = next->next;
      }
      current = current->next;
   } 
   return head;  
}

struct node* find(int key,struct node *head) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == head) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(int key,struct node * head) {

   	//start from the first link
   	struct node* current = head;
	
   //if list is empty
   	if(head == NULL) 
      		return NULL;
	//only one node with the same value as that of node to be deleted
	if(head->key == key && head->next == head){
		free(head);
		return NULL;
	} 
   	//navigate through list
   	while(current->key != key) {

      		//if it is last node and not found key
      		if(current->next == head)
       			return NULL; 
       		current = current->next;
   	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
   	free(current);
   	return head;
}

struct node *newnode(int key){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->next = p->prev = p;
	p->key = key;
	return p;
}

struct node *insertbegin(struct node * root,int key){
	struct node*p = newnode(key);
	p->next = root;
	p->prev = root->prev;
	root->prev =p;
	root = p;
	return root;
}
struct node *insertend(struct node * root,int key){
	struct node*p = newnode(key),*q = root->prev;
	p->prev = q;
	p->next = q->next;
	q->next =p;
	return root;
}

