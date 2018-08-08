
# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>
# include <cstdio>

using namespace std;


double eqn(double a, double  b, double c, double d, double x, double y)
{
	if((x == a && y == b) || (x == c && y == d)){
		return 0.000;
	}
	double m;
	m = (double) (d-b)/(double) (c-a);
//	cout << "M" << m<<endl;
	double k;

	k = ((y - b) - (m * (x - a)));
	return k;
}

int mod(int a,int b)
{

	if(a == 0){
		a = b-1;
	} else {
		a--;
	}

	return a;
}
		                                                                                                                             
void merge(vector<pair<int,int> > convex_left, vector<pair<int,int> > convex_right,vector<pair<int,int> > &res){

	pair<int,int> left_right;
	pair<int,int> right_left;
	pair<int,int> left_right1;
	pair<int,int> right_left1;

	int max,min;
	max = -99999;
	min = 99999;

	int max_left,min_right,max_left1,min_right1;

	for (int i = 0; i < convex_left.size(); i++){
		if(convex_left[i].first > max){
			max = convex_left[i].first;
			max_left1 = max_left = i;
		}
	}

	left_right1 = 	left_right = convex_left[max_left];
	

	for (int i = 0; i < convex_right.size(); i++){
		if(convex_right[i].first < min){
			min = convex_right[i].first;
			min_right1 = min_right = i;
		}
	}

	right_left1 = right_left = convex_right[min_right];

	bool left = false; // for left polygon
	bool right = false;// for right polygon

	while(left == false || right == false){

		
		while(eqn(left_right.first,left_right.second,right_left.first,right_left.second,convex_left[(max_left+1) % convex_left.size()].first,convex_left[(max_left+1) % convex_left.size()].second) > 0.00){
			
					
			left_right = convex_left[(max_left+1) % convex_left.size()];
			max_left = (max_left+1) % convex_left.size();

		}	

		left = true;

	
		while(eqn(left_right.first,left_right.second,right_left.first,right_left.second,convex_right[mod(min_right,convex_right.size())].first,convex_right[mod(min_right,convex_right.size())].second) > 0.00){
			
			right_left = convex_right[mod(min_right,convex_right.size())];
			min_right = mod(min_right,convex_right.size());
			left = false;

		}

		right = true;
	}

	cout << "TEST UPPER DONE " << endl;


	bool left1 = false;
	bool right1 = false;

	while(left1 == false || right1 == false){
		
		

		while(eqn(left_right1.first,left_right1.second,right_left1.first,right_left1.second,convex_left[mod(max_left1,convex_left.size())].first,convex_left[mod(max_left1,convex_left.size())].second) < 0.00){			

//		cout << eqn(left_right1.first,left_right1.second,right_left1.first,right_left1.second,convex_left[mod(max_left1,convex_left.size())].first,convex_right[mod(max_left1,convex_left.size())].second) << endl;
	//	cout << "changing max_left1 for " << left_right1.first << " " << right_left1.first << endl;
			max_left1 = mod(max_left1,convex_left.size());
			left_right1 = convex_left[max_left1];
	//	cout << "new are" << left_right1.first << " " << right_left1.first << endl;
//		getchar();
		}

		left1 = true;

		while(eqn(left_right1.first,left_right1.second,right_left1.first,right_left1.second,convex_right[(min_right1+1) % convex_right.size()].first,convex_right[(min_right1+1)%convex_right.size()].second) < 0.00){
			

	//		cout << "changing min_right1 for " << left_right1.first << " " << right_left1.first << endl;
			min_right1 = (min_right1+1) % convex_right.size();
			right_left1 = convex_right[min_right1];
			left1 = false;
	//		cout << "new are" << left_right1.first << " " << right_left1.first << endl;
		}

		right1 = true;
	}

	cout << "TEST LOWER DONE" << endl;
	cout << " Finals are" << left_right.first << " " << right_left.first<< " " << left_right1.first << " " << right_left1.first << endl;

	int pos = max_left;

	while(pos != max_left1){
		res.push_back(convex_left[pos]);
		pos = (pos +1)%convex_left.size();
	}

	res.push_back(convex_left[pos]);

	pos = min_right1;

	while(pos != min_right){

		res.push_back(convex_right[pos]);
		pos = (pos+1) % convex_right.size();
	}

	res.push_back(convex_right[pos]); 

/*	int pos = min_right;
	while(pos != min_right1){
		res.push_back(convex_right[pos]);
		pos = mod(pos,convex_right.size());
	}
	
	res.push_back(convex_right[pos]);
	
	pos = max_left1;
	while(pos != max_left){
		
		res.push_back(convex_left[pos]);
		pos = mod(pos,convex_left.size());
	}
	res.push_back(convex_left[pos]); */

	
}
		
	
				

					





