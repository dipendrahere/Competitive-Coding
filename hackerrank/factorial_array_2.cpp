/*
TAKEN HELP FROM :
http://www.geeksforgeeks.org/compute-n-under-modulo-p/
http://www.geeksforgeeks.org/segment-trees-product-of-given-range-modulo-m/
http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/*/




#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define nfact 1001000
long fact[1001000];
long mod = 1e9;
  void calfacts(){
    fact[0] = 1;
    fact[1] = 1;
    for(long i=2;i<nfact;i++){
        fact[i] = ((fact[i-1]%mod)*(i%mod))%mod;
    }
}
long power(long x, unsigned long y, long p)
{
    long res = 1;      // Initialize result
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
 
 
// Function to find modular inverse of a under modulo p
// using Fermat's method. Assumption: p is prime
long modInverse(long a, long p)
{
   return power(a, p-2, p);
}
 
// Returns n! % p using Wilson's Theorem
long modFact(long n)
{
    long p = mod;
    // n! % p is 0 if n >= p
    if (p <= n)
        return 0;
 
    // Initialize result as (p-1)! which is -1 or (p-1)
    long res = (p-1);
 
    // Multiply modulo inverse of all numbers from (n+1)
    // to p
    for (long i=n+1; i<p; i++)
       res  = (res%p * modInverse(i, p)%p) % p;
    return res;
}
long change(long i, long v){
    return ((v%mod)*(i+1)%mod)%mod;
}
// A utility function to get the middle index from
// corner indexes.
long getMid(long s, long e) {  return s + (e -s)/2;  }
  
/*  A recursive function to get the Pdt of values 
    in given range of the array. The following are 
    parameters for this function.
  
    st    --> Polonger to segment tree
    si    --> Index of current node in the segment tree.
              Initially 0 is passed as root is always
              at index 0
    ss & se  --> Starting and ending indexes of the 
                 segment represented by current node, 
                 i.e., st[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
long getPdtUtil(long *st, long ss, long se, long qs, long qe,
                                                long si)
{
    // If segment of this node is a part of given
    // range, then return the Pdt of the segment
    if (qs <= ss && qe >= se)
        return st[si];
  
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 1;
  
    // If a part of this segment overlaps with the
    // given range
    long mid = getMid(ss, se);
    return (getPdtUtil(st, ss, mid, qs, qe, 2*si+1)%mod +
           getPdtUtil(st, mid+1, se, qs, qe, 2*si+2)%mod)%mod;
}
  
/* A recursive function to update the nodes which have 
   the given index in their range. The following are 
   parameters
    st, si, ss and se are same as getPdtUtil()
    i    --> index of the element to be updated.  
             This index is in input array.*/   
void updateValueUtil(long *st, long ss, long se, long i, 
                        long prev_val, long new_val, long si)
{
    // Base Case: If the input index lies outside 
    // the range of  this segment
    if (i < ss || i > se)
        return;
  
    // If the input index is in range of this node, then  
    // update the value of the node and its children
    st[si] = ((st[si]+new_val)-prev_val)%mod;
    if (se != ss)
    {
        long mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, prev_val,
                                new_val, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, prev_val, 
                                new_val, 2*si + 2);
    }
}
  
// The function to update a value in input array 
// and segment tree. It uses updateValueUtil() to 
// update the value in segment tree
void updateValue(long arr[], long *st, long n, long i, 
                                      long new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input";
        return;
    }
    long temp = arr[i];
 
    // Update the value in array
    arr[i] = new_val;
  
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, temp, new_val, 0);
}
  
// Return Pdt of elements in range from index qs
// (query start)to qe (query end).  It mainly 
// uses getPdtUtil()
long getPdt(long *st, long n, long qs, long qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }
  
    return getPdtUtil(st, 0, n-1, qs, qe, 0);
}
  
// A recursive function that constructs Segment Tree 
// for array[ss..se]. si is index of current node 
// in segment tree st
long constructSTUtil(long arr[], long ss, long se,
                              long *st, long si)
{
    // If there is one element in array, store it 
    // in current node of segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
  
    // If there are more than one elements, then
    // recur for left and right subtrees and store 
    // the Pdt of values in this node
    long mid = getMid(ss, se);
    st[si] =  (constructSTUtil(arr, ss, mid, st, si*2+1)%mod +
              constructSTUtil(arr, mid+1, se, st, si*2+2)%mod)%mod;
    return st[si];
}
  
/* Function to construct segment tree from given array. 
   This function allocates memory for segment tree and 
   calls constructSTUtil() to fill the allocated memory */
long *constructST(long arr[], long n)
{
    // Allocate memory for segment tree
  
    // Height of segment tree
    long x = (long)(ceil(log2(n))); 
  
    // Maximum size of segment tree
    long max_size = 2*(long)pow(2, x) - 1; 
  
    // Allocate memory
    long *st = new long[max_size];
  
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
  
    // Return the constructed segment tree
    return st;
}
 

// long main()
// {
//     long n, m;
//     cin>>n;
//     cin>>m;
//     calfacts();

//     //long n = sizeof(arr)/sizeof(arr[0]);
//     for(long i =0 ;i < n; i++){
//         cin>>arr[i];
//     }
    
//     constructST(arr, n);
//     for(long i=0;i<m;i++){
//         long ch;
//         cin>>ch;
//         if(ch == 1){
//             long l,r;
//             cin>>l>>r;
//             updateRange(n, l, r, 1);
//         }
//         else if(ch == 2){
//             long l,r;
//             cin>>l>>r;
//             cout<<getSum(n, l, r);

//         }
//         else{
//             long y, v;
//             cin>>y>>v;
//             long val =  v-a[y];
//             updateRange(n, y, y, val);
//         }
//     }


   
 
//     return 0;
// }




// Driver program to test above functions
int main()
{
	long n,m;
	cin>>n>>m;

    long a[n];
    long arr[n];
     calfacts();

    for(long i =0 ;i < n; i++){
        cin>>a[i];
        if(a[i] < nfact-100){
        	arr[i] = fact[a[i]];
        }
        else{
        	arr[i] = modFact(a[i]);
        }
    }
    long *st = constructST(arr, n);
    for(long i=0;i<m;i++){
        long ch;
        cin>>ch;
        if(ch == 1){
            long l,r;
            cin>>l>>r;l--;r--;
            for(long i=l;i<=r;i++){
            	long val = change(a[i], arr[i]);
            	a[i]++;
            	updateValue(arr, st, n, i, val);
            }
            
        }
        else if(ch == 2){
            long l,r;
            cin>>l>>r;l--;r--;
            cout<<getPdt(st, n, l, r)%mod<<endl;

        }
        else{
            long y, v;
            cin>>y>>v;y--;
            a[y] = v;
            long val;
            if(v < 1000000){
            	val = fact[v];
            }
            else{
            	val = modFact(v);
            }
            
            updateValue(arr, st, n, y, val);
        }
    }






    //long n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    // long *st = constructST(arr, n);
  
    // // Prlong Product of values in array from index 1 to 3
    // cout << "Product of values in given range = "
    //      << getPdt(st, n, 1, 3) << endl;
            
    // // Update: set arr[1] = 10 and update corresponding 
    // // segment tree nodes
    // updateValue(arr, st, n, 1, 10);
  
    // // Find Product after the value is updated
    // cout << "Updated Product of values in given range = "
    //      << getPdt(st, n, 1, 3) << endl;
    // return 0;
}
