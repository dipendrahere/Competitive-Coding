#include<bits/stdc++.h>
using namespace std;
long long combine(long long a[], long long x[], long long st, long long mid, long long end){
	long long i=st, j=mid, k=st;
	long long ret = 0;
	while((i<=mid-1) && (j<=end)){
		if(a[i] >= a[j]){
			x[k++]=a[i++];
		}
		else{
			x[k++]=a[j++];
			ret+=(mid-i);
		}
	}
	while(i<=mid-1) x[k++]=a[i++];
	while(j<=end) x[k++]=a[j++];
	for(long long i = st; i<=end; i++){
		a[i]=x[i];
	}
	return ret;
}
long long rec(long long a[], long long x[], long long st, long long end){
	long long mid;
	long long ret = 0;
	if(end > st){
		mid = (end+st)/2;
		ret+=rec(a, x, st, mid);
		ret+=rec(a, x, mid+1, end);
		ret+=combine(a, x, st, mid+1, end);
	}
	return ret;
}
long long invCount(vector<long long> a){
	long long arr[a.size()+2];
	long long temp[a.size()+2];
	memset(temp, 0, sizeof(temp));
	for(long long i = 0;i < a.size();i++){
		arr[i] = a[i];
	}
	return rec(arr, temp, 0, a.size()-1);
}
int main(){
	long long t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		long long n = s.size();
		vector<long long> v;
		for(long long i=0; i<s.size(); i++){
			v.push_back(s[i]-'a');
		}
		vector<long long> temp = v;
		long long ic = invCount(temp);
		//cout<<ic<<endl;
		long long less[n+10][28];
		long long more[n+10][28];
		memset(more, 0, sizeof(more));
		memset(less, 0, sizeof(less));
		for(long long i=1; i<n; i++){
			long long val = v[i-1];
			for(long long j=0; j<26; j++){
				less[i][j] = less[i-1][j];
			}
			for(long long j = val+1; j < 26; j++){
				less[i][j]+=1;
			}
		}
		for(long long i = n-2; i>=0;i--){
			long long val = v[i+1];
			for(long long j=0; j<26; j++){
				more[i][j] = more[i+1][j];
			}
			for(long long j = 0; j < val; j++){
				more[i][j]++;
			}
		}
		long long mn = ic;
		long long by, which;
		for(long long i=0;i<n;i++){
			for(long long j =0;j<26;j++){
				long long x = abs(v[i]-j);
				long long y = ic - less[i][v[i]] - more[i][v[i]] + less[i][j] + more[i][j];
				if(mn > x+y){
					mn = x+y;
					by = j;
					which = i;
				}
			}
		}
		cout<<mn<<endl;
	}
}
