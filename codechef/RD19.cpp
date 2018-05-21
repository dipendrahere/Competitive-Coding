#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		cin>>a[0];
		int g = a[0];
		for(int i =1 ;i < n;i++){
			cin>>a[i];
			g = __gcd(g, a[i]);
		}
		if(g == 1){
			cout<<0<<endl;
		}
		else{
			cout<<"-1\n";
		}
	}
}
