#include<bits/stdc++.h>
#define ll long long
ll f[10050001];
ll a[10050001];
using namespace std;
void cal(){
	f[1] = 1;
	for(int i = 2; i <=  10000000; i++){
		for(int j = i; j <= 10000000; j+=i){
			f[j]+=i;
		}
	}
}
void val(){
	a[0] = 0;
	a[1] = 0;
	for(int i=2;i<=10000000;i++){
		a[i] = a[i-1]+f[i]+1;
	}
}
int main(){
	memset(f, 0, sizeof(f));
	cal();
	val();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
}
