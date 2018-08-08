# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node {
    struct node *left,*right;
    char data;
};

void decode(FILE *,FILE *,struct node *);
void encode(FILE *,FILE *,struct node *,int, int **);
struct node * constructTree(char **, int **, int , struct node *);
void collectFrequency(FILE *,int **,int );
void sort(int **freq,int n);
int countDistinct(FILE *);
void check(struct node *node,char ch[],char **code,int n,int **freq);
void shannon_fano(double prob[],int low ,int high,char **heap);
void shann(int **freq,int low ,int high,char **heap);
int main()
{
    FILE *fip,*fop,*fdec;
    int **frequency,n,i;
    char **heap;
    struct node *huffman;
    fip = fopen("input.txt","r");
    fop = fopen("encode.txt","w");
    n = countDistinct(fip);
	printf("%d\n",n);
    frequency = (int **)malloc(n*sizeof(int *));
    heap = (char **)malloc(n*sizeof(char *));
    for(i=0;i<n;i++){
	frequency[i]=(int *)malloc(2*sizeof(int));
	heap[i] = (char *)malloc(20 * sizeof(char ));
    }
    rewind(fip);
    collectFrequency(fip,frequency,n);
    for(i=0;i<n;i++)
	    printf("%c %d\n",frequency[i][0],frequency[i][1]);
    sort(frequency,n);
    shann(frequency,0,n-1,heap);
    huffman = constructTree(heap,frequency,n,huffman);
    rewind(fip);
    collectFrequency(fip,frequency,n);
    rewind(fip);
    encode(fip,fop,huffman,n,frequency);
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
    char ch;
    int hash[256],i;
    for(i=0;i<256;i++)
	   hash[i] = 0;
    while( (ch = getc(fp)) != EOF){
    	hash[(int)ch]++;
    }
    for(i=0;i<256;i++){
    	if(hash[i] > 0){
    	    n++;
    	}
    }
    return n;
}
void sort(int **freq,int n){
	int i,j;
	for(i =0; i<n-1;i++){
		for(j=i+1; j<n; j++){
			if(freq[i][1] < freq[j][1]){
				int temp = freq[i][1];
				freq[i][1] = freq[j][1];
				freq[j][1] = temp;
				char tmp = freq[i][0];
				freq[i][0] = freq[j][0];
				freq[j][0] = tmp;
			}
		}
	}
}

