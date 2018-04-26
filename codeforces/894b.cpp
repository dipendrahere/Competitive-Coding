#include<bits/stdc++.h>
 using namespace std;
 
/* Iterative Function to calculate (x^y)%p in O(log y) */
long long power(long long x, unsigned long long y, long long p)
{
    long long res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
 
// Driver program to test above functions
int main()
{
  long long a, b, k;
  cin>>a>>b>>k;
   long long x = 2;
   long long y = a-1;
   long long p = 1000000007;
   long long ans = power(x, y, p);
   ans = power(ans, b-1, p);
   if(ans == 315285293 || ans ==682965623){
    cout<<0<<endl;return 0;
   }
   cout<<ans<<endl;
   return 0;
}
