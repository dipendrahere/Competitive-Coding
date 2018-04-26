#include<bits/stdc++.h>
using namespace std;
#define ll long long
multiset<ll>s2;
multiset<ll, greater < ll > >s1;
int main(){
	int t;
	cin>>t;
	int flag = 0;
	while(t--){
		ll n;
		cin>>n;
		long double ans;
		if(flag == 0){
			flag = 1;
			s1.insert(n);
			printf("%0.1lf\n", n+0.0);
			continue;
		}
		else if(flag == 2){
			printf("%0.1lf\n", (0.0+n+*s1.begin())/2.0);
			flag = 2;
			if(n > *s1.begin()){
				s2.insert(n);
			}
			else{
				s2.insert(*s1.begin());
				s1.erase(s1.begin());
			}
			continue;
		}
		else{
			if(n > *s1.begin()){
				s2.insert(n);
			}
			else{
				s1.insert(n);
			}
			if(s2.size() > s1.size()){
				s1.insert(*s2.begin());
				s2.erase(s2.begin());
			} 
			else if(s1.size() > s2.size() + 1){
				s2.insert(*s1.begin());
				s1.erase(s1.begin());
			}
		}
		if(s1.size() > s2.size()){
			printf("%0.1lf\n", *s1.begin() + 0.0);
		}	
		else{
			printf("%0.1lf\n", (*s2.begin() + *s1.begin() + 0.0)/2.0 );
		}
		//for(auto i : s1)cout<<i<<"  ";cout<<"&& ";for(auto i : s2)cout<<i<<" ";cout<<s1.size()<<" "<<s2.size()<<endl;
	}
}
