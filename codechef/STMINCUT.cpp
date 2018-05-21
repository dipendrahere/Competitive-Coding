#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2][n+2];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		int val = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] != a[j][i]){
					int m = max(a[i][j], a[j][i]);
					val += abs(a[i][j]-m)+abs(a[j][i]-m);
					a[i][j] = a[j][i] = m;
				}
			}
		}
		cout<<val<<endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n;j++){
				if(i == j){
					continue;
				}
				int v = 0;
				for(int k = 0; k <n;k++){
					v = min(v, a[i][k]+a[k][j]);
				}
				if(v < a[i][j]){
					val+= abs(v-a[i][j]);
					a[i][j] = v;
				}
			}
		}
		cout<<val<<endl;
	}
}
