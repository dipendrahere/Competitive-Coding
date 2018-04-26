#include <bits/stdc++.h>
using namespace std;

int main() {
	int flag=1;
	int n;
	int k;
	scanf("%d", &n);
	scanf("%d",&k);
	char s[n+2];
	scanf("%s", s);
	int a[30];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		a[s[i]-'a']++;
	//	cout<<a[s[i]]-'a'<<endl;;
		if(a[s[i]-'a'] > k){
			flag=0;
			break;
		}
	}
	if(flag==0){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
	return 0;
}