#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	//vector<pair<int, int> > v;
	int a[2000]={0};
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		for(int j =x; j <=y; j++){
			a[j] = max(a[j], y);
		}
	}
	//for(int i = 0; i < 20; i++){
	//	cout<<a[i]<<" ";
	//}
	//cout<<endl;
	int pos = 0;
	while(pos < m){
		if(a[pos] == pos){
			cout<<"NO\n";
			return 0;
			break;
		}
		else{
			pos = a[pos];
		}
	}
	cout<<"YES\n";
	return 0;
}
