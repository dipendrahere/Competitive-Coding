#include<bits/stdc++.h>
using namespace std;
#define mp make_pair

struct comp{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)const{
		return b.second > a.second;
	}
};
struct comp2{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)const{
		return b.second < a.second;
	}
};
set<pair<int, int>, comp> sm;
set<pair<int, int>, comp2> gt;
bool check(){
	auto i = sm.begin();
	int a = i->second;
	i++;
	int b = i->second;
	i = gt.begin();
	int c = i->second;
	return a+b>c;
}
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sm.clear();
	gt.clear();
	long long ans = 0;
	int st = 0;
	for(int i=0;i<n;i++){
		sm.insert(mp(i, a[i]));
		gt.insert(mp(i, a[i]));
		if(sm.size() < 2){
			ans += sm.size();
			continue;
		}
		else{
			while(sm.size() >= 3 && !check()){
				sm.erase(sm.find(mp(st, a[st])));
				gt.erase(sm.find(mp(st, a[st])));
				st++;
			}
			ans+=sm.size();
		}
	}
	cout<<ans<<endl;
}
