#include<bits/stdc++.h>
using namespace std;
int p[10000002];
vector<long long> pr;
void sieve(){
	for(int i=2;i<10000002;i++){
		if(p[i] == -1){
			for(int j=i+i;j<10000002;j+=i){
				p[j]=1;
			}
		}
	}
	for(int i=2;i<10000002;i++){
		if(p[i] == -1){
			pr.push_back(i+0LL);
		}
	}
}
int main(){
	memset(p, -1, sizeof(p));
	sieve();
	int n,k;
	cin>>n>>k;
	multiset<int, greater<int> > s;
	for(int i=0;i<n;i++){
		long long t;
		cin>>t;
		s.insert(t);
	}
	
	long long ans = 0;
	for(int i=0;i<k;i++){
		long long v = *s.begin();
		ans += v;
		s.erase(s.begin());
		if(v == 0 || v == 2 || v == 1){
			s.insert(0);
			continue;
		}
		auto ptr = lower_bound(pr.begin(), pr.end(), v);
		long long l = ptr-pr.begin();
		s.insert(l);
	}
	cout<<ans<<endl;
}
