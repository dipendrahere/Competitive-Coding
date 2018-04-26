
/* 





WRONG




*/


#include<bits/stdc++.h>
using namespace std;

bool suffix(string a, string b){
	if(a.size() > b.size())return false;
	for(int i = a.size()-1, j=b.size()-1; i >=0; i--, j--){
		if(a[i]!=b[j])return false;
	}
	return true;
}
vector<string> filter(vector<string> a){
	set<string> ret;
	
	for(int i = 0 ; i< a.size();i++){
		int flag = 0;
		for(int j = 0; j < a.size();j++){
			if(i == j){
				continue;
			}
			
			if(suffix(a[i], a[j])){
				flag = 1;
				continue;
			}
		}
		if(flag == 0)
		ret.insert(a[i]);
	}
	vector<string> r;
	for(auto t : ret){
		r.push_back(t);
	}
	return r;
}
int main(){
	int n;
	cin>>n;
	map<string, vector<string> > m;
	while(n--){
		string temp;
		cin>>temp;
		map<string, vector<string> >::iterator it = m.find(temp);
		if(it== m.end()){
			int c;
			cin>>c;
			vector<string> cns;
			while(c--){
				string yy;
				cin>>yy;
				cns.push_back(yy);
			}
			m.insert(pair<string, vector<string> >(temp, filter(cns)));
		}
		else{	
			int c;
			cin>>c;
			set<string> cns = it->second;
			while(c--){
				string yy;
				cin>>yy;
				cns.insert(yy);
			}
			vector<string> tt;
			for(auto r: cns){
				tt.push_back(r);
			}
			it->second = filter(tt);			
		}
	}
	cout<<m.size()<<endl;
	for(auto a: m){
		cout<<a.first<<" "<<a.second.size()<<" ";
		for(auto u:a.second){
			cout<<u<<" ";
		}
		cout<<endl;
	}
}
