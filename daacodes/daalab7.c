# include <stdio.h>
# include <stdlib.h>
#include <math.h>
#define len(x) ((int)log10(x)+1)

struct node {
	struct node *left,*right;
  	char data;
};
int isLeaf(struct node* root)
{
    return !(root->left) && !(root->right) ;
}

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     printf(" %c\n",node->data);  
 
     /* then recur on left sutree */
     printPreorder(node->left);  
 
     /* now recur on right subtree */
     printPreorder(node->right);
}  

int countDistinct(FILE *fp)
{
  int n=0;
  /* Count the total number of distinct characters in the file */
  int c,k;
  int count[256]={0};

  /* for as long as we can get characters... */
  while((c=fgetc(fp))) {

    /* break if end of file */
    if(c == EOF) break;

    /* otherwise add one to the count of that particular character */
    count[c]+=1;
  }

  /* now print the results; only if the count is different from
   * zero */
  for(k=0; k<256; k++) {
    if(count[k] > 0) {
      n++;
    }
  }
  return n;
}

void collectFrequency(FILE *fp,int **frequency,int n)
{
  	/* Count the total number of distinct characters in the file */
  	int c,k;
  	int count[256]={0};

  	/* for as long as we can get characters... */
  	while((c=fgetc(fp)) != EOF) {
    		count[c]+=1;
  	}

  /* now print the results; only if the count is different from
   * zero */
	int i = 0;
  	for(k=0; k<256; k++) {
    		if(count[k] > 0) {
      			frequency[i][0] = k;
			frequency[i][1] = count[k];
		    	printf("%d  -  %c %d\n",i,frequency[i][0],frequency[i][1]);
			i++;
    		}
  	}

	
  /*
    You need to figure out how many times each character appears in the file. For this we will use hash table.

    create a proper hash function by looking at the file and use the frequency array as a hash table.
    For collision and it's resolution, we allow two cells at every position of the hash table.
    The first cell will contain the ascii code of the character and the second cell will contain the frequency of that character.
  */
}
void minheapify(char ch[],int** a, int j, int n){
	int temp;
	char tmp;
	int largest = j,i;
	int p = 2*j +1;
	int q = p+1;
	while(j < n){
		if ( p < n && a[p][1] < a[largest][1]) 
			largest = p;
			
		else if ( q < n && a[q][1] < a[largest][1]) 
			largest = q;

		if (largest != j) {
		    	temp = a[j][1];
		   	a[j][1] = a[largest][1];
		    	a[largest][1] = temp;

			tmp = a[j][0];
		   	a[j][0] = a[largest][0];
		    	a[largest][0] = tmp;

			tmp = ch[j];
		   	ch[j] = ch[largest];
		    	ch[largest] = tmp;
		    	j = largest;
			p = 2*j+1;
			q = p+1;
		}
		else return;
	}

}

char extractMin(char arr[],int **freq,int *n)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	if(*n==0) return -1;
	(*n)--;
	char temp = arr[0];
	arr[0] = arr[*n];
	int k = freq[0][1];
	freq[0][1] = freq[*n][1];
	temp = freq[0][0];
	freq[0][0] = freq[*n][0];
	minheapify(arr,freq,0,*n);
	return temp;
}
void buildMinHeap(char *heap, int **frequency, int n)
{
	int i;
	for(i = 0 ; i <n; i++){
		heap[i] = (char)(frequency[i][0]);
	}
	int j = (n/2)-1;
	for( ; j>=0; j--){
		minheapify(heap,frequency,j,n);
	}	
	
  /* 
     This is exactly sint calFreq(int ** frequency, char c,int n){imilar to the buil_max_heap that you have created in previous lab assignment with the following difference:
     In heap you store the characters, but unlike previous implementation the comaprison between different characters are not by their ASCII but by their frequency.
     You should use the same hash function to look for the frequency of the specific character
  */
}
void insert(char * heap,int **frequency,int *n,char c,int val){
	heap[*n] = c;
	frequency[*n][0] = c;
	frequency[*n][1] = val;
	//(*n)++;
	int pos = *n;
	while(pos > 0 && frequency[(pos-1)/2][1] > frequency[pos][1]){
		int y = frequency[pos][1];
		frequency[pos][1]=  frequency[(pos-1)/2][1];
		frequency[(pos-1)/2][1] = y;

		char t = frequency[(pos-1)/2][0];
		frequency[(pos-1)/2][0] = frequency[pos][0];
		frequency[pos][0] = t;
		
		t = heap[pos];
		heap[pos] = heap[(pos-1)/2];
		heap[(pos-1)/2] = t;

		pos = (pos-1)/2;
	}
	(*n)++;

}
struct node * constructHuffman(char *heap, int **frequency, int n, struct node *huffman)
{
	int i,j,f,g;
	struct node **heaptree = (struct node **)malloc(n*sizeof(struct node *));;

