//Convex hull not by divide and conquer.
//Takes care of both horizontally occuring points and vertically occuring points on the hull.
#include<stdio.h>
#include<math.h>
struct node{
	double x,y;
	int mark;
}point[50],answer[50];
int z,k;
int flag;
int solution[50];
int cmp(const void *a,const void *b)
{
	struct node *c=(struct node *)a;
	struct node *d=(struct node *)b;
	if((*c).x==(*d).x)
	{
		if((*c).y>(*d).y)
		{
			return 1;
		}
		return -1;
	}
	else if((*c).x>(*d).x)
	{
		return 1;
	}
	return -1;
}
int line(int low,int high,int indicator)
{
	k=0;
	flag=0;
	double maxdis=0;
	double dist,m;
	int idx=high;
	int i;
	if(point[low].x!=point[high].x)
	{
		m=(point[high].y-point[low].y)/(point[high].x-point[low].x);
		for(i=low+1;i<high;i++)
		{
			double ynew=m*(point[i].x-point[low].x)+point[low].y;
			if(indicator==0&&ynew>point[i].y)
			{
				continue;
			}
			else if(indicator==1&&ynew<point[i].y)
			{
				continue;
			}
			dist=(m*point[i].x-point[i].y+point[low].y-m*point[low].x);
			dist=dist/(sqrt(1+m*m));
			if(dist<0)
			{
				dist=-1*dist;
			}
			if(dist==maxdis)
			{
				flag=1;
				solution[k++]=i;
			}
			else if(dist>maxdis)
			{
				flag=0;
				k=0;
				maxdis=dist;
				idx=i;
			}
		}
	}
	return idx;
}
void convex(int low,int high,int indicator)
{
	//printf("low=%d high=%d\n",low,high);
	int idx=line(low,high,indicator);
	int i;
	if(idx==high)
	{
		if(point[low].x!=point[high].x)
		{
			if(point[low].mark!=1)
			{
				answer[z++]=point[low];
				point[low].mark=1;
			}
			if(flag==1)
			{
				for(i=0;i<k;i++)
				{
					if(point[solution[i]].mark!=1)
					{
						answer[z++]=point[solution[i]];
						point[solution[i]].mark=1;
					}
				}
			}
			if(point[high].mark!=1)
			{
				answer[z++]=point[high];
				point[high].mark=1;
			}
			return;
		}
		else
		{
			for(i=low;i<=high;i++)
			{
				if(point[i].mark!=1)
				{
					answer[z++]=point[i];
					point[i].mark=1;
				}
			}
			return;	
		}
	}
	convex(low,idx,indicator);
	convex(idx,high,indicator);
	return;
}
int main()
{
	int i,n;
	printf("Enter the number of points: ");
	scanf("%d",&n);
	printf("Enter the points:\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&point[i].x,&point[i].y);
		point[i].mark=0;
	}
	qsort(point,n,sizeof(struct node),cmp);
	convex(0,n-1,0);
	int till=z;
	convex(0,n-1,1);
	k=1;
	printf("The points on convex hull are:\n");
	for(i=0;i<till;i++)
	{
		printf("%d:(%.1lf,%.1lf)\n",k++,answer[i].x,answer[i].y);
	}
	for(i=z-1;i>=till;i--)
	{
		printf ("%d:(%.1lf,%.1lf)\n",k++,answer[i].x,answer[i].y);
	}
	return 0;
}
