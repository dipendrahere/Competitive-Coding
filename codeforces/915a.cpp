#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int miin = INT_MAX;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(k%temp == 0 && k/temp < miin){
			miin = k/temp;
		}
	}
	cout<<miin<<endl;
}
