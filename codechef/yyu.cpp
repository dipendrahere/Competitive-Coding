#include<bits/stdc++.h>
using namespace std;
vector<int> make(int mx, int id, int u, int size){
	int val;
	vector<int> v;
	val = u;
	for(int i = 0; i < size;i++){
		v.push_back(0);
	}
	for(int i = id; i < size;i++, val++){
		if(val > mx){
			val = 1;
		}
		v[i] = val;
	}
	val = u;
	for(int i = id; i >= 0; i--, val--){
		if(val == 0){
			val = mx;
		}
		v[i] = val;
	}
	// cout<<"for "<<mx<<" : ";
	// for(auto i: v){
	// 	cout<<i<<" ";
	// }cout<<endl;
	return v;
}
bool check(vector<int> b, vector<int> a){
	for(int i = 0; i < a.size();i++){
		if(a[i] == -1){
			continue;
		}
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a;
		int c = 0;
		int mx = -1;
		int id = -1;
		for(int i = 0 ;i < n;i++){
			int l;
			cin>>l;
			a.push_back(l);
			if(a[i]!=-1){
				id = i;
				c++;
			}
			mx = max(mx, a[i]);
		}	
		//cout<<id<<endl;
		if(c ==0 || c == 1){
			cout<<"inf\n";
		}
		else{
			int flag = 0;
			int ck = 0;
			int ans = -1;
			for(int i = mx; i <= mx+n; i++){
				vector<int> b = make(i, id, a[id], n);
				if(check(b, a)){
					ck++;
					ans = i;
					if(ck > 2){
						flag = 1;
						break;
					}
				}
			}
			if(flag == 1){
				cout<<"inf\n";
			}
			else if(ans == -1){
				cout<<"impossible\n";
			}
			else{
				cout<<ans<<endl;
			}
		}
	}
}
