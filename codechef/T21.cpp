#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string a, b;
		cin>>a;
		cin>>b;
		int n1 = 0;
		int n2 = 0;
		for(auto i: a){
			n1 = n1*10+(i-'0');
			n1 = n1%3;
		}
		for(auto i: b){
			n2 = n2*10+(i-'0');
			n2 = n2%3;
		}
		cout<<(n1*n2)%3<<endl;
	}
	return 0;
}
