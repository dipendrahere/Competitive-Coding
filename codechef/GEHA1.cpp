#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int cc(deque<int> q, int c){
	int v=0;
	deque<int> p = q;
	while(1){if(p.size()==0)break;
		if(c == p.front()){
			v++;
		}
		p.pop_front();
	}
	return v;
}
bool check(vector<int> &v){
	int n = v.size();
	bool a, b, c;
	deque<int> u;
	a = 1;
	b=1;
	c=1;
	int w = 0;
	deque<int> q;
	
	if(n == 3||n==2){
		if(n>=2){
	q.clear();
	q.pb(v[0]);
	for(int i =1;i<n;i++){
		q.pb(v[i]);
		if(i!=1){
			q.pop_front();
		}
		//cout<<"here"<<cc(q, 1)<<endl;
		if(cc(q, 1) >= 2){
			b = 0;
			return false;
			break;
		}
	}
	}
		q.clear();
		for(auto i: v){
			q.pb(i);
		}
		if(cc(q, 0) >= 2 || cc(q, 2)>=3){

			return false;
		}
		return a&b&c;
	}
	if(n>=3){
	q.pb(v[0]);
	q.pb(v[1]);
	for(int i =2;i<n;i++){
		q.pb(v[i]);
		if(i!=2){
			q.pop_front();
		}
		if(cc(q, 0) >= 2){
			a = 0;return false;
			break;
		}
	}
	}
	if(n>=2){
	q.clear();
	q.pb(v[0]);
	for(int i =1;i<n;i++){
		q.pb(v[i]);
		if(i!=1){
			q.pop_front();
		}
		if(cc(q, 1) >= 2){
			b = 0;return false;
			break;
		}
	}
	}
	if(n>=4){
	q.clear();
	q.pb(v[0]);
	q.pb(v[1]);
	q.pb(v[2]);
	for(int i =3;i<n;i++){
		q.pb(v[i]);
		if(i!=3){
			q.pop_front();
		}
		if(cc(q, 2) > 2){
			c = 0;return false;
			break;
		}
	}
	}
	return a&b&c;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		for(int i =0;i<=n;i++){
			for(int j =0;j<=n;j++){
				int k = n-i-j;
				if(k < 0)continue;
				vector<int> v;
				for(int x =0;x<i;x++){
					v.pb(0);
				}
				for(int x=0;x<j;x++){
					v.pb(1);
				}

				for(int x=0;x<k;x++){
					v.pb(2);
				}
				do{
				if(check(v)){
					for(auto i: v){cout<<i<<" ";}cout<<endl;
					ans++;
				}}while(next_permutation(v.begin(), v.end()));
			}
		}
		cout<<ans<<endl;
	}
}
