#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long  fac[1000500];
long long  power(long long  x, long long  y, long long  p)
{
    long long  res = 1;      // Initialize result
 
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
 
// Returns n^(-1) mod p
long long  modInverse(long long  n, long long  p)
{
    return power(n, p-2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.

long long  modFact(long long  n, long long  p)
{
    // n! % p is 0 if n >= p
    if (p <= n)
        return 0;
 
    // Initialize result as (p-1)! which is -1 or (p-1)
    long long  res = (p-1);
 
    // Multiply modulo inverse of all numbers from (n+1)
    // to p
    for (long long  i=n+1; i<p; i++)
       res  = (res * modInverse(i, p)) % p;
    return res;
}

long long  nCrModPFermat(long long  n, long long  r, long long  p)
{
   // Base case
   if (r==0)
      return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    //long long  fac[n+1];
    //fac[0] = 1;
    //for (long long  i=1 ; i<=n; i++)
      //  fac[i] = fac[i-1]*i%p;
 	if(n > 1000000){
 		return (modFact(n,mod)*modInverse(fac[r], mod)%mod*modInverse(modFact(n-r,mod), p)%p)%mod;
 	}
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;

}
long long  dostuff(long long  n, long long  v){
	if(v > n*26)
		//return 0;
	if(v < n){
		return 0;
	}
	long long  val  = nCrModPFermat(v-1, n-1, mod)%mod;
	//cout<<"n :"<<v-1<<" r: "<<n-1<<" = "<<val<<endl;
	//cout<<val<<endl;
	return val;
	
}

int  main(){
	fac[0]=1;
	for(long long  i=1;i<1000500;i++){
		fac[i]=(fac[i-1]%mod*i%mod)%mod;
	}
	//cout<<fac[0]<<fac[1]<<fac[2]<<fac[3];
	long long  n, m, s;
	cin>>n>>m>>s;
	string temp;
	cin>>temp;
	long long  sum = 0;
	for(char r :temp){
		sum+=(r-'a'+1);
	}
	//cout<<sum<<endl;
	long long  v = s - sum;
	//cout<<v<<endl;
	if(v <= 0){
		v = v+m;
	}
	//cout<<v<<endl;
	long long  ans = 0;
	                  while(1){
		cout<<n<<" "<<v<<":"<<endl;
		ans = (ans%mod + dostuff(n,v)%mod)%mod;
		cout<<ans<<endl;
		v+=m;
		 if(v > n*26){
		 	break;
		 }
	                       }
	cout<<ans<<endl;
}
