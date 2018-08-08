# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node {
    struct node *left,*right;
    char data;
};

void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *);
struct node * constructHuffman(char *, int **, int , struct node *);
void buildMinHeap(char *, int **, int );
void collectFrequency(FILE *,int **,int );
int countDistinct(FILE *);
void restore_down(char *,int,int **, int);
void restore_up(char *,int **,int);
void check(struct node *,char ch[],char **code,int);
int main()
{
    FILE *fip,*fop,*fdec;
    int **frequency,n,i;
    char *heap;
    struct node *huffman;
    fip = fopen("input.txt","r");
    fop = fopen("encode.txt","w");
    n = countDistinct(fip);
	printf("%d\n",n);
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
    rewind(fip);
    encode(fip,fop,huffman);
    fclose(fop);
    fop = fopen("encode.txt","r");
    fdec = fopen("decode.txt","w+");
    decode(fop,fdec,huffman);
    fclose(fip);
    fclose(fop);
    fclose(fdec);
    return 0;
}

int countDistinct(FILE *fp)
{
    int n=0;
    /* Count the total number of distinct characters in the file */
    char ch;
    int hash[256],i;
    for(i=0;i<256;i++)
	   hash[i] = 0;
    while( (ch = getc(fp)) != EOF){
    	//printf("%d ",(int)ch);
    	hash[(int)ch]++;
    }
    for(i=0;i<256;i++){
    	if(hash[i] > 0){
    	    n++;
    	}
    }
    //printf("%d\n",n);
    return n;
}

