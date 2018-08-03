#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+2];
	int m;
	cin>>m;
	memset(a, 0, sizeof(a));
	for(int i=0;i<m;i++){
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		for(int i=l;i<=r;i++){
			a[i]++;
		}
	}
	sort(a, a+n);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int k;
		cin>>k;
		if(k > a[n-1]){
			cout<<0<<endl;
			continue;
		}
		else if(k <= a[0]){
			cout<<n<<endl;
			continue;
		}
		auto x = lower_bound(a, a+n, k);
		if(*x == k){
			int y = x-a;
			cout<<n-y<<endl;
		}
		else{
			int y = x-a;
			cout<<n-y<<endl;
		}
	}
}