	int hs = n,k;
	for(i = 0 ; i<hs ; i++){
		heaptree[i] = (struct node *)malloc(sizeof(struct node));
		heaptree[i]->data = heap[i];
		heaptree[i]->left = heaptree[i]->right = NULL;
	}
	char ch1,ch2;
	while (hs != 1){    
		struct node *top =(struct node *)malloc(sizeof(struct node));
		int c1 = frequency[0][1];
		ch1 = extractMin(heap,frequency,&hs);
		int c2 = frequency[0][1];
		ch2 = extractMin(heap,frequency,&hs);
		printf("ch1- %c  c1-  %d    ch2- %c     c2- %d\n",ch1,c1,ch2,c2);
		for(j=0;j<hs;j++){
		//	printf("%c %d\n",frequency[j][0],frequency[j][1]);
		}
		for(i =0; i<n;i++){
			if(heaptree[i])
				printf("1  %d  %c hrerr\n",i,heaptree[i]->data);
			if(heaptree[i] && heaptree[i]->data == ch1)
				f = i;
			if(heaptree[i] && heaptree[i]->data == ch2)
				g = i;
		}
				//printf("n %d      f  %d g %d hrerr\n",n,f,g);
        	top->data = ch1;
        	top->left = heaptree[f];
        	top->right = heaptree[g];
		heaptree[f] = top;
		heaptree[g] = NULL;
        	insert(heap,frequency,&hs,ch1,c1+c2);
		for(j=0;j<hs;j++){
			printf("heap   %c %d\n",frequency[j][0],frequency[j][1]);
		}
    	}
 	for(i =0; i<n;i++){
		if(heaptree[i])
			return heaptree[i];
	}
  /*
    Construct the huffman tree from the given heap.
    Note that you may need to change the heap while contruction (deletion, insertion). Please import the appropriate function written in previous classes.
    Also, note that, you may need to store frequency of new elements that are not there in the file and thus in the array fequency.
    For this you may change the content of the array frequency correctly and figure out a way to store the frequency of tree nodes in the array.
    Otherwise you may use your own data structure
  */
}
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
void printCodes(struct node* root, int arr[], int top)
{

    if (root->left)
    {
        arr[top] = 1;
        printCodes(root->left, arr, top + 1);
    }
 
    if (root->right)
    {
        arr[top] = 0;
        printCodes(root->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void findCodes(struct node* root, int arr[], int top,char c,int *t)
{
	if(root == NULL) return;
    if (root->left)
    {
        arr[top] = 1;
        findCodes(root->left, arr, top+1,c,t);
    }
 
    if (root->right)
    {
        arr[top] = 0;
        findCodes(root->right, arr,top +1,c,t);
    }
 //printf("hittt\n");
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
   if (root->left == NULL && root->right == NULL && root->data == c )
    {
	*t = 0;
	int i;
        //printf("   find   %c: ", root->data);
	arr[top+1] = 22;
	for(i = top-1 ; i>=0; i--)
		*t = (*t) * 10 + arr[i] +1;
//		*t = (*t << 1) | arr[i];
	//printf("t %d\n",*t);   
      //  printArr(arr, top);
	return;
    }
	
}
void encode(FILE *fip,FILE *fop,struct node *huffman,int n)
{
	char c;	
	//printCodechar(huffman, arr, top,n);	
	char bit=0,s, x = 0;
    	int i=0,j=0;
	while ((c=fgetc(fip)) != EOF){
		int brr[100],top=0,t=0;
		findCodes(huffman, brr, top,c,&t);
		i = 0;
		//printf("%d t\n",t);
		while(t ){
			/*bit = bit << 1;
			i = t%10 - 1;
			t = t/10;
			bit  = bit | i;
			//printf("%d t %d %d\n",t,i,bit);
			j++;
			if(j == 7) {
				fputc(bit,fop);
				//printf("-----%c@ \n",bit);
				bit= 0;
				j=0;
			} */
			i = t%10 - 1;
			t = t/10;
			if(i == 0) 
				fputc('0',fop);
			if(i == 1) 
				fputc('1',fop);
		}
	}
	/*if(j !=0 && j!= 7 ){
		while(j == 7 ){
			bit = bit<< 1;
			j++;
		}
		fputc(bit,fop);
				printf("----- \n");
	}*/
    return;

  /*
    Encode fip using huffman code and write properly to fop.
  */
}

void decode(FILE *fip,FILE *fop,struct node *huffman)
{
	struct node *current = huffman;
    	char bit;
    	char mask = 1 << 7;
    	char c;	
	int i,buffer;
  	while ((c= fgetc(fip))!=EOF){
		//printf("%c\n ",c);
		/*for (i=0;i<8;i++){
		    	bit = c & mask;
		    	c = c << 1;
		    	if (bit!=0){
		        	current = current->left;
				//printf("1");
		        	if (current->left == NULL && current->right == NULL ){
				    	fputc((char)current->data,fop);
					printf("---%c",current->data);
				    	current = huffman;
		        	}
			}

			else{
				current = current->right;
				//printf("0");
				if (current->left == NULL && current->right == NULL){
				    	fputc((char)current->data,fop);
					printf("---%c\n",current->data);
				    	current = huffman;
				}
			}
        	}*/
			if (c == '1'){
		        	current = current->left;
				//printf("1");
		        	if (current->left == NULL && current->right == NULL ){
				    	fputc((char)current->data,fop);
					//printf("---%c",current->data);
				    	current = huffman;
		        	}
			}

			else{
				current = current->right;
				//printf("0");
				if (current->left == NULL && current->right == NULL){
				    	fputc((char)current->data,fop);
					//printf("---%c\n",current->data);
				    	current = huffman;
				}
			}
    	}

    	return;

  /*
    Decode fip using huffman code and write properly to fop.
  */
}

int main()
{
	  FILE *fip,*fop,*fdec;
	  int **frequency,n,i;
	  char *heap;
	  struct node *huffman = NULL;
	  fip = fopen("input.txt","r");
	  fop = fopen("encode","w");
	  n = countDistinct(fip);
		printf("n %d\n",n);
	  frequency = (int **)malloc(n*sizeof(int *));
	  heap = (char *)malloc(n*sizeof(char));
	  for(i=0;i<n;i++)
	    	frequency[i]=(int *)malloc(2*sizeof(int));
	  rewind(fip);
	  collectFrequency(fip,frequency,n);
	  for(i=0;i<n;i++)
	    	printf("%c %d\n",frequency[i][0],frequency[i][1]);
	  buildMinHeap(heap,frequency,n);
	  huffman = constructHuffman(heap,frequency,n,huffman);
	  //printPreorder(huffman);

	  int arr[1000],top=0;
	//  printCodes(huffman, arr, top);
	  rewind(fip);
		  printf("hii encode\n");
	  encode(fip,fop,huffman,n);
	  fclose(fop);
	  fop = fopen("encode","r");
	  printf("bye encode\n");
	  fdec = fopen("decode.txt","w");
	//  decode(fop,fdec,huffman);
	  printf("bye decode\n");
	  fclose(fip);
	  fclose(fop);
	  fclose(fdec);
	  return 0;
}

