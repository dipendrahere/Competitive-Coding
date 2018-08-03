#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v;
	int s = 0;
	int flag = 0;
	int y;
	for(int i=0;i<n;i++){
		cin>>y;
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	int i=0,j=1;
	for(;i<n;i++){
		for(;j<n;j++){
			if(v[j]>v[i]){
				s++;
				j++;
				break;
			}
			if(j == n-1){
				flag =1;
			}
		}
		if(flag){
			break;
		}
	}
	cout<<s<<endl;
}
