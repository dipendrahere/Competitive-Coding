#include<bits/stdc++.h>
using namespace std;
#define pb push_back
// 0 - work
// 1 - should not be changed
// 2 - want low
// 3 - want high
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long t;
	cin>>t;
	while(t--){
		long n, q;
		cin>>n>>q;
		map<long, long> mp;
		vector<long> a;
		vector<long> b;
		for(long i = 0; i < n; i++){
			long temp;
			cin>>temp;
			a.pb(temp);
			b.pb(temp);
			mp.insert(make_pair(temp, i));
		}
		sort(a.begin(), a.end());
		for(long i = 0; i < q;i++){
			long x;
			cin>>x;
			long less = lower_bound(a.begin(), a.end(), x) - a.begin();
			long more = n - 1 - less;
			long ind = mp[x];
			long low = 0;
			long high = n-1;
			long mid;
			long lc = 0;
			long hc = 0;
			while(low <= high){
				mid = (high+low)/2;
				if(mid == ind){
					break;
				}
				else if(mid > ind){
					high = mid - 1;
					if(b[mid] > x){
						more--;
						continue;
					}
					else{
						hc++;
					}
				}
				else{
					low = mid + 1;
					if(b[mid] < x){
						less--;
						continue;
					}
					else{
						lc++;
					}
				}
			}
			if(lc > less || hc > more){
				cout<<"-1\n";
				continue;
			}
			else{
				cout<<max(lc, hc)<<endl;
			}
		}
	}
}
