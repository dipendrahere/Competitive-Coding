#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin>>n;
	int count = 0;
	while(n--){
		ll x;
		cin>>x;
		bitset<65> b(x);
		if(x == 1 || x == 0){
			continue;
		}
		else{
			int c = 0;
			for(auto i : b.to_string()){
				if( i == '1' ){
					c++;
					if(c > 2)break;
				}
			}
			if(c == 1 || c == 2){
				count++;
			}
		}
	}
	cout<<count<<endl;
}