void collectFrequency(FILE *fp,int **freq,int n)
{
    /*
       You need to figure out how many times each character appears in the file. For this we will use hash table.

       create a proper hash function by looking at the file and use the frequency array as a hash table.
       For collision and it's resolution, we allow two cells at every position of the hash table.
       The first cell will contain the ascii code of the character and the second cell will contain the frequency of that character.
     */
    int hash[256],i;
    for(i=0;i<256;i++)
	hash[i] = 0;
    char ch;
    int cnt=0;
    while( (ch = getc(fp)) != EOF){
	   //printf("%d ",(int)ch);
	   hash[(int)ch]++;
	   cnt++;
    }
    int ptr= 0;
    //printf("HASHED WITH TOTAL %d\n",cnt);
    for(i=0;i<256;i++)
    {
    	if(hash[i] > 0){
    	    freq[ptr][0] = i;
    	    freq[ptr][1] = hash[i];
    	    ptr++;
    	}
    }
    //printf("%d\n",ptr);
    // for(i=0;i<n;i++)
    //printf("%d %c %d\n",i,freq[i][0],freq[i][1]);
}
void buildMinHeap(char *heap, int **freq, int n)
{
    /* 
       This is exactly similar to the buil_max_heap that you have created in previous lab assignment with the following difference:
       In heap you store the characters, but unlike previous implementation the comaprison between different characters are not by their ASCII but by their frequency.
       You should use the same hash function to look for the frequency of the specific character
     */
    int i,j,k;
    for(i=0;i<n;i++){
	heap[i] = freq[i][0];
	//printf("%c ",freq[i][0]);
    }
    //printf("Assigned");
    for(i=((n-1)/2);i>=0;i--)
	restore_down(heap,i,freq,n);
    /*for(i=0;i<n;i++)
	printf("%c %d\n",heap[i],freq[i][1]);*/

}
void restore_down(char *heap, int index,int **freq,int n){
    int i,j,k,temp;
    char tc;
    int left = index*2+1;
    int right = index*2+2,large=index;
    if(left<n && freq[left][1] < freq[index][1] )
	large = left;
    else 
	large = index;
    if(right<n && freq[right][1] < freq[large][1])
	large = right;
    if(large != index){
	temp = freq[large][1];
	freq[large][1] = freq[index][1];
	freq[index][1] = temp;

	tc = heap[large];
	heap[large] = heap[index];
	heap[index] = tc;

	restore_down(heap,large,freq,n);
    }
}
void delete(char *heap,int **freq,int *size)
{
    /*int *curr;
    curr = (int *)malloc(2*sizeof(int));
    curr[0] = heap[0];
    curr[1] = freq[0][1];*/
   // printf("DELETE %d %d\n",(int)heap[0],freq[0][1]);
    heap[0] = heap[*size-1];
    freq[0][0] = freq[*size-1][0];
    freq[0][1] = freq[*size-1][1];
    *size = *size-1;
    restore_down(heap,0,freq,*size);
    //printf("DEL RET\n");
    //return curr;
}
struct node * constructHuffman(char *heap, int **freq, int n, struct node *huffman)
{
    /*
       Construct the huffman tree from the given heap.
       Note that you may need to change the heap while contruction (deletion, insertion). Please import the appropriate function written in previous classes.
       Also, note that, you may need to store frequency of new elements that are not there in the file and thus in the array frequency.
       For this you may change the content of the array frequency correctly and figure out a way to store the frequency of tree nodes in the array.
       Otherwise you may use your own data structure
     */
    int size = n;
    char c1,c2;
    int f1,f2;
    int *curr;
    int cnt = 1;
    curr = (int *)malloc(2*sizeof(int));
    struct node **arr,*ele;
    int i;
    int first,second;
    arr = (struct node **)malloc(n*sizeof(struct node *));
    for(i=0;i<n;i++)
    {
        arr[i] = (struct node *)malloc(sizeof(struct node ));
	   //arr[i] = (struct node *)malloc(1*sizeof(struct node));
	   arr[i]->data = heap[i];
	   arr[i]->left = arr[i]->right = NULL;
    }
    while(size>1){
    	/*for(i=0;i<n;i++)
    	{
    		if(arr[i] == NULL)
    			printf("NL ");
    		else
    			printf("%d ",arr[i]->data);
    	}
    	printf("\n");*/
    	c1 = heap[0];
    	f1 = freq[0][1];
    	delete(heap,freq,&size);
    	c2 = heap[0]; 
    	f2 = freq[0][1];
            delete(heap,freq,&size);
    	//printf("%c %c %d %d\n",c1,c2,f1,f2);
    	//printf("asdadad");
    	ele= (struct node *)malloc(sizeof(struct node ));
    	ele->data = c1;
    	first = second = 0;
    	for(i=0;i<n;i++){
    		//printf("afg");
    	    if(arr[i] != NULL && arr[i]->data == c1)
    		first = i;
    	    if(arr[i] != NULL && arr[i]->data == c2)
    		second = i;
    	}
        //  printf("left %d, right %d\n",first,second);
    	ele->left = arr[first];
    	ele->right = arr[second];
    	arr[first] = ele;
    	arr[second] = NULL;
    	heap[size] = c1;
    	freq[size][0] = heap[size];
    	freq[size][1] = f1+f2;
    	//printf("Inserted %d %d\n",(int)heap[size],freq[size][1]);
    	size++;
    	//printf("%d ",size);
    	restore_up(heap,freq,size-1);
    }
    /*printf("OUT\n");
    for(i=0;i<n;i++){
	    if(arr[i] == NULL)
		    printf("NL ");
	    else
		    printf("%d ",arr[i]->data);
    }
    printf("\n");*/
    i=0;
    while(arr[i] == NULL && i<n)
	   i++;
    huffman = arr[i];
    /*for(i=0;i<n;i++)
	printf("%c ",heap[i]);
   printf("OVER\n");
   if(huffman->right == NULL)
	   printf("LEFT NULL\n");
    else
          printf("\n%c ",huffman->data);*/  
    return huffman;
}
void restore_up(char *heap,int **freq,int i){
    int temp;
    char tc;
    while(i > 0){
	//printf("asda");    
	if(freq[i][1] < freq[(i-1)/2][1])
	{
	    temp = freq[i][1];
	    freq[i][1] = freq[(i-1)/2][1];
	    freq[(i-1)/2][1] = temp;

	    tc = heap[i];
	    heap[i] = heap[(i-1)/2];
	    heap[(i-1)/2] = tc;
	}
	else
	    break;
	i = (i-1)/2;
    }

}
char * binary(long long int val){
	char *a;
	a = (char *)malloc(100*sizeof(char));
	int rem,cnt=0,arr[100],i;
	while(val > 0){
		rem = val % 2;
		arr[cnt++] = rem;
		val/=2;
	}
	if(cnt == 0)
	{
		a[0] = '0';
		a[1] = '\0';
		return a;

	}
	for(i=0;i<cnt;i++){
		a[i] = (char)(arr[i]+'0');
		//strcpy(a,arr[i]-'0');
	}
	a[cnt] = '\0';
	return a;
}
void check(struct node *node,char ch[],char **code,int count){
	if(node == NULL)
        	return;
	if(node->left == NULL && node->right==NULL)
	{
	    strcpy(code[(int)node->data],ch);
	    //code[(int)node->data] = binary(ch);
	    printf("%s %d\n",ch,count);
	    return;
	}
    	char temp[100];
    //printf("CHECK\n");
       	if(node->left != NULL){
        	strcpy(temp,ch);
        	strcat(temp,"0" );
          	check(node->left,temp,code,count+1);
       	}
       	if(node->right != NULL){
		strcpy(temp,ch);
		strcat(temp,"1");
		check(node->right,strcat(ch,"1"),code,count+1);

       	}
}
void encode(FILE *fip,FILE *fop,struct node *huffman)
{
    
     char **code,ch;
     char *encoding;
     char start[100];
     int i,j;
     /*for(i=0;i<150;i++)
	     code[i] = -1;*/
     code = (char **)malloc(125*sizeof(char *));
     for(i=0;i<125;i++)
	   code[i] = (char *)malloc(100 * sizeof(char)); 
     strcpy(start,"0");
     check(huffman->left,start,code,0);
     strcpy(start,"1");
     check(huffman->right,start,code,0);
	
     while((ch = getc(fip)) != EOF){
	     fprintf(fop,"%s",code[(int)ch]);
	      //printf("%c",ch);
     }
     /*for(i=0;i<125;i++)
	 printf("%d %s \n",i,code[i]);*/
}
char validate(char current[],char **code){
    int i;
    
    for(i=0;i<125;i++){
        if(strcmp(code[i],current) == 0)
            return i;
    }
        
    return -1;
}
void decode(FILE *fip,FILE *fop,struct node *huffman)
{
    /*
       Decode fip using huffman code and write properly to fop.
     */
   	char c;
	struct node *cur = huffman;
     	while((c = getc(fip)) != EOF){
        	if (c == '0'){
			cur = cur->left;
				//printf("1");
		        if (cur->left == NULL && cur->right == NULL ){
			    	fputc((char)cur->data,fop);
				//printf("---%c",cur->data);
			    	cur = huffman;
		        }
		}
		else{
			cur = cur->right;
			//printf("0");
			if (cur->left == NULL && cur->right == NULL){
			    	fputc((char)cur->data,fop);
				//printf("---%c\n",cur->data);
			    	cur = huffman;
			}
		}
     	}
 
 }
