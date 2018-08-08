const int MAX=1E6;
vector<int>v;
//v stores prime factors less than equal to MAX
for(i=2;i<=MAX;i++)
{
	if(!prime[i])
	{
		v.push_back(i);
		for(j=2*i;j<=MAX;j+=i)
		{
			prime[j]=1;
		}
	}
}
//carry out prime factorisation of N
for(i=0;i<v.size();i++)
{
	if(v[i]*v[i]>N)
	break;
	int co=0; //count of the power of prime factor
	while(N%v[i]==0)
	{
		N=N/v[i];
		co++;
	}
	if(co>=1)
	printf("%d %d\n",v[i],co);
}
if(N>1) //the leftover N is prime factor
{
	printf("%d 1\n",N);
}
/********************************************/
//Another way
vector<int>v[MAX];
//v[i] stores prime factors of i
for(i=2;i<=MAX;i++)
{
	if(!prime[i])
	{
		v[i].push_back(i);
		for(j=2*i;j<=MAX;j+=i)
		{
			v[j].push_back(i);
			prime[j]=1;
		}
	}
}
//carry out prime factorisation of N
int m=N;
for(i=0;i<v[N].size();i++)
{
	int co=0; //count of the power of prime factor
	while(m%v[i]==0)
	{
		m=m/v[i];
		co++;
	}
	printf("%d %d\n",v[i],co);
}

