#include<stdio.h>
int mainpath[1000][1000], len[1000] ,cost[1000];
int path[1000],reach[1000],a[1000][1000];int nopaths = 0,costt = 0;
void dfs ( int v,int t,int ind,int n,int value);
void copy( int length);
void sort ();
void swap(int in,int jn);



int main()
{	int i,j,count=0;int s ,t,k , w ,z,n;
	int u ,v ,r;
	
	printf("enter no. of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
			a[i][j] = 0;
			}
	printf("enter u v and w.. enter u = -1 to exit\n");
    scanf("%d%d%d",&u,&v,&w);
  	while(u!=-1)
    {
      a[u][v]=w;
       printf("enter u v and w..\n");
      scanf("%d%d%d",&u,&v,&w);
    } 
    
	
	
//printf("enter the source .\n");
//	scanf("%d",&s);
	//scanf("%d",&t);
	//path[0] = s;
	for(r=0;r<n;r++)
	{	s = r;
		path[0] = s;
		printf("source is %d\n",s);
			for(z=0;z<n;z++)
		{	for(k=0;k<n;k++)
			{	reach[k] = 0;
				cost[k] = 0;
				
			}
			t = z;
			printf("t is %d\n",t);
			dfs(s ,t ,0,n,0);
			printf("no. of paths are %d...\n",nopaths);
			sort();
			//printf("after sorting\n");
			for(i=0;i<nopaths;i++)
			{	printf("path no. %d is...\n",i+1);
				for(j=0;j<len[i];j++)
					printf("%d-",mainpath[i][j]);
				printf("the cost of path is  %d..\n",cost[i]);
				printf("\n");}
			nopaths =0;
		}
	}
	
	
	return 0;
}
void sort ()
{	int i,j;
	for(i=0;i<nopaths;i++)
	{	for(j=i+1;j<nopaths;j++)
		{	if( cost[i] > cost[j] )
				swap(i,j);
		}
	}
}
void swap(int in,int jn)
{	int temp;
	int t[100] ,i;
	temp = cost[in];
	cost[in] = cost[jn];
	cost[jn] = temp;
	temp = len[in];
	len[in] = len[jn];
	len[jn] = temp;
	// len[j] has length of i and similarly for i
	for(i=0;i<len[in];i++)
		path[i] = mainpath[jn][i]; // we stored jn
	for(i=0;i<len[jn];i++)
		mainpath[jn][i] = mainpath[in][i]; // put in into jn 
	for(i=0;i<len[in];i++)
		mainpath[in][i] = path[i];
}
void dfs ( int v,int t,int ind,int n,int value)
{	int i;
	reach[v] = 1;
	path[ind] =  v;
	costt  += value;
	
  	if( v == t )
  	{	//printf("copy called..\n");
  		if( (ind+1) == n)
  			copy(ind+1);
  		reach[v] = 0;
  		costt  -= value;
		return ;
	}
	for(i=0;i<n;i++){
		if(a[v][i] && !reach[i])
  			{//	printf("recurse\n");		
			   dfs(i,t,ind+1,n,a[v][i]);
		}
	}
	reach[v] = 0;
	costt -= value;
	
	
}
void copy( int length)
{	int i;
	len[nopaths] =  length;
	cost[nopaths] = costt;
	for(i=0;i<length;i++)
	mainpath[nopaths][i] = path[i];
	nopaths += 1;
}
	
	
	
	

