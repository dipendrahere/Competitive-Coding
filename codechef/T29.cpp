#include<bits/stdc++.h>
using namespace std;
/*https://www.commonlounge.com/discussion/d871499b49e443259cfbea9b16f9b958/1e99ce7e95dc44768a69c29476bfa083#query-in-merge-sort-tree*/
const long long maxn = 1e5+1000;
vector<long long> tree[4*maxn+100];
long long n, m, arr[maxn]; 
#define all(v) v.begin(), v.end()
#define mlong(x, y) x>y?y:x;
void build(long long node, long long l, long long r) {
	if(l == r) {
		tree[node].push_back(arr[l]);
		return;
	} 
	long long mid = l + r >> 1, 
	left = node << 1, right = left|1;
	
	build(left, l, mid);
	build(right, mid+1, r);
	
	merge(all(tree[left]), all(tree[right]), 
	        back_inserter(tree[node]));
}
long long query(long long node, long long l, long long r, long long i, long long j, long long k) {
	if(i > r || l > j) return 0;
	if(i <= l && r <= j) {
		auto uuu = lower_bound(all(tree[node]), k);
		auto yyy = upper_bound(all(tree[node]), k);
		if(*uuu == k){
			return uuu-tree[node].begin();
		}
		else if(*yyy == k){
			return yyy-tree[node].begin();
		}
		if(uuu == tree[node].begin()){
			return 0;
		}
		if(yyy == tree[node].end()){
			return yyy-tree[node].begin();
		}
		uuu--;
		yyy++;
		if(abs(*uuu - k) > abs(*yyy - k)){
			return yyy-tree[node].begin();
		}
		else if(abs(*uuu - k) < abs(*yyy - k)){
			return uuu-tree[node].begin();
		}
		else{
			if(*uuu > *yyy){
				return yyy-tree[node].begin();
			}
			else{
				return uuu-tree[node].begin();
			}
		}
	} 
	long long mid = l + r >> 1, 
		left = node << 1, right = left|1;
	return query(left, l, mid, i, j, k) + 
		   query(right, mid+1, r, i, j, k);
}
int main(){
	//cout<<"Y";
	cin>>n;
	long long q;
	//int y = 1e9;
	//cout<<y;
	cin>>q;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		arr[i] = 1e9L-arr[i];
	}
	build(1, 1, n);
	while(q--){
		long long l, r,k;
		cin>>l>>r>>k;
		long long x = query(1, 1, n, l, r, k);
		long long diff = 1e17;
		long long anss = 1e17;
		for(long long i = max(l+x-1000, l); i <= min(l+x+2*10000, r);i++){
			long long val = arr[i];
			if(abs(val - k) < diff){
				diff = abs(val-k);
				anss = 1e9L-val;
			}
			else if(abs(val - k) == diff){
				anss = mlong(anss, 1e9L-val);
			}
		}
		cout<<anss<<endl;
	}
}
