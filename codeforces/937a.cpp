#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	set<int> s;
	int sc[1000]={0};
	while(t--){
		int temp;
		cin>>temp;
		if(temp == 0){
			continue;
		}
		s.insert(temp);
		sc[temp]++;
	}
	int ans = s.size();
	
	cout<<ans<<endl;
}
