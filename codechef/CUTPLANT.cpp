#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool check(int a[], int b[], int n){
	for(int i = 0 ; i < n;i++){
		if(b[i]>a[i])return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		int b[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		if(!check(a, b, n)){
			cout<<"-1\n";
			continue;
		}
		int idx = -1;
		for(int i = 0 ;i < n; i++){
			if(a[i]!=b[i]){
				idx = i;
				break;
			}
		}
		if(idx == -1){
			cout<<"0\n";
			continue;
		}
		vector<int> h;
		h.pb(b[idx]);
		int count = 0;
		for(int i = idx; i < n; i++){
			// cout<<endl;for(auto i :h)cout<<i<<" ";cout<<endl;
			// cout<<"i = "<<i<<" h = "<<h[h.size() -1]<<" count = "<<count<<endl;
			//if(h.size() == 0)cout<<"hello";cout<<endl;
			if(h.size() == 0){
				if(a[i]!=b[i]){
					h.pb(b[i]);
					continue;
				}
				else{
					continue;
				}
			}
			while(h.size() > 0 && h[0] > a[i]){
				h.erase(h.begin());
				count++;
			}
			int last = h.size()-1;
			if(h[last] > a[i]){
				count+=h.size();
				h.clear();
				if(b[i]!=a[i]){
					h.pb(b[i]);
				}
			}
			else if(h[last] < a[i] && h[last] > b[i]){
				h.push_back(b[i]);
			}
			else if(h[last] < a[i] && h[last] == b[i]){
				continue;
			}
			else if(h[last] < a[i] && h[last] < b[i]){
				while(h.size() > 0 && h[h.size()-1] < b[i]){ 
					h.pop_back();
					count++;
				}
				if(h.size() == 0){
					//h.pb(b[i]);
					if(b[i]!=a[i]){
						if(b[i] != h[h.size()-1])
						h.pb(b[i]);
					}
					continue;
				}
				else if(h[h.size()-1] == b[i]){
					continue;
				}
				else{
					h.pb(b[i]);
				}
			}
			else if(h[last] == a[i]){
				int u = h[h.size()-1];
				h.pop_back();
				count += h.size();
				h.clear();
				h.pb(u);
				if(a[i]!=b[i])
				h.pb(b[i]);
			}
		}
		if(h[h.size()] == b[n-1]){
			//count--;
		}
		// cout<<" ";
		// // for(auto i : h){
		// // 	cout<<i<<" "; 
		// // }
		// cout<<endl;
		cout<<h.size()+count<<endl;
	}
}
