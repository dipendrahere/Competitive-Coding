#include <bits/stdc++.h>
using namespace std;
bool prime[1000010];
void sieve(){
	int n = 1e6+9;
	memset(prime, true, sizeof(prime));
	for (int p=2; p*p<=n; p++)
	{
		if (prime[p] == true)
		{
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}
	return;
}
int main() {

	long n;
	cin>>n;

	sieve();
	vector<int> pr;
	for(int i=2;i<1000007;i++){
		if(prime[i] == true){
			pr.push_back(i);
		}
	}
	long temp = n;
	map<int,int> m;
	for(vector<int>::iterator it = pr.begin();it!=pr.end();it++){
		int count=0;
		while(temp%(*it)==0){
			count++;
			temp=temp/(*it);
		}
		if(count > 0){
			m.insert(pair<int, int>(*it, count));
		}
	}
	if(temp>1){
		m.insert(pair<int, int>(temp,1));
	}

	int count=0;
	vector<int> ans;
	long long val1=1,val2=1;
	for(map<int, int>::iterator it = m.begin();it!=m.end();it++){
		val1 *= (2*(it->second)+1);
		val2 *= ((it->second)+1);       
	}
	val1++;
	val1/=2;
	val1-=val2;
	cout<<val1<<endl;

	return 0;
}
