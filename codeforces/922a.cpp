#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>y>>x;
	if(x == 1 && y == 0){cout<<"Yes\n";
	return 0;
}else if(x == 1 && y!=0){
	cout<<"No\n";return 0;
}
	int times = x-1;
	y = y-(x-1);
	if(x == 0){
		cout<<"No\n";
		return 0;
	}

	if(y >=0  && y%2 == 0){
		cout<<"Yes\n";
	}
	else
		cout<<"No\n";
}
