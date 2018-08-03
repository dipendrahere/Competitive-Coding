#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int flag = 0;
		for(int i=0;i<n;i++){
			if(a[i] == 1){
				continue;
			}
			for(int j=0;j<n;j++){
				if(a[i] == a[j]){
					continue;
				}
				else if(__gcd(a[i], a[j]) == 1){
					flag = 1;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(flag){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
