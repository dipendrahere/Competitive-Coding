#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int f= 0;
	int a, b;
	a=0;
	b=0;
	while(n--){
		int x, y;
		cin>>x>>y;
		if(x > 0){
			a++;
		}
		else{
			b++;
		}
	}
	if(a==1||b==1 || a ==0 || b == 0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
