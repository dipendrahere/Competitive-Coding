#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[200050]={0};
		int temp;
		int mx = -10;
		for(int i=0;i<n;i++){
			cin>>temp;
			a[temp]++;
			if(temp > mx){
				mx = temp;
			}
		}
		int w = 0;
		for(int i = 0; i<k;i++){
			w += a[i];
		}
		int ans = w;
		for(int i = 1; i < mx; i++){
			w = w-a[i-1]+a[i+k-1];
			ans = max(ans, w);
		}
		cout<<ans<<endl;
	}
}
