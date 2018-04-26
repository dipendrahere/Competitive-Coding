#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;

	cin>>a>>b>>c;
	a = a%b;
	int tt = 0;
	while((a*10)/b != c && tt < 1000000){
		a = (a*10)%b;
		tt++;
	}
	if(tt == 1000000){
		cout<<"-1\n";
		return 0;
	}
	cout<<tt+1<<endl;
}
