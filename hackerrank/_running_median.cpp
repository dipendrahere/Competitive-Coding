#include<bits/stdc++.h>
using namespace std;
multiset<int> l;
multiset<int> r;
float cal(int a, float m){
    if(l.size() > r.size()){
        if(a < m){
            r.insert(-1*(*l.begin()));
            l.erase(l.begin());
            l.insert(-1*a);
        }
        else{
            r.insert(a);
        }
        return 1.0*(-1.0*(*l.begin())+*r.begin())/2.0;
    }
    else if(l.size() < r.size()){
        if(a > m){
            l.insert(-1*(*r.begin()));
            r.erase(r.begin());
            r.insert(a);
        }
        else{
           l.insert(-1*a);
        }
        return 1.0*(-1.0*(*l.begin())+*r.begin())/2.0;
    }
    else{
        if(a > m){
            r.insert(a);
            return 1.0*(*r.begin());
        }
        else{
            l.insert(-1*a);
            return *l.begin()*-1.0;
        }
        
    }
}
int main(){
    int n;
    cin>>n;
    int a[n+2];
    float median = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        median = cal(a[i],median);
        printf("%.1f\n",median);
    }
}