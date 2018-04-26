#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long pows(long long a, long long b){
	a = a%MOD;
	long long res = 1;
	while(b > 0){
		if(b%2 == 0){
			a = (a*a)%MOD;
			b = b/2;
		}
		else{
			b--;
			res = (res*a)%MOD;
		}
	}
	return res%MOD;
}
int main(){
	long long w[20] = {0};
	for(int i = 10; i <= 99; i++){
		w[i%10 - i/10 + 10]++;
	}
	int t;
	cin>>t;
	while(t--){
		long long n;
		int wt;
		cin>>n;
		cin>>wt;
		if(wt > 9 || wt < -9){
			cout<<"0\n";continue;
		}
		else{
			long long ans = w[wt+10];
			ans = (ans * pows(10, n-2))%MOD;
			cout<<ans<<endl;
		}
	}
}
