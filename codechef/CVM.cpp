#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string o;
		cin>>o;
		string t;
		cin>>t;
		s = s+t;
		int n = s.size();
		vector<int> nums;
		string num = "";
		for(int i=1;i<n;i++){
			if((s[i] == '(' || s[i]==')' || s[i]==' ' || s[i] == '/')){
				if(num != "")
				nums.pb(stoi(num));
				num = "";
			}
			else{
				num.pb(s[i]);
			}
		}
		long a = nums[0]*nums[3];
		long b = nums[2]*nums[1];
		int g = __gcd(a, b);
		a = a/g;
		b= b/g;
		cout<<a<<" "<<b<<endl;
	}
	
}
