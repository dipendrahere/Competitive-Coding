#include<bits/stdc++.h>
using namespace std;
bool legit(int vl){
	int ret = 0;
	while(vl){
		ret+=(vl%10);
		vl=vl/10;
	}
	if(ret == 10)return true;
	return false;;
}
int main(){
	int n;
	cin>>n;
	vector <int> v;
	int st = 19;
	//v.push_back(st);
	int vl=19;
	for(int i=1;i<10020;i++){
		
		if(legit(vl)){
			v.push_back(vl);
			vl+=9;
		}
		while(!legit(vl)){
			vl=vl+9;
		}
	}
	cout<<v[n-1]<<endl;;
}
