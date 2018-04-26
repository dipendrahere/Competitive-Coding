#include<bits/stdc++.h>
using namespace std;
int rec(int l, int n){
	if(n == 0){
		return 1; 
	}
	if(l == 0){
		return rec(1, n-1);
	}
	else{
		return rec(0, n-1)+rec(1, n-1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<rec(0, n-1)+rec(1, n-1)<<endl;
	}
}
