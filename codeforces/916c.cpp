#include<bits/stdc++.h>
using namespace std;
bool prime[1005000];
#define mp make_pair
void sieve(){
	memset(prime, true, sizeof(prime));
	for (int p=2; p*p<=1005000; p++){
        if (prime[p] == true){
            for (int i=p*2; i<=1005000; i += p)
                prime[i] = false;
        }
    }
}
void printr(vector<struct nns> v){
	for(auto i : v){
		cout<<i.a<<" "<<i.b<<i.w<<endl;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> arr;
	sieve();
	for(int i=2;i<1005000;i++){
		if(prime[i]){
			arr.push_back(i);
		}
	}
	int near = *lower_bound(arr.begin(), arr.end(), n-1);
	cout<<near<<" "<<near;
	vector< pair <int, pair< int, int > > > v;
	vector<int> gr[n+2];
	for(int i = 1; i < n-2; i++){
		v.push_back(mp(i, mp, (i+1, 1)));
		gr[i].push_back(i+1);
	}
	v.push_back(mp(n-1, np(n, )))
}
