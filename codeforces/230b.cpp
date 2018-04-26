#include<bits/stdc++.h>
using namespace std;
bool prime[1000030];
void sieve(){
	for(int i =2; i*i <= 1000030; i++){
		if(prime[i]){
			for(int j = 2*i; j <= 1000030; j+=i){
				prime[j] = false;
			}
		}
	}
}
int main(){
	memset(prime, true, sizeof(prime));
	sieve();
	int n;
	cin>>n;
	long x;
	for(int i =0;i<n;i++){
		cin>>x;
		if(x == 1){cout<<"NO\n";continue;}
		long t = (long)sqrt(x);
		if(t*t == x){
			if(prime[t]){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
		else{
			cout<<"NO\n";
		}
	}
}
