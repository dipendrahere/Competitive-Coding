#include<bits/stdc++.h>
using namespace std;
vector<int> arr[5000+10];
bool isleaf(int i){
	if(arr[i].size() == 0){
		return true;
	}
	return false;
}
bool achha(int i){
	int count = 0;
	bool ans = true;
	for(auto x:arr[i]){
		if(isleaf(x)){
			count++;
		}
		else{
			ans = ans && achha(x);
		}
	}
	if(count>=3 && ans == true){
		return true;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int temp;
		cin>>temp;
		arr[temp].push_back(i);
	}
	if(achha(1)){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}
