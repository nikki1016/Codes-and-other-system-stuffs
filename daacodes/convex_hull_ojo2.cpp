# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>
# include <cstdio>

using namespace std;


double eqn(int a, int b, int c, int d, int x, int y)
{
	if((x == a && y == b) || (x == c && y == d)){
		return 0.00;
	}
	double m;
	m = (double) (d-b)/(double) (c-a);
//	cout << "M" << m<<endl;
	return ( (double)(y - b) - ((double)m * (x-a)));
}
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
bool test_upper(vector<pair<int,int> > v, int a,int b, int c, int d, int &g, int &h)
{
	cout << "HERE UPPER" << endl;

	
	cout << a << " " << b << " " << c << " " << d << endl;

	for (int i = 0; i < v.size(); i++){
		cout << v[i].first << " " << v[i].second << " ";
		cout << eqn(a,b,c,d,v[i].first,v[i].second) << endl;
		cout << endl;
	//	getchar();
			

		if(eqn(a,b,c,d,v[i].first,v[i].second) > 0.00){
					
				g = v[i].first;
				h = v[i].second;

				return false;
		}
	}
//	cout << "HERE ALSO" << endl;

	return true;
}

bool test_lower(vector<pair<int,int> > v, int a, int b, int c, int d,int &g, int &h)
{
	
	cout << "HERE" << endl;
cout << a << " " <<b <<" " << c <<" " <<d <<endl;
	for (int i = 0; i < v.size(); i++){
		
		cout << " for" << v[i].first <<"and" << v[i].second <<" " << eqn(a,b,c,d,v[i].first,v[i].second) << endl;
	//	getchar();
		if(eqn(a,b,c,d,v[i].first,v[i].second) < 0.00){
				g = v[i].first;
				h = v[i].second;
				return false;
		}
	}
	return true;
}
	

void merge(vector<pair<int,int> > convex_left,vector<pair<int,int> > convex_right,vector<pair<int,int> > &res, vector<pair<int,int> > v)
{

	if(convex_left.size() == 0){
		res = convex_right;
		return;
	} else if (convex_right.size() == 0){
		res = convex_left;
		return;
	}
	int xhighl,yhighl,xhighr,yhighr;
	int xlowl,ylowl,xlowr,ylowr;

	xhighl = convex_left[0].first;
	yhighl = convex_left[0].second;

	xlowl = convex_left[0].first;
	ylowl = convex_left[0].second;

	for (int i = 1; i < convex_left.size(); i++){
		
		if(convex_left[i].second > yhighl){
			yhighl = convex_left[i].second;
			xhighl = convex_left[i].first;
		}

		if(convex_left[i].second < ylowl){
			ylowl = convex_left[i].second;
			xlowl = convex_left[i].first;
		}

	}

	xhighr = convex_right[0].first;
	yhighr = convex_right[0].second;

	xlowr = convex_right[0].first;
	ylowr = convex_right[0].second;

	for (int i = 1; i < convex_right.size(); i++){
		
		if(convex_right[i].second > yhighr){
			yhighr = convex_right[i].second;
			xhighr = convex_right[i].first;
		}

		if(convex_right[i].second < ylowr){
			ylowr = convex_right[i].second;
			xlowr = convex_right[i].first;
		}
	}
	

	int g,h;
/*	cout << "here" << endl;
	for (int i = 0; i < v.size(); i++){
		cout << v[i].first << " ";
	}
	cout << endl; */

	while(test_upper(convex_right,xhighl,yhighl,xhighr,yhighr,g,h) != true){
		
		xhighr = g;
		yhighr = h;
	}

	while(test_upper(convex_left,xhighr,yhighr,xhighl,yhighl,g,h) != true){
		xhighl = g;
		yhighl = h;
	}

	cout << "Test_upper passed" << endl;
	cout << xhighr << " " << yhighr<<"      " << xhighl <<" "<<yhighl << endl;
	while(test_lower(convex_right,xlowl,ylowl,xlowr,ylowr,g,h) != true){
		xlowr = g;
		ylowr = h;
	}

	while(test_lower(convex_left,xlowr,ylowr,xlowl,ylowl,g,h) != true){
		xlowl = g;
		ylowl = h;
//		cout << "modified" << g << h << endl;
		
	}

	cout << "Test_lower passed" << endl;
	cout << xlowr << " " << ylowr<<"     " << xlowl <<" " <<ylowl << endl;


	int index;

/*	cout << "Convex_left is " << endl;
	for (int i = 0; i < convex_left.size(); i++){
		cout << convex_left[i].first <<" ";
	}
	cout << endl;    */

	for (int i = 0; i < convex_left.size(); i++){
		if(convex_left[i].first == xhighl && convex_left[i].second == yhighl){
			index = i;
			break;
		}
	}

	int i = index;

///	cout <<"res.size" << res.size() << endl;

//	cout << "convex_left.size" << convex_left.size() << endl;
	while(convex_left[i].first != xlowl || convex_left[i].second != ylowl){

//	cout << i << endl;

		res.push_back(convex_left[i]);
	
			
		i++;
	
		i = i % convex_left.size();

	
	}

	res.push_back(convex_left[i]);

	/*
	cout << "included left" << endl;
	for (int i = 0; i < res.size(); i++){
		cout << res[i].first << " " <<res[i].second<< endl;
	}
	cout << "convex_right is " << endl;
	for (int i = 0; i < convex_right.size(); i++){
		cout << convex_right[i].first << " " << convex_right[i].second << endl;
	}
	*/
	for (int i = 0;i < convex_right.size(); i++){
		
		if(convex_right[i].first == xlowr && convex_right[i].second == ylowr ){
			index = i;
			break;
		}
	}

	while (convex_right[index].first != xhighr ||  convex_right[index].second != yhighr){
		res.push_back(convex_right[index]);
		index++;

		index = index % convex_right.size();
	}

	res.push_back(convex_right[index]);

	
}




		
			
	
	


	

	
	
		
	
	

