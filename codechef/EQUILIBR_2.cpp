#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
ll fact[1000000];
void pre(){
	fact[0]=1;
	fact[1]=1;
	for(ll i = 2; i < 1000000;i++){
		fact[i] = ((fact[i-1]) * i)%mod;
	}
}
long long pow(ll a, ll b, ll m){
	a = a%m;
	ll res = 1;
	while(b > 0){
		if(b%2 == 1){
			b--;
			res = (a*res)%mod;
		}
		else{
			b = b/2;
			a = (a*a)%mod;
		}
	}
	return res;
}
int main(){
	unsigned long long n, k;
	cin>>n>>k;
	pre();
	int id = -1;
	int val = 574218755;
	for(int i = 1; i <= 3*1000000; i++){
	n = i;
	ll num = (pow(2, n-1, mod) - n)%mod;
	cout<<num<<" ";
	ll den = (pow(2, n-1, mod))%mod;
	ll ans = (num * pow(den, mod-2, mod))%mod;
	cout<<ans<<endl;
	if(ans == val){
		id = i;
	}
	}	
	cout<<"dig ="<< id<<endl;
}
