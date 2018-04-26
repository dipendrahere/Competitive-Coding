#include<bits/stdc++.h>
using namespace std;
int sum =0 ;
void print(vector<int> t[200006]){
	// for(int i = 1; i < sum+1;i++){
	// 	cout<<"bacha of "<<i<<":"<<endl;
	// 	for(auto r:t[i]){
	// 		cout<<r<<" ";
	// 	}
	// }

	// cout<<endl;return ;


	int a[200006+2]={0};
	for(int i  = 0; i < sum+2;i++){
		for(auto r : t[i]){
			a[r] = i;
		}
	}
	for(int i= 1;i<sum+1;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int h;
	cin>>h;
	int a[200009];
	//int h[100009];
	for(int i= 0 ;i < h+1;i++){
		cin>>a[i];
		//h[i] =a[i];
		sum+=a[i];
	}
	int flag = 0;
	for(int i=0;i<h;i++){
		if(a[i] == 1 || a[i+1] == 1){
			continue;
		}
		flag = 1;
		break;
	}
	if(flag == 0){
		cout<<"perfect\n";return 0;
	}
	else{
		cout<<"ambiguous\n";
		vector<int> t[200006];
		int v = 1;
		for(int i = 1; i < h+1; i++){
			int j;
			for(j = 1; j <= a[i]; j++){
				t[v].push_back(j+v);
			}
			v = v+j-1;
		}
		print(t);
		v = 1;
		vector<int> y[200006];
		for(int i = 1; i < h+1; i++){
			int j=1;
			if(a[i] != 1 && a[i-1]!=1){
				y[v-1].push_back(v+1);
				j=2;
			}
			for(; j <= a[i]; j++){
				y[v].push_back(j+v);
			}
			v = v+j-1;
			
		}	
		print(y);
	}
}
