#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		int flag = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]> 0){
				cout<<a[i]<<" ";
				flag = 1;
			}
		}
		if(flag == 0){
			int max = -1000000;
			for(int i=0;i<n;i++){
				if(a[i] > max){
					max = a[i];
				}
			}
			cout<<max<<endl;
		}
		cout<<endl;
	}
}