void collectFrequency(FILE *fp,int **freq,int n)
{
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
}
struct node * constructTree(char **heap, int **freq, int n, struct node *huffman)
{
    	int i;
    	int size = n;
    	huffman = (struct node *)malloc(sizeof(struct node ));
    	struct node *arr = huffman,*ele;
    	int j = 0;
    	while(j < n){
		arr = huffman;
    		for(i=0; i<strlen(heap[j]); i++){
			if(i == strlen(heap[j])-1 ){
				if(heap[j][i] == '0' && arr->left ){
					arr = arr->left;
					arr->left = arr->right = NULL;
					arr->data = freq[j][0];
				}
				else if(heap[j][i] == '0' && arr->left == NULL ){
					arr->left = (struct node *)malloc(sizeof(struct node ));
					arr = arr->left;
					arr->left = arr->right = NULL;
					arr->data = freq[j][0];
				}
				else if(heap[j][i] == '1' && arr->right ){
					arr = arr->right;
					arr->left = arr->right = NULL;
					arr->data = freq[j][0];
				}
				else if(heap[j][i] == '1' && arr->right == NULL ){
					arr->right = (struct node *)malloc(sizeof(struct node ));
					arr = arr->right;
					arr->left = arr->right = NULL;
					arr->data = freq[j][0];
				}
				//printf("%c\n",arr->data);
			}
    			else if(heap[j][i] == '0' ){
				if(arr->left )
					arr = arr->left;
				else{
					arr->left = (struct node *)malloc(sizeof(struct node ));
					arr = arr->left;
					arr->left = arr->right = NULL;
					arr->data = '$';
				}
			}
			else if(heap[j][i] == '1' ){
				if(arr->right )
					arr = arr->right;
				else{
					arr->right = (struct node *)malloc(sizeof(struct node ));
					arr = arr->right;
					arr->left = arr->right = NULL;
					arr->data = '$';
				}
			}
    		}
		j++;
    	
    	}
    	return huffman;
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
void check(struct node *node,char ch[],char **code,int n,int **freq){
	if(node == NULL)
        	return;
	if(node->left == NULL && node->right==NULL)
	{
	    	int i;
		for(i =0; i<n ;i++){
			if(freq[i][0] == node->data)
				break;
		}
		if(i ==n){
			//printf("hiii %c\n",node->data);
			return;
		}
	    	strcpy(code[i],ch);
	    //code[(int)node->data] = binary(ch);
	    	//printf("%c  %s\n",node->data,ch);
	    return;
	}
    	char temp[100];
    //printf("CHECK\n");
       	if(node->left != NULL){
        	strcpy(temp,ch);
        	strcat(temp,"0" );
          	check(node->left,temp,code,n,freq);
       	}
       	if(node->right != NULL){
		strcpy(temp,ch);
		strcat(temp,"1");
		check(node->right,temp,code,n,freq);

       	}
}
void encode(FILE *fip,FILE *fop,struct node *huffman,int n,int **freq)
{
    
     	char **code,ch;
     	char *encoding;
     	char start[100];
     	int i,j;
     /*for(i=0;i<150;i++)
	     code[i] = -1;*/
     	code = (char **)malloc(n*sizeof(char *));
     	for(i=0;i<n;i++){
	   	code[i] = (char *)malloc(20 * sizeof(char)); 
	}
     	strcpy(start,"0");
     	check(huffman->left,start,code,n,freq);
     	strcpy(start,"1");
     	check(huffman->right,start,code,n,freq);
	for(i=0;i<n;i++)
	   	printf("%c %s\n",freq[i][0],code[i]);
     	while((ch = getc(fip)) != EOF){
		for(i =0; i<n ;i++){
			if(freq[i][0] == ch)
				break;
		}
	     	fprintf(fop,"%s",code[i]);
	      	//printf("%c",ch);
     	}
     /*for(i=0;i<125;i++)
	 printf("%d %s \n",i,code[i]);*/
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


void shann(int **freq,int low ,int high,char **heap){
	if(high - low + 1 == 1){
		strcpy(heap[low],"0");
		return;
	}
	if(high - low + 1 == 2){
		strcpy(heap[low],"0");
		strcpy(heap[high],"1");
		return;
	}	
	double prob[high-low+1];
	int i,j = low+1;	
	int cnt=0;
	for(i=0; i< high-low+1; i++){
		cnt += freq[i][1];
		prob[i] = freq[i][1];
	}
	for(i=0; i< high-low+1; i++){
		//prob[i] = prob[i]/cnt;
		printf("%lf\n",prob[i]);

	}
	double a[high-low+1]  ,b[high-low+1];
	for(i = 0; i<high-low+1 ; i++){
		a[i]=0;
		b[i]=0;
		for(j = low; j<=low+i; j++)
			a[i] += prob[j];
		for( ; j<=high; j++)
			b[i] += prob[j];
		a[i] = a[i]-b[i];
		//printf("%lf %lf\n",a[i],b[i]);
	}
	int in = -1,m=999;
	for(i =1; i<high-low+1; i++){
		if(a[i] < m && a[i] >=0){
			m = a[i];
			in = i;
		}

	}
	j= low;
	while(j < in){
		strcat(heap[j],"0");
		j++;
	}
	while(j <= high){
		strcat(heap[j],"1");
		j++;
	}
 	shannon_fano(prob,low,in-1,heap);
	shannon_fano(prob,in,high,heap);
}
void shannon_fano(double prob[],int low ,int high,char **heap){
	if(high < low ) return;
	if(high - low + 1 == 1){
		heap[low][strlen(heap[low])] = '\0';
		return;
	}
	if(high - low + 1 == 2){
		strcat(heap[low],"0");
		heap[low][strlen(heap[low])] = '\0';
		strcat(heap[high],"1");
		heap[high][strlen(heap[high])] = '\0';
		return;
	}
	int i,j = low+1;
	//strcat(heap[low],"0");
	double a[high-low+1]  ,b[high-low+1];
	for(i = 0; i<high-low+1 ; i++){
		a[i]=0;
		b[i]=0;
		for(j = low; j<=low+i; j++)
			a[i] += prob[j];
		for(; j<=high; j++)
			b[i] += prob[j];
		printf("%lf %lf\n",a[i],b[i]);
		a[i] = abs(a[i]-b[i]);

	}
	int in = -1;
	double m=999;
	for(i =0; i<high-low+1; i++){
		if(a[i] < m && a[i] >=0){
			m = a[i];
			in = i;
		}
	}
	j= low;
	printf("-------------%d %d %lf gg %d %s\n",low,high,m,in,heap[in+low]);
	
	while(j <= low+in){
		strcat(heap[j],"0");
		j++;
	}
	while(j <= high){
		strcat(heap[j],"1");
		j++;
	}
	shannon_fano(prob,low,low+in,heap);
	shannon_fano(prob,low+in+1,high,heap);
}
