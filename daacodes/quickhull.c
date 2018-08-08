	#include<stdio.h>
	#include<math.h>
	#include<stdlib.h>
	typedef struct point{
		int x;
		int y;
	} point;
	struct point convexHull[1000];
	int no=0;

	float distance(point a,point b, point c)
	{
		return(   abs ( (b.y-a.y)*c.x - (b.x-a.x)*c.y + b.x*a.y - b.y*a.x ) / sqrt( (b.y-a.y)*(b.y-a.y) + (b.x-a.x)*(b.x-a.x) ) );
	}

	int comparex(const void *x,const void *y) {
	    struct point *n1=(struct point *)x;
	    struct point *n2=(struct point *)y;
	    return (n1->x - n2->x);
	}

	//0 for left  1 for right
	int leftright(point a, point b, point c)
	{
		float k = ((b.y-a.y)*(c.x-a.x))-((c.y-a.y)*(b.x-a.x));
		if(k>0)
			return 1;
		else if( k<0) 
			return 0;
		return -1;
	}


	void findHull(struct point s[],int size,point a,point b)
	{
		if(size==0)
			return;
		int i=0,index;
		point k;
		float max=-999999;
		for(i=0;i<size;i++)
		{ 
			float d=distance(a,b,s[i]);
			if(d>max)
			{	
				max=d;
				index=i;
			}
		}

		convexHull[no++]=s[index];
		struct point s0[1000],s1[1000],s2[1000];
		int size0=0,size1=0,size2=0;
		
		for(i=0;i<size;i++)
		{
			float l1=leftright(a,s[index],s[i]);
			float l2=leftright(b,s[index],s[i]);
			if(l1==0 && l2==0)
				s1[size1++]=s[i];
			else if(l2==1 && l2==1 )
				s2[size2++]=s[i];
			else
				s0[size0++]=s[i];
		}
		findHull(s1,size1,a,s[index]);
		findHull(s2,size2,s[index],b);

	}

	void quickHull(struct point *arr,int l, int r)
	{	printf("in start of quick quickHull\n");
		point a=arr[l];
		point b= arr[r];
		convexHull[no++]=a;
		convexHull[no++]=b;
		struct point sl[1000],sr[1000];
		int sizel=0,sizer=0;
		int i;
		for(i=l;i<=r;i++)
		{
			float rr=leftright(a,b,arr[i]);
			if(rr==0)
				sl[sizel++]=arr[i];
			if(rr==1)
				sr[sizer++]=arr[i];
		}
		findHull(sl,sizel,a,b);
		findHull(sr,sizer,b,a);
	}


	int main()
	{
		int n;
		scanf("%d",&n);
		struct point arr[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d%d",&arr[i].x,&arr[i].y);
		qsort(arr,n,sizeof(point),comparex);
		quickHull(arr,0,n-1);
		for(i=0;i<no;i++)
		{
			printf("(%d , %d)  ",convexHull[i].x,convexHull[i].y);
		}
		return 0;
	}


