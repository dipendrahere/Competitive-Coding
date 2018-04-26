#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<int> q;
	vector<int> a;
	for(int i=0;i<s.size();i++){
		if(s[i]=='Q'){
			q.push_back(i);
		}
		else if(s[i]=='A'){
			a.push_back(i);
		}
	}
	sort(q.begin(), q.end());
	sort(a.begin(), a.end());
	int ans = 0;
	
	for(int i = 0 ; i < q.size();i++){
		int j = (upper_bound(a.begin(), a.end(), q[i]) - a.begin());
		//cout<<"j"<<j<<endl;
		for(;j<a.size();j++){
			int k = (upper_bound(q.begin(), q.end(), a[j]) - q.begin());
			ans+= (q.size()-k);
		}
	}
	cout<<ans<<endl;
}
