#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2];
		int c = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			if(a[i] != -1){
				c++;
			}
		}
		if(c == 0 || c == 1){
			cout<<"inf\n";
		}
		else{
			int id;
			for(int i = n-1; i>=0; i--){
				if(a[i]!=-1){
					id = i;
					break;
				}
			}
			int b[n+2];
			memset(b, -1, sizeof(b));
			int val = a[id];
			int z = -1;
			for(int i = id; i >= 0 && val >= 0; i--, val--){
				if(val == 0){
					z = i;
					break;
				}
				b[i] = val;
			}
			int s = -1;
			if(z != -1){
				for(int i = z; i>=0; i--){
					if(a[i]!=-1){
						s = i;
						break;
					}
				}
				if(s == -1){
					cout<<"inf\n";
					continue;
				}
				int ans = max(a[id], a[s]+z-s);
				for(int i = id, val = a[id]; i >= 0; i--, val--){
					if(val == 0){
						val = ans;
					}
					b[i] = val;
				}
				int done = 0;
				for(int i = 0; i < n; i++){
					if(a[i] == -1){
						continue;
					}
					else if(a[i]!=b[i]){
						done = 1;
						cout<<"impossible\n";
						break;
					}
				}
				if(done == 0){
					cout<<ans<<endl;
				}
			}
			else{
				int flag = 0;
				for(int i = 0; i < n; i++){
					if(a[i] == -1){
						continue;
					}
					else if(a[i]!=b[i]){
						flag = 1;
						cout<<"impossible\n";
						break;
					}
				}
				if(flag == 0){
					cout<<"inf\n";
				}
			}
		}
	}
}
