#include<bits/stdc++.h>
using namespace std;
#define pb push_back
set<int> tell;
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
int ff(vector<int> a, int st, int end){
	int ans = -1;
	int vs = a[st];
	int ve = a[end];
	ans = max(vs, ve);
	while(ve >= 1){
		end--;
		ve--;
	}
	while(st+1 <= end){
		st++;
		vs++;
	}
	// while(end > st){
	// 	st++;
	// 	vs++;
	// 	if(a[end]!=1){
	// 		ve--;
	// 		end--;
	// 	}
	// 	if(st<end)
	// 	ans = max(ans, max(vs, ve));
	// }
	return max(ans, max(vs, ve));
}
bool down(vector<int> b){
	for(int i = 0; i < b.size()-1;i++){
		if(b[i+1]-b[i] <= 0){
			return true;
		}
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		tell.clear();
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
		tell.insert(mx);
		tell.insert(mx+1);
		tell.insert(mx+n-1-id);
		for(int i = 2; i*i < n-1-id;i++){
			tell.insert(i+mx);
		}
		int st = -1;
		for(int i = 0; i < n; i++){
			if(a[i]!=-1 && st != -1){
				tell.insert(ff(a, st, i));
				//cout<<st<<" "<<i<<" got: "<<ff(a, st, i)<<endl;
				st = -1;
			}
			if(a[i] != -1 && i != n-1 && a[i+1] == -1){
				st = i;
			}
		}
		if(c ==0 || c == 1){
			cout<<"inf\n";
		}
		else{
			int flag = 0;
			int ck = 0;
			int ans = -1;
			for(auto i: tell){
				vector<int> b = make(i, id, a[id], n);
				if(check(b, a)){
					//cout<<"ok for "<<i<<endl;
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
				vector<int> b = make(ans, id, a[id], n);
				if(down(b))
					cout<<ans<<endl;
				else{
					cout<<"inf\n";
				}
			}
		}
	}
}
