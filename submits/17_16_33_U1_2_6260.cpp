#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    long long n,k,p;
    long long sum=0,now1=0;
    cin>>n>>k;
    vector<long long> ele;
    vector<long long> res;
    long long best=0;
    long long fir=0;
    for (long long i=0;i<k;i++){
        cin>>p;
        sum+=p;
        ele.push_back(p);
    }
    best=1000000000000000;
    res.push_back(sum);
    for (long long i=0;i<n-k;i++){
        cin>>p;
        sum-=ele[now1];
        sum+=p;
        now1++;
        //cout<<sum<<endl;
        ele.push_back(p);
        res.push_back(sum);
    }
    long long h;
    for (long long i=0;i<n-k+1;i++){
        h=0;
        for (long long j=0;j<max(i-k,n-n);j++){
            h=max(h,res[j]);
        }
        for (long long j=min(i+k,n-k+1);j<n-k+1;j++){
            h=max(h,res[j]);
        }
        best=min(best,h);
    }
    cout<<best;
}
