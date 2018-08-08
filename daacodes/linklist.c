#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *next;
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

struct node *reverse(struct node* head_ref) {
   struct node* prev   = NULL;
   struct node* current = head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   head_ref = prev;
   return head_ref;
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
      if(current->next == NULL) {
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
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}
struct node *newnode(int key){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->next = NULL;
	p->key = key;
	return p;
}

struct node *insertbegin(struct node * root,int key){
	struct node*p = newnode(key);
	p->next = root;
	root=p;
	return root;
}
struct node *insertend(struct node * root,int key){
	struct node*p = newnode(key),*q = root;
	while(q->next )
		q=q->next;
	q->next =p;
	return root;
}

