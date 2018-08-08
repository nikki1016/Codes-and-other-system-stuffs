#include<iostream>
//#include<unordered_map>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	int i;
	for(i =0; i<n; i++){
		cin >> arr[i];
	}
/*	unordered_map<int,int> mapp = new unordered_map<int,int>();
	for(i =0; i<n; i++){
		if(mapp.contains(arr[i])){
			mapp.at(arr[i])++;
			if(mapp.at(arr[i])  == n/2){
				cout << arr[i] << endl;
				break;
			}
		}
		else {
			mapp[arr[i]] = 1;
		}
	}
	if(i == n ) cout << "NONE" << endl;*/
	/** Moore's voting algo**/
	int majind = 0,count = 1;
	for(i =1; i<n; i++){
		if(arr[majind] == arr[i]) count++;
		else count--;
		if(count == 0){
			majind  = i;
			count = 1;
		}
	}
	
		count = 0;
		for(i =0; i<n; i++){
			if(arr[i] == arr[majind] ) 
				count++;
		}
		if(count > n/2)
			cout << arr[majind]<<endl;
		else cout<< "NONE" << endl;
	
	return 0;	
}
