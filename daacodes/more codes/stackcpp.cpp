#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

stack<int>  push_bottom(stack <int> stk, int a){
    if(stk.size() == 0 || stk.top() <= a){
        stk.push(a);
        return stk;
    }
    if(stk.top() > a){
        int t = stk.top();
        stk.pop();
        stk = push_bottom(stk,a);
        stk.push(t);
	return stk;
    }
    
    
}


void SortedStack :: sort()
{
   //Your code here
   if(s.size() != 0){
       int a = s.top();
       s.pop();
       sort();
       this->s = push_bottom(this->s,a);
   }
   
}


void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	printStack(ss->s);
	cout<< "hiii"<<endl;
	ss->sort();
	printStack(ss->s);
}
}

