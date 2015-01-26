#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
     int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long long b[n-k+1],bmax=0,imax=0;
    for(int i=0;i<n-k+1;i++){
        b[i]=0;
        for(int j=i;j<i+k;j++){
            b[i]+=a[j];
        }
        if(b[i]>bmax){
            bmax=b[i];
            imax=i;
        }
    }
    /*for(int i=0;i<n-k+1;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    cout << bmax << endl;
    cout <<"imax " << imax << endl;*/
    long long t=0,amin=bmax;
    for(int i=0;i<n-k+1;i++){

        if(i<imax-2*k+2||i>imax){
            //cout << "R";
            if(b[i]>t)
                t=b[i];
             amin = t;
        }
    }
     //cout << "ololo "<< amin;
    for(int i=imax-k+2;i<=imax+k-1;i++){
        if(i<0||i>n-k)
            continue;
            if(i-k>=0){
        if(b[i-k]>=t){
            t=b[i-k];
            if(t<amin)
                amin=t;
               // cout << "ololo1 " << i-k << " " << amin << endl;
            continue;
        }}

        if(b[i+k-1]==t){//run
   //cout << "ppp";
        t=0;
    for(int j=0;j<n-k+1;j++){
        if(j<i-k+1||j>i+k-1){
            if(b[j]>t)
                t=b[j];

        }

        }
         if(t<amin){
                amin=t;
           //cout << "ololo2 " << i-k << " " << amin << endl;
             }




    }}

    cout << amin;

    return 0;
}
