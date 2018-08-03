#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minl(ll a, ll b){return a<b?b:a;}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		ll a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		deque<ll> q;
		ll sum = 0;
		ll max = 0;
		ll ans = 0;
		for(int i = 0;i<n;i++){
			q.push_back(a[i]);
			sum+=a[i];
			while(sum > k){
				sum-=q.front();
				q.pop_front();
			}
			if(q.size() > max){
				max = q.size();
				ans = sum;
			}
			else if(q.size() == max){
				ans = minl(ans, sum);
			}
		}
		cout<<max<<" "<<k-ans<<endl;
	}
}
