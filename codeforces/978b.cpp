#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans = 0;
	int count= 0;
	for(auto i : s){
		if(i == 'x'){
			count++;
		}
		else{
			if(count >= 3){
				ans+= (count - 2);
			}
			count = 0;
		}
	}
	if(count >= 3){
		ans+= (count - 2);
	}
	cout<<ans<<endl;
}
