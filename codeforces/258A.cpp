#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string ans;
	int f = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i]=='0' && f==0){
			f++;
			continue;
		}
		ans.push_back(s[i]);
	}
	if(f==0){
		ans.erase(0,1);
		cout<<ans<<endl;
		return 0;
	}
	cout<<ans<<endl;
}
