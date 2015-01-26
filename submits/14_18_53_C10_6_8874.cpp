
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin ("forest.in");
    ofstream fout ("forest.out");
    long long int a,k,b,m,x, day=0;
    fin >> a>>k>>b>>m>>x;
    if(k>x && m>x)// always working (O(1))
        day = x/(a+b);
    else
    for(day=0;day<10000000000;day++){ // (<O(n)
        if(x <=0)
            break;
        if(x % k != 0)
            x-=a;
        if(x % m != 0)
            x-=b;
    }
    fout<<day;
    return 0;
}
