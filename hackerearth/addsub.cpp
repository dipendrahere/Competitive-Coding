#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	
	cin>>t;
	while(t--){int min = 10000000;
		int n,k;cin>>n>>k;int a[200] = {0};
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int arr[n];
		for(int i = 0 ; i < n;i++){
	//		cout<<"new"<<endl;
			for(int j = 0 ; j <n;j++){
				if(a[j]- a[i] >= 0){
					arr[j] = (a[j] - a[i])*5;
				}
				else{
					arr[j] = (a[i] - a[j])*3;
				}
			}
			int cost=0;
			sort(arr+0, arr+n);
			for(int i = 0 ; i < k; i++){
				cost+= arr[i];
		//		cout<<"add "<<arr[i]<<endl;
			}
			
			if(min > cost){
					min = cost;
				}
			
		}
		cout<<min<<endl;
	}
	return 0;
}