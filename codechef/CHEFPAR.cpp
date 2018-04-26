#include<bits/stdc++.h>
using namespace std;
int main(){
	long n,m,k;
	cin>>n>>m>>k;
	long a[n+2];
	int ans[4]={(k-2+k)%k,(6*k-6)%k,(19*k-19)%k,6};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
	}
	int t = -1;
	for(int i=0;i<n;i++){
		t++;
		t = t%4;
		cout<<a[i]+ans[t]<<" ";
	}
	cout<<endl;
}
