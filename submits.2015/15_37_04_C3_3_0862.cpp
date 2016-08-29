#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<long long,int> a;
int main()
{
    freopen("river.in","r",stdin);
    freopen("river.out","w",stdout);
   int n,o;
   cin >> n >> o;;
   long long s=0;
   for(int i=1;i<=n;i++){
    cin >> a[i];
    s+=a[i]*a[i];
   }
   int k;
   cin >> k;
   int e,j,l=n;
   cout << s << endl;

   for(int i=0;i<k;i++){
      cin >> e >> j;
      if(e==1){
        if(j==1){
            s=s-a[1]*a[1]-a[2]*a[2];
            a[2]=a[2]+a[1];
            s+=a[2]*a[2];
             cout << s << endl;
           for(int k=2;k<=l;k++)
            a[k-1]=a[k];
           a[l]=0;
           l--;
           continue;
        }
        if(j==l){
            s=s-a[l]*a[l]-a[l-1]*a[l-1];
            a[l-1]+=a[l];
            s+=a[l-1]*a[l-1];
             cout << s << endl;
            a[l]=0;
            l--;
            continue;
        }

        s=s-a[j]*a[j]-a[j-1]*a[j-1]-a[j+1]*a[j+1];
        a[j-1]+=a[j]/2;
        a[j+1]+=a[j]-a[j]/2;
        s+=a[j-1]*a[j-1]+a[j+1]*a[j+1];
         cout << s << endl;
         for(int k=j+1;k<=l;k++)
            a[k-1]=a[k];
         a[l]=0;
         l--;
         continue;
      }
      if(e==2){
        s=s-a[j]*a[j];
        for(int k=l;k>=j+1;k--)
            a[k+1]=a[k];
        l++;
        a[j+1]=a[j]-a[j]/2;
        a[j]=a[j]/2;
        s+=a[j]*a[j]+a[j+1]*a[j+1];
        cout << s << endl;
      }


   }
    return 0;
}
