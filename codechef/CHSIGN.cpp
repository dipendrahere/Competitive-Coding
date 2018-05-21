#include<bits/stdc++.h>
using namespace std;
struct val{
	int v;
	int ind;
};
struct comp{
    bool operator() (const struct val& lhs, const struct val& rhs) const {
    	return lhs.v > rhs.v;
    }
};
struct val make(int a, int b){
	struct val temp = {a, b};
	return temp;
}
bool check(int gr, int sm1, int sm2){
	if(gr > sm1 + sm2){
		return true;
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n == 1){
			int k;
			cin>>k;
			cout<<-1*k<<"\n";
			continue;
		}
		else if(n == 2){
			int a, b;
			cin>>a>>b;
			if(a > b){
				b = -1*b;
			}
			else if(a < b){
				a *=-1;
			}
			cout<<a<<" "<<b<<endl;
			continue;
		}
		int a[n+2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		multiset<struct val, comp> s; 
		for(int i = 0; i < n; i++){
			if(i == 0){
				if(a[i] < a[i+1]){
					s.insert(make(a[i], i));
				}
			}
			else if(i == n-1){
				if(a[i] < a[i-1]){
					s.insert(make(a[i], i));
				}
			}
			else if(a[i] <= a[i-1] && i[a] < a[i+1]){
				s.insert(make(a[i], i));
			}

		}
		int h[100500] = {0};
		for(auto x : s){
			int i = x.ind;
			if(i == 0 || i == 1){
				if(h[i+1] == 0){
					if(h[i+2] == 0 || check(a[i+1], a[i], a[i+2])){
						h[i] = 1;
					}
				}
			}
			else if(i == n-1 || i == n-2){
				if(h[i-1] == 0){
					if(h[i-2] == 0 || check(a[i-1], a[i], a[i-2])){
						h[i] = 1;
					}
				}
			}
			else if(h[i-1] == 0 && h[i+1] == 0){
				if(h[i-2] == 0 && h[i+2] == 0){
					h[i] = 1;
				}
				else if(h[i-2] !=0 && h[i+2] != 0){
					if(check(a[i-1], a[i-2], a[i]) && check(a[i+1], a[i+2], a[i])){
						h[i] = 1;
					}
				}
				else if(h[i-2] == 0 && h[i+2] != 0){
					if(check(a[i+1], a[i+2], a[i])){
						h[i] = 1;
					}
				}
				else if(h[i-2] != 0 && h[i+2] == 0){
					if(check(a[i-1], a[i-2], a[i])){
						h[i] = 1;
					}
				}
			}
			else{
				continue;
			}
		}
		for(int i = 0; i < n; i++){
			if(h[i] == 1){
				cout<<-1*a[i]<<" ";
			}
			else{
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
