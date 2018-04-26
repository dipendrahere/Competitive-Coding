#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	if(k > 100){
		cout<<"No\n";
	}
	else{
		set<int> s;
		for(int i = 1; i <= k; i++){
			s.insert(n%i);
		}
		if(s.size() == k){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}
