#include<bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b){
	if(b == 0){
		return 1;
	}
	long long res = 1;
	long long v = pow(a, b/2);
	if(b%2 == 0){
		res = v*v;
	}
	else{
		res = a*v*v;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	long long a[n+2];
	long long mx = -10;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] > mx){
			mx = a[i];
		}
	}
	sort(a, a+n);
	long long ans = 1;
	for(long long i = 2; i <= mx; i++){
		long long p = lower_bound(a, a+n, i)-a;
		long long value = n-p;
		value--;
		cout<<i<<" "<<value<<endl;
		if(value == -1){
			value = 0;
		}
		ans = ans*pow(i, value);
	}
	cout<<ans<<endl;
}
