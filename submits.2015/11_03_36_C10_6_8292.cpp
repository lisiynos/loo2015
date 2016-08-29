#include <iostream>
#include <fstream>

using namespace std;


int main(){
    ifstream fin("forest.in");
    ofstream fout("forest.out");
    long long int a,k,b,m,x, day = 0;
    fin >> a >> k >> b >> m >> x;
    if(k>x && m>x){// always working
        day = x/(a+b);
        if(x % (a+b) != 0)
            day++;
    }
    else{
      while(x>0){
        day++;
        if(day%k != 0)
            x -= a;
        if(day%m != 0)
            x -= b;
      }
      fout << day << endl;
    }
    return 0;
}

/*
a,k,b,m,x = list(map(int, open('forest.in').read().split()))

for day in range(1,10000000000):
    if x<=0:
        print(day-1, file=open('forest.out', 'w'))
        exit()
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b

*/
