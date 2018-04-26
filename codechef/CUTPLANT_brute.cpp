#include<bits/stdc++.h>
using namespace std;
bool check(int a[], int b[], int n){
	for(int i = 0; i < n;i++){
		if(b[i] > a[i])return false;
	}
	return true;
}
 
int rec(int a[], int b[], int s, int e){
	if(s > e)return 0;
	if(s == e){
		if(a[s] == b[e])return 0;
		a[s] = b[e];
		return 1;
	}
	int ind = -1;
	for(int i = s; i <= e; i++){
		if(a[i] != b[i]){
			ind = i;
			break;		
		}
	}
	if(ind == -1)return 0;
	int l = ind;
	int x = b[ind];
	int r = ind;
	for(int i = ind+1; i <= e; i++){
		if(b[i] > x || a[i] < x){
			break;
		}
		r = i;
	}
	cout<<"making "<<l<<" to "<<r<<" "<<x<<endl;
	for(int i = l; i <= r; i++){
		a[i] = x;
	}
	return 1+rec(a, b, l+1, e);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		for(int i = 0; i < n;i++){
			cin>>a[i];
		}
		int b[n+2];
		for(int i = 0; i< n;i++){
			cin>>b[i];
		}
		if(!check(a, b, n)){
			cout<<"-1\n";
		}
		else
			cout<<rec(a, b, 0, n-1)<<endl;
	}
}
