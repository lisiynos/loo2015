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
    long long sum=0,now1,now2;
    cin>>n>>k;
    vector<long long> ele;
    for (long long i=0;i<k;i++){
        cin>>p;
        ele.push_back(p);
        sum+=p;
    }
    now1=0;
    now2=k-1;
    priority_queue<vector<long long> > Q;
    vector<long long> h(3);
    vector<long long> z;
    h[0]=sum;
    h[1]=now1;
    h[2]=now2;
    Q.push(h);
    for (long long i=0;i<n-k;i++){
        cin>>p;
        ele.push_back(p);
        h[0]=h[0]-ele[now1]+p;
        now1++; now2++;
        h[1]++;h[2]++;
        Q.push(h);
    }
    h=Q.top();
    Q.pop();
    while (true){
        z=Q.top();
        Q.pop();
        if (z[1]>h[2] or z[2]<h[1]){
            cout<<z[0];
            exit(0);
        }
    }
}
