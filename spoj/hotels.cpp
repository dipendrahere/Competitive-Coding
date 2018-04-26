#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n;
	cin>>m;
	long long a[n+2];
	long long int s[n+2];
	memset(s, 0, sizeof(s));
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			s[0]=a[0];
		}
		else{
			s[i]=s[i-1]+a[i];
		}
	}
	long mx = 0;
	for(int i=0;i<n;i++){
		long long id = upper_bound(s, s+n,s[i]+m-a[i])-s;
		//cout<<id-1<<endl;
		if(mx < s[id-1]-s[i]+a[i]){
			mx = s[id-1]-s[i]+a[i];
		}
	}
	cout<<mx<<endl;
	return 0;
}