void convexhull(vector<pair<int,int> >v,int n, int min, int max, vector<pair<int,int> > &res)
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

	} else if (n == 3){

		int k = v[0].second - v[0].first;
		int flag = 0;
		for (int i = 1; i < n; i++){
			if(v[i].second - v[i].first != k){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			res.push_back(v[0]);
			res.push_back(v[2]);
			return;
		}
			
		int max_pos = 0;
		int maxi  = v[0].second;
		for (int i = 1; i < 3; i++){
			if(v[i].second > maxi){
				maxi = v[i].second;
				max_pos = i;
			}
		}

		res.push_back(v[max_pos]);
		
		int a,b;
		a = (max_pos+1) % 3;
		b = (max_pos+2) % 3;

		if(v[a].first < v[b].first){
			res.push_back(v[b]);
			res.push_back(v[a]);
		}  else {
			
			res.push_back(v[a]);
			res.push_back(v[b]);
		}
		
		
		return;
	} else {
		int flag = 0;
		int k = v[0].second - v[0].first;

		for (int i = 1; i < n; i++){
			if(v[i].second - v[i].first != k){
				flag = 1;
				break;
			}
		}

		if(flag == 0){
			
			res.push_back(v[0]);
			res.push_back(v[n-1]);
			return;
		} else {

			
			int mid;
			mid = (min+max)/2;
			cout << "mid" <<mid << endl;
	//		getchar();
			vector<pair <int,int> > temp_left;
			vector<pair<int,int> > temp_right;

			int i = 0 ;
			
			while(i < mid-min+1){
				temp_left.push_back(v[i]);
				i++;
			}
			

			while(i <= max-min){
				temp_right.push_back(v[i]);
				i++;
			}
			
			cout << "temp_left" << endl;

			for (int i = 0; i < temp_left.size(); i++){
				cout << temp_left[i].first <<" ";
			}

			cout << endl;

			vector<pair<int,int> > convex_left,convex_right;
		
			convexhull(temp_left,temp_left.size(),min,mid,convex_left);

			cout << "Left" << endl;
			for (int i = 0; i < convex_left.size(); i++){
				cout << convex_left[i].first << " " ;
			}

			cout << endl;   

			for (int i = 0; i < temp_right.size(); i++){
				cout << temp_right[i].first <<" " ;
			}

			cout << endl << mid+1 << " " << max << endl;

			convexhull(temp_right,temp_right.size(),mid+1,max,convex_right);

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
			merge(convex_left,convex_right,res);
			
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
	//	x = rand()%100;
	//	y = rand()%100;
	//	cout << x << " " << y << endl;
		cin >> x >> y;
		p = make_pair(x,y);
		v.push_back(p);
	}

//	cout << "done" << endl;
	sort(v.begin(),v.end());
	int min = 0;
	int max = n-1;
	
//	cout << eqn(62,27,63,26,49,21) << endl;
	vector<pair<int,int> > res;
//	cout << " calling" << endl;

	convexhull(v,n,min,max,res);

	cout << "Final answer is " << endl;

	for (int i = 0; i < res.size(); i++){
		cout << res[i].first << " " << res[i].second << endl;
	} 

	return 0;
}


