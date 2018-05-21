#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
	return a>b?b:a;
}
int main(){
	int n;
	cin>>n;
	string a, b, c;
	cin>>a;
	cin>>b;
	cin>>c;
	int ma, mb, mc;
	ma = mb = mc = -10;
	map<char, int> mp;
	for(auto i : a){
		mp[i]++;
	}
	for(auto i : mp){
		if(i.second > ma){
			ma = i.second;
		}
	}
	mp.clear();

	for(auto i : b){
		mp[i]++;
	}
	for(auto i : mp){
		if(i.second > mb){
			mb = i.second;
		}
	}
	mp.clear();

	for(auto i : c){
		mp[i]++;
	}
	for(auto i : mp){
		if(i.second > mc){
			mc = i.second;
		}
	}
	mp.clear();
	if(n == 1){
		if(ma == a.size()){
			ma--;
		}
		else{
			ma++;
		}
		if(mb == b.size()){
			mb--;
		}
		else{
			mb++;
		}
		if(mc == c.size()){
			mc--;
		}
		else{
			mc++;
		}
		if(ma > mb && ma > mc){
		cout<<"Kuro\n";
	}
	else if(mb > mc && mb > ma){
		cout<<"Shiro\n";
	}
	else if(mc > ma && mc > mb){
		cout<<"Katie\n";
	}
	else{
		cout<<"Draw\n";
	}
	return 0;
	}
	ma = min(a.size(), ma+n);
	mb = min(b.size(), mb+n);
	mc = min(c.size(), mc+n);
	if(ma > mb && ma > mc){
		cout<<"Kuro\n";
	}
	else if(mb > mc && mb > ma){
		cout<<"Shiro\n";
	}
	else if(mc > ma && mc > mb){
		cout<<"Katie\n";
	}
	else{
		cout<<"Draw\n";
	}

}
