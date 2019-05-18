#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n,k,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(n==2)
		{}
		else if(k==1)
		{
			if(n%2==0&&n%4!=0)
				n=(n+2)/2;
			else if(n%2==0&&n%4==0)
				n=n/2;
			else
				n=(n+1)/2;
		}
		else
		{
			for(i=0;i<k;i++)
			{
				n=(n+1)/2;
				if(n==1)
					break;
			}
		}
		printf("%.6lf\n",1.00/(n+0.0));
	}
	return 0;
}
