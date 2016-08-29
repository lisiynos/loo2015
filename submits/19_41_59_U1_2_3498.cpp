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
    cin>>n>>k;
    vector<long long> ele(n);
    vector<long long> res(n-k+1);
    vector<long long> pred(n);
    vector<long long> post(n);
    long long best=1000000000000000000;
    long long sum=0;
    for (long long i=0;i<k;i++){
        scanf("%d",&ele[i]);
        sum+=ele[i];
        res[i]=0;

    }
    long long now=0;
    res[0]=sum;
    for (long long i=k;i<n;i++){
        scanf("%d",&ele[i]);
        sum+=ele[i];
        sum-=ele[now];
        now++;
        res[now]=sum;
        pred[i]=max(pred[i-1],res[i-k]);
    }
    for(long long i=n-k+1;i<n;i++){
        res[i]=0;
    }
    for (long long i=n-k-1;i>=0;i--){
        post[i]=max(post[i+1],res[i+k-1]);
        //cout<<"i="<<i<<" i+k-1="<<res[i+k-1]<<endl;
    }
    for (long long i=k;i<n-k;i++){
        best=min(best,max(post[i],pred[i]));
        //cout<<pred[i]<<" "<<post[i]<<endl;
    }
    cout<<best;
    return(0);
    //cout<<pred[2]<<endl;
    //cout<<post[2]<<endl;
}
