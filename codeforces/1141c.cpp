#include<bits/stdc++.h>
using namespace std;
int find(int a[], int n){
	int maxNeg = 1;
	int maxNegInd = -1;
	for(int i=0;i<n;i++){
		if(a[i]<0){
			if(maxNeg > a[i]){
				maxNeg = a[i];
				maxNegInd = i;
			}
		}
	}
	return maxNegInd;
}
bool check(int pre[], int n){
	set<int> st;
	for(int i=0;i<n;i++){
		st.insert(pre[i]);
	}
	if(st.size() != n){
		return false;
	}
	return true;
}
bool check2(int b[], int n){
	int a[n];
	for(int i=0;i<n;i++)a[i]=b[i];
	sort(a, a+n);
	for(int i=0;i<n;i++){
		if(a[i]!=i+1){
			cout<<-1<<endl;
			return true;
		}
	}
	return false;
}
void print(int a[], int n){
	if(check2(a, n))return;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int a[n+2];
	for(int i=0;i<n-1;i++){
		cin>>a[i];
	}
	int pre[n+2];
	pre[0] = a[0];
	for(int i=1;i<n-1;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int indexOf1 = -1;
	if(check(pre, n-1)){
		indexOf1 = find(pre, n-1);
		//cout<<indexOf1<<endl;
		int ans[n];
		if(indexOf1 == -1){
			ans[0] = 1;
			for(int i = 1;i<n;i++){
				ans[i]=ans[i-1]+a[i-1];
			}
		}
		else{
			ans[indexOf1+1] = 1;
			for(int i = indexOf1+2;i<n;i++){
				ans[i]=ans[i-1]+a[i-1];
			}
			for(int i=indexOf1;i>=0;i--){
				ans[i]=ans[i+1]-a[i];
			}
		}
		print(ans, n);
	}
	else{
		cout<<-1<<endl;
		return 0;
	}
	return 0;
}
