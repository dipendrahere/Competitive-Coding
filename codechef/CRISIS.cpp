#include<bits/stdc++.h>
using namespace std;
float rec(int a[], int n, int x, int abhitk, int csum){
	if(n == 0)
	float v = 0;
	int ind = n;
	int sc = a[n-1];
	float mx = 0;
	for(int i = x; i<=n;i++){
		float v = max(rec(a, n-1, i-1, abhitk+sc*ind, csum+ind), rec(a, n-1, i, abhitk, csum));
		if(v > mx){
			mx = v;
		}
	}
	return mx;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		int a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<rec(a, n, x);
	}
}