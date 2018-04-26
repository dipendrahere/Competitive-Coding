#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	int b[m+2];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int ans=0;
	sort(a, a+n);
	sort(b, b+m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(abs(a[i]-b[j]) <= 1){
				ans++;
				b[j] = 1000;
				break;
			}
		}
	}
	cout<<ans<<endl;return 0;
}
