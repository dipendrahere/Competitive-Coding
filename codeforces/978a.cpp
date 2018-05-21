#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	set<int> s;
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		s.insert(temp);
		v.push_back(temp);
	}
	vector<int> ans;
	for(auto i = v.rbegin(); i != v.rend(); i++){
		if(s.find(*i) != s.end()){
			ans.push_back(*i);
			s.erase(*i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto i = ans.rbegin(); i != ans.rend(); i++){
		cout<<*i<<" ";
	}
	cout<<endl;
}
