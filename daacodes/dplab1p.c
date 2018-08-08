#include<stdio.h>
#include<limits.h>

void print(int n,int i,int j,float m[n][n],float p[])
{
	//printf("\n%d %d %f \n",i,j,m[i][j]);
	if(j==i)
	{
		printf("%f",p[i]);
		if(p[i+1]==1)
			printf("+");
		else if(p[i+1]==2)
			printf("-");
		else if(p[i+1]==3)
			printf("*");
		else 
			printf("/");

		return ;		
	}
	if(m[i][j]!=-1)
	{
		//printf("hi\n");
		printf("(");
		print(n,i,m[i][j],m,p);
		print(n,m[i][j]+2,j,m,p);
		printf(")");
	}
}


float solve(float p[], int k1)
{
	int n=2*k1-1;
	float s1[n];
	float m[n][n];
	int i, j, k, L, q;
	float m1[n][n];
	for(i=0;i<n;i++)
		s1[i]=p[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=-100000;
			m1[i][j]=-1;
		}
	}
	for (i=0; i<n; i+=2)
		m[i][i] = p[i];

	for (L=2; L<n; L+=2)
	{
		for (i=0; i<n-L+1; i+=2)
		{
			j = i+L;
			int s;
			int kmax=-2;
			//printf("%d %d\n\n",i,j);
			//m[i][j] = -100000;
			s=0;
			for (k=i; k<=j-1; k+=2)
			{
				
				float l=m[i][j];
				//s = 0;
				if(p[k+1]==1 || p[k+1]==0)
				{
					q=m[i][k] + m[k+2][j];
					if(q>l)
					{
						l=q;
						s=1;
						m1[i][j]=k;
					}
				}
				if(p[k+1]==2 || p[k+1]==0)
				{
					q=m[i][k] - m[k+2][j];
					if(q>l)
					{
						l=q;
						s=2;
						m1[i][j]=k;
					}
				}
				if(p[k+1]==3 || p[k+1]==0)
				{
					q=m[i][k] * m[k+2][j];
					if(q>l)
					{
						l=q;
						s=3;
						m1[i][j]=k;
					}
				}
				if((p[k+1]==4 || p[k+1]==0) && m[k+2][j]!=0)
				{
					q=m[i][k] / m[k+2][j];
					if(q>l)
					{
						l=q;
						s=4;
						m1[i][j]=k;
					}
				}
				
				if(p[k+1]==0 && l>m[i][j])
				{
					kmax=k;
					m1[i][j]=l;
					
					//s1[k+1]=s;
					//printf("%d %d %d %f\n",i,j,k+1,s1[k+1]);
				}
				m[i][j]=l;
			}
			//printf("%d\n\n",kmax);
			m1[i][j]=kmax;
			if(kmax>-2)
			s1[kmax+1]=s;
			// q = cost/scalar multiplications
			//q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
			//if (q < m[i][j])
			//	m[i][j] = q;

		
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%f ",m[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%f ",m1[i][j]);
		printf("\n");
	}
	printf("\n\n\n");

	for(i=0;i<n;i++)
	{
		printf("%f ",s1[i]);
	}
	printf("\n\n\n");
	
	//print(n,0,n-1,m1,s1);
	return m[0][n-1];
}

int main()
{
	int n,i;
	scanf("%d",&n);
	printf("hi%d\n",n);
	float a[2*n-1];
	scanf("%f",&a[0]);
	for(i=1;i<2*n-1;i+=2)
	{
		scanf("%f",a+i);
		printf("%f ",a[i]);
		scanf("%f",a+i+1);
		printf("%f ",a[i+1]);
	}
	printf("\n");
	for(i=0;i<2*n-1;i++)
		printf("%f ",a[i]);
	printf("\n");
	//for(i=0;i<2*n-1;i++)
	//	scanf("%f",a+i);
	//int arr[] = {1, 2, 3, 4};
	//int size = sizeof(arr)/sizeof(arr[0]);
	printf("%f\n",solve(a,n));
	//printf("Minimum number of multiplications is %d ",
	//		MatrixChainOrder(arr, size));

	//getchar();
	return 0;
}
