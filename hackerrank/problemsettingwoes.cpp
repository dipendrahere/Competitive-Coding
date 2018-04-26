#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
bool rec(int in, int n, int s, int p, int as, int ap){
    if(as > s && ap > p){
        return false;
    }
    if(in == n){
        if(as == s && ap == p){
            return true;
        }
        else{
            return false;
        }
    }
    for(int i = 0; i <= 9; i++){
        arr[in] = i;
        if(rec(in+1, n, s, p, as+i, ap*i)){
            return true;
        }
    }
    return false;
}

int main() {
    int n, s, p;
    cin>>n>>s>>p;
    if(rec(0, n, s, p, 0, 1)){
        for (auto i : arr){
            cout<<i;
        }
        cout<<endl;
    }
    else{
        cout<<"-1\n";
    }
    return 0;
}
