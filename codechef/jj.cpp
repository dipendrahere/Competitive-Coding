#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rec(int n, int k){
	if(n == 1 && k >= 0){
		return -1;
	}
	if(k == 0){
		return n;
	}
	if(n%2 == 0){
		if(k == 1){
			return n-2;
		}
		else{
			return rec(n/2, k-2);
		}
	}
	else{
		if(n == 3 && k == 1){
			return 2;
		}
		else if(n == 3){
			return -1;
		}
		n = n-1;
		return rec(n, k);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		ll rest = rec(n, k);
		if(n == 2){
			cout<<"0.500000\n";
			continue;
		}
		if(k > 100){
			cout<<"1.000000\n";
		}
		if(rest == -1){
			cout<<"1.000000\n";
		}
		else{
			printf("%.6f\n",1.00/(rest+0.0));
		}
	}
}
