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
		int oc = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			if(a[i] != -1){
				c++;
			}
			if(a[i] == 1){
				oc++;
			}
		}
		if(oc == n){
			cout<<"1\n";continue;
		}
		int flag = -1;
		int down = 0;
		int yu = -1;
		if(c >= 2){
			int id = -1;
			int val;
			for(int i = n-1; i >=0; i--){
				if(a[i]!=-1){
					id = i;
					val = a[i];
					break;
				}
			}
			
			for(int i = id; i>= 0; i--, val--){
				//cout<<"at "<<val<<" "<<i<<endl;
				if(val == 0){
					
					int r = 0;
					int v = 0;
					if(1){
						if(a[i]!=yu && a[i]!=-1){
							flag = 1;break;
						}
						else{
							break;
						}
					}
					for(int j = i; j >= 0; j--, r++){
						if(a[j]!=-1){
							down = 1;
							v=a[j];
							break;
						}
					}
					
					val = r+v;yu = max(yu, val);
					//cout<<"was zero at "<<i<<" now "<<val<<endl;
				}
				if(a[i] == -1){
					continue;
				}
				else if(a[i]!=val){
					if(i == 0){
						if(a[i]!=yu){
							flag = 1;break;
						}
						else{
							break;
						}
					}
					flag = 1;
					//cout<<"here at"<<i<<" "<<val<<endl;
					break;
				}
			}
			if(flag == 1){
				cout<<"impossible\n";
			}
			else if(down == 0){
				cout<<"inf\n";
			}
			else{
				cout<<yu<<endl;
			}
		}
		else if(c == 0 || c == 1){
			cout<<"inf\n";
		}
	}
}
