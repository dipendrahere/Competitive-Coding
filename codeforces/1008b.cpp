#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;int flag = 1;
	cin>>n;
	int mx = 0;
	int y, u;
	cin>>y>>u;
	mx = max(y,u);
	for(int i=1;i<n;i++){
		int x, y;
		cin>>x>>y;
		if(min(x, y) > mx){
			flag = 0;
			break;
		}
		if(max(x, y) > mx){
			mx = x>mx?y:x;
		}
		else{
			mx = max(x,y);
		}
	}
	if(flag){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
