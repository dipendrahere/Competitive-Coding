#include<bits/stdc++.h>
using namespace std;
struct x{
    double loc;
    double str;
};
struct x mat[600];
int n;
bool fun(struct x lhs, struct x rhs){
    return lhs.loc < rhs.loc;
}
int res(double x){
    double sumi = 0.0;
    double sumu = 0.0;
    for(int i=0;i<n;i++){
        if(x > mat[i].loc){
            sumi += ((mat[i].str*1.0)/log2(2.0+x - mat[i].loc));
        }
        else{
            sumu += ((mat[i].str*1.0)/log2(2.0+ mat[i].loc - x));
        }
    }
    if (sumu > sumi){
        return 1;
    }
    else return -1;
}
int Ok(double mid, double l, double r){
    if(res(mid) == res(r)){
        return true;
    }
    return false;
}
int main(){
    multiset<double> se;
    cin>>n;
    for(int  i=0;i<n;i++){
        cin>>mat[i].loc;
    }
    for(int i=0;i<n;i++){
        cin>>mat[i].str;
        mat[i].str = mat[i].str*1.0;
    }
    sort(mat, mat+n, fun);
    for(int i=0;i < n-1;i++){
        double l=mat[i].loc*1.0+(1e-12),r=mat[i+1].loc*1.0-(1e-12);
        if(res(l) - res(r) == 0){
            continue;
        }
        double mid;
        int tem=0;
        while(r-l>1e-12){
            mid=(l+r)/2.0;
          //  cout<<mid<<endl;
            if(Ok(mid, l, r))
                r=mid;
            else
                l=mid;
            tem++;
            if(tem==60)
                break;
        }
        //cout<<l<<endl;
        se.insert(l);
    }
    cout<<se.size()<<endl;
    for(auto i : se){
        printf("%.10f ", i);
    }
}
