#include<bits/stdc++.h>
using namespace std;

long long int getSum(long long int BITree[], long long int index)
{
	long long int sum = 0;
	while (index > 0)
	{   
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}
void updateBIT(long long int BITree[], long long int n, long long int index, long long int val)
{
	while (index <= n)
	{
		BITree[index] += val;
		index += index & (-index);
	}
}
long long int getInvCount(long long int arr[], long long int n)
{
	long long int invcount = 0;
	long long int BIT[n+1];
	memset(BIT, 0, sizeof(BIT));
	for (long long int i=n-1; i>=0; i--)
	{
		invcount += getSum(BIT, arr[i]-1);
		updateBIT(BIT, n, arr[i], 1);
	}

	return invcount;
}


int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int arr[n+2];
		long long int temp[n+2];
		for(long long int i =0 ; i < n;i++){
			cin>>arr[i];
			temp[i] = arr[i];
		}
		sort(temp, temp+n);
		for(long long int i = 0; i < n; i++){
			arr[i] = lower_bound(temp, temp+n, arr[i])-temp+1;
			//cout<<arr[i]<<" ";
		}
        long long int ans = getInvCount(arr, n);
        //cout<<ans<<endl;
        for(long long int i = 0; i < n; i++){
            long long int v = arr[i];
            ans = ans+n-2*v+1;
            cout<<ans<<" ";
        }
        cout<<endl;
	}
}
