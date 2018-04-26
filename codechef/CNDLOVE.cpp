#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long sum = 0;
		int temp;
		for(int i=0;i<n;i++){
		cin>>temp;
		sum+=temp;
		}
		if(sum%2 == 0){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}
