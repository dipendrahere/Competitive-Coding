#include<bits/stdc++.h>
using namespace std;
bool gt(int a, int b){
	return a>b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int m[n+2];
		int t[n+2];
		int mc = 0;
		int tc = 0;
		int ms = 0;
		int ts = 0;
		for(int i=0;i<n;i++){
			if(i&1){
				cin>>t[tc++];
				ts += t[tc-1];
			}
			else{
				cin>>m[mc++];
				ms += m[mc-1];
			}
		}
		if(ts > ms){
			cout<<"YES\n";
			continue;
		}
		sort(m, m+mc, gt);
		sort(t, t+tc);
		for(int i = 1; i < tc; i++){
			t[i] = t[i-1]+t[i];
		}
		for(int i = 1; i < mc; i++){
			m[i] = m[i-1]+m[i];
		}
		int flag = 0;
		int mn = min(k, min(mc, tc));
		for(int i =0; i < mn; i++){
			if(ts-t[i]+m[i]>ms-m[i]+t[i]){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
