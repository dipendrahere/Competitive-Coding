#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<string, int> mp;
		double f = 0.0;
		while(n--){
			string s;
			cin>>s;
			double ans = 0.0;
			int flag = -1;
			for(auto i: s){
				int now = 1;
				if(flag == -1 && (i == 'd' || i == 'f')){
					flag = 0;
					ans += 0.2;
					continue;
				}
				else if(flag == -1){
					flag = 1;
					ans+=0.2;
					continue;
				}
				if(i == 'd' || i == 'f'){
					now = 0;
				}
				if(now == flag){
					ans+=0.4;
				}
				else{
					ans+=0.2;
				}
				flag = now;
			}
			if(mp.find(s)==mp.end()){
				mp[s]++;
			}
			else{
				ans = ans/2.0;
			}
			f +=ans;
		}
		double y = f*10.0;
		cout<<y<<endl;
	}
}
