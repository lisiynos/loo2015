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
    vector<vector<long long> >res;
    h[0]=sum;
    h[1]=now1;
    h[2]=now2;
    Q.push(h);
    res.push_back(sum);
    for (long long i=0;i<n-k;i++){
        cin>>p;
        ele.push_back(p);
        h[0]=h[0]-ele[now1]+p;
        now1++; now2++;
        h[1]++;h[2]++;
        Q.push(h);
        res.push_back(sum);
    }
    
    h=Q.top();
    Q.pop();
    while (true){
        z=Q.top();
        Q.pop();
        if (z[1]-k>h[2] or z[2]+k<h[1]){
            cout<<z[0];
            exit(0);
        }
        else{
            bool flag=0;
            for (long long i=max(z[1]-k,n-n);i<min(n-1,z[2]-k);i++){
                if (res[i]>z[0]){
                    flag=1;
                    break;
                }
            }
            if (flag==0){
                cout<<z[0];
            }
        }
    }
}
