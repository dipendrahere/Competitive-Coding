#include<bits/stdc++.h>
using namespace std;
int mat[200];
int max(int a, int b){
	return a>b?a:b;
}
void print(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	cout<<endl;
}


int rec(int a[], int b[], int n, int m, int v, int i){
	if(i == n){
		return v;
	}
	int f=0;
	int ret = 0;
	if(mat[a[i]-1] > 0){
		mat[a[i]-1]--;
		f=1;
	//	cout<<a[i]<<" with "<<a[i]-1<<endl;
		ret = max(ret, rec(a, b, n, m, v+1, i+1));
		mat[a[i]-1]++;
	}
	if(mat[a[i]] > 0){
		mat[a[i]]--;
		f=1;
	//	cout<<a[i]<<" with "<<a[i]<<endl;
		ret = max(ret, rec(a, b, n, m, v+1, i+1));
		mat[a[i]]++;
	}
	if(mat[a[i]+1] > 0){
		mat[a[i]+1]--;
		f=1;
	//	cout<<a[i]<<" with "<<a[i]+1<<endl;
		ret = max(ret, rec(a, b, n, m, v+1, i+1));
		mat[a[i]+1]++;
	}
	if(f==0)
	ret = max(ret, rec(a, b, n, m, v, i+1));
	return ret;
}
int main(){
	int n;
	memset(mat, 0, sizeof(mat));
	cin>>n;
	int a[n+2];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	int b[m+2];
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
		mat[b[i]]++;

	}
	//sort(a, a+n);
	//sort(b,b+m);
	//print(mat, 20);
	cout<<rec(a,b,n,m,0,0)<<endl;
}
