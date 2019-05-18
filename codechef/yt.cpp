#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rec(ll n, ll k){
	if(k == 0){
		return n;
	}
	if(n == 1 || n == 0){
		return -1;
	}
	if(n == 2){
		return -1;
	}
	if(n%3 == 1 || n%3 == 0 || n%3 == 2){
		return rec(n/3 + n/3, k-1);
	}
	else{
		return rec(n - n/3, k-1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll k;
		cin>>k;
		if(k > 500){
			cout<<"1.0000000\n";
			continue;
		}
		if(n == 1){
			cout<<"1.0000000\n";
			continue;
		}
		if(n == 2){
			cout<<"0.50000000\n";
			continue;
		}
		ll rest = rec(n, k);
		if(rest == 0 || rest == -1){
			cout<<"1.0000000\n";
		}
		else{
			if(rest > 1e9){
				cout<<"0.0000000\n";
			}
			else
				printf("%.8f\n",1.00/(rest+0.0));
		}
	}
}