void convexhull(vector<pair<int,int> >v,int n, int xmin, int xmax, vector<pair<int,int> > &res)
{
	//cout << "Called on " << xmin <<" " << xmax << endl;
	if(n == 0){
		return;
	}
	if(n == 1){
		res.push_back(v[0]);
		return;
	}
	if(n == 2){
		res.push_back(v[1]);
		res.push_back(v[0]);
		return;

	} /*else if (n == 3){
		int k = v[0].first;
		int flag = 0;
		for (int i = 1; i < n; i++){
			if(v[i].first != k){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			res.push_back(v[0]);
			res.push_back(v[2]);
			return;
		}
			
		res.push_back(v[1]);
		res.push_back(v[0]);
		res.push_back(v[2]);
		return;
	} */else {
		int flag = 0;
		int k = v[0].first;

		for (int i = 1; i < n; i++){
			if(v[i].first != k){
				flag = 1;
				break;
			}
		}

		if(flag == 0){
			
			res.push_back(v[0]);
			res.push_back(v[n-1]);
			return;
		} else {

			
			int xmid;
			xmid = (xmin+xmax)/2;
			vector<pair <int,int> > temp_left;
			vector<pair<int,int> > temp_right;

			int i = 0;
			
			while(v[i].first <= xmid){
				temp_left.push_back(v[i]);
				i++;
			}

			while(i < v.size()){
				temp_right.push_back(v[i]);
				i++;
			}

		

			vector<pair<int,int> > convex_left,convex_right;
		
			convexhull(temp_left,temp_left.size(),xmin,xmid,convex_left);

	/*		cout << "Left" << endl;
			for (int i = 0; i < convex_left.size(); i++){
				cout << convex_left[i].first << " " ;
			}
			cout << endl;   */

			convexhull(temp_right,temp_right.size(),xmid+1,xmax,convex_right);

			cout << "Right" << endl;
			for (int i = 0; i < convex_right.size(); i++){
				cout << convex_right[i].first << " ";
			}
			cout << endl;  

			cout << "Left is" << endl;

			for (int i = 0; i < convex_left.size(); i++){
				cout << convex_left[i].first<<" ";
			}
			cout << endl;  
			merge(convex_left,convex_right,res,v);
			
			cout << "After merge, res is " << endl;

			for (int i = 0; i < res.size(); i++){
				cout << res[i].first<<" " << res[i].second << endl;
			}
			cout << endl;   

			return;
		}
	}
}

			
			

			
			
		



int main()
{

	int n;
	cin >> n;

	int x,y;
	pair<int,int> p;

	vector<pair<int,int> > v;

	for (int i = 0; i < n; i++){
		x = rand()%100;
		y = rand()%100;
		cout << x << " " << y << endl;
	//	cin >> x >> y;
		p = make_pair(x,y);
		v.push_back(p);
	}

//	cout << "done" << endl;
	sort(v.begin(),v.end());
	int xmin = v[0].first;
	int xmax = v[n-1].first;
	
	vector<pair<int,int> > res;
//	cout << " calling" << endl;

	convexhull(v,n,xmin,xmax,res);

	cout << "Final answer is " << endl;

	for (int i = 0; i < res.size(); i++){
		cout << res[i].first << " " << res[i].second << endl;
	}

	return 0;
}

