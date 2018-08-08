#include <stdio.h>
#include <stdlib.h>

void solve(double *,int);
void printans(int arr[][100],double temp[],int temp2[],int n,int i,int j);
int main()
{
  	int i,n,m;
  	double num,operator,*expr;
  	char *par_expr;
  	scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  	expr = (double *)malloc(((2*n)-1)*sizeof(double)); /* n numbers and n-1 operators */
  	scanf("%lf",&expr[0]);  /* first number */
  	for(i=1; i<(2*n)-1; i=i+2) {
    	scanf("%lf",&expr[i]); /* operator */
    	scanf("%lf",&expr[i+1]); /* Number */

  	}
  	solve(expr,n);
  	return 0;
}

void solve(double *expr, int n)
{
  /* solve the puzzle and use printf to print the parenthesized expression and result to screen */

	double temp[n];
	int temp2[n-1],pp[n-1];
	int i,j,k,len,m;
	double q;
	temp[0] = expr[0];
	k=0;
	for(i =1; i< 2*n-1; i= i+2){
		temp2[k] = expr[i];
		pp[k] = temp2[k];
		temp[++k] = expr[i+1];
	}
	
	
	int n1 = n+1;
	double arr[n1][n1];
	int brr[n1][100];
	for(i =0; i< n1; i++){	
		for(j =0; j< n1; j++){
			if(i == j && i != 0){
				arr[i][j] = temp[i-1];
				brr[i][j]= i;
			}
			else {
				arr[i][j] = 0;
				brr[i][j] = -1;
			}
		}
	}
	
	for(len = 2; len < n1; len++){
		for(i =1; i< n1-len+1; i++){
			j = i+len-1;
			arr[i][j] = -999999;
			if(j-i == 1 || i-j ==1){
				printf("%d-%d=1\n",i,j);
				switch(temp2[i-1]){
							case 0:
									for(m = 1; m<5; m++){
										switch(m){
											case 1:
					  								q = temp[i-1] + temp[j-1];
													break;
											case 2:
					  								q = temp[i-1] - temp[j-1];
													break;
											case 3:
					  								q = temp[i-1] * temp[j-1];
													break;
											case 4:
													if(temp[j-1] != 0)
					  									q = temp[i-1] / temp[j-1];
													else q=0;
													break;
										}
										//printf("%.2lf  q  %.2lf  temp[%d] %.2lf  temp[%d] \n",q,temp[i-1],i-1,temp[j-1],j-1);
										if(q > arr[i][j]){
											arr[i][j] = q;
											//printf("min q %.2lf  and arr[%d][%d] %.2lf \n",q,i,j,arr[i][j]);
										}
									}
									if(arr[i][j] == temp[i-1] + temp[j-1]){
										pp[i-1] = 1;
									}
									else if(arr[i][j] == temp[i-1] - temp[j-1]){
										pp[i-1] = 2;
									}
									else if(arr[i][j] == temp[i-1] *  temp[j-1]){
										pp[i-1] = 3;
									}
									else if(temp[j-1] != 0 && arr[i][j] == temp[i-1] / temp[j-1]){
										pp[i-1] = 4;
									}
									break;
							case 1:
	  								q = temp[i-1] + temp[j-1];
									break;
							case 2:
	  								q = temp[i-1] - temp[j-1];
									break;
							case 3:
	  								q = temp[i-1] * temp[j-1];
									break;
							case 4:
									if(temp[j-1] != 0.0){
	  									q = temp[i-1] / temp[j-1];
										//printf("no zero\n");
									}
									else q = 0;
									break;
						}
						if(q > arr[i][j]){
							//printf("outer q %.2lf  and arr[%d][%d] %.2lf \n",q,i,j,arr[i][j]);
							arr[i][j] = q;
							brr[i][j] = i;
						}
			}
			else{
				for(k = i; k <= j-1 ; k++){
					if(temp2[k-1] == 0){
						for(m = 1; m<5; m++){
							switch(m){
								case 1:
		  								q = arr[i][k] + arr[k+1][j];
										break;
								case 2:
		  								q = arr[i][k] - arr[k+1][j];
										break;
								case 3:
		  								q = arr[i][k] * arr[k+1][j];
										break;
								case 4:q=0;
										if(arr[k+1][j] != 0.0)
		  									q = arr[i][k] / arr[k+1][j];
										else q=0;
										break;
							}
							//printf("%.2lf  q  %.2lf  arr[%d][%d] %.2lf  arr[%d][%d] \n",q,arr[i][k],i,k,arr[k+1][j],k+1,j);
							if(q > arr[i][j]){
								printf("q %.2lf  and arr[%d][%d] %.2lf \n",q,i,j,arr[i][j]);
								arr[i][j] = q;
								//temp2[i-1] = m;
								brr[i][j] = k;
							}
						}
						if(arr[i][j] == arr[i][k] + arr[k+1][j]){
							pp[k-1] = 1;
						}
						else if(arr[i][j] == arr[i][k] - arr[k+1][j]){
							pp[k-1] = 2;
						}
						else if(arr[i][j] == arr[i][k] * arr[k+1][j]){
							pp[k-1] = 3;
						}
						else if(arr[k+1][j] != 0.0 && arr[i][j] == arr[i][k] / arr[k+1][j]){
							pp[k-1] = 4;
						}
					}
					else if(temp2[k-1] == 1){
						q = arr[i][k] + arr[k+1][j];
					}
					else if(temp2[k-1] == 2){
						q = arr[i][k] - arr[k+1][j];
					}
					else if(temp2[k-1] == 3){
						q = arr[i][k] * arr[k+1][j];
					}
					else if(temp2[k-1] == 4 && arr[k+1][j] !=0){
						q = arr[i][k] / arr[k+1][j];
					}
					else q=0;
					if(q > arr[i][j]){
						printf("outer q %.2lf  and arr[%d][%d] %.2lf \n",q,i,j,arr[i][j]);
						arr[i][j] = q;
						brr[i][j] = k;
					}
				}
			}
		}
	}
	for(i =0; i< n1; i++){
		for(j =0; j<n1; j++)
			printf("%.2lf  ",arr[i][j]);
		printf("\n");
	}
	
	printf("value of expression required are : %.2lf \n",arr[1][n]);
	for(i =0; i< n1; i++){
		for(j =0; j<n1; j++)
			printf("%d  ",brr[i][j]);
		printf("\n");
	}
	printans(brr,temp,temp2,n1,1,n1-1);
	printf("\n");
}


void printans(int arr[][100],double temp[],int temp2[],int n,int i,int j){
	if(i==j){
		printf("%.1lf ",temp[i-1]);
		return;
	}
	printf(" ( ");
	printans(arr,temp,temp2,n,i,arr[i][j]);
	if(temp2[i-1] == 1) 
		printf(" + %d %d  ",i-1,temp2[i-1]);
	else if(temp2[i-1] == 2) 
		printf(" - %d %d  ",i-1,temp2[i-1]);
	else if(temp2[i-1] == 3) 
		printf(" * %d %d  ",i-1,temp2[i-1]);
	else if(temp2[i-1] == 4) 
		printf(" / %d %d  ",i-1,temp2[i-1]);
	else printf("hii ");
	printans(arr,temp,temp2,n,arr[i][j]+1, j);
	
	printf(" ) ");
	return ;
}
