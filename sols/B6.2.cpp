#include <iostream>
#include <cstdio>

using namespace std;
unsigned long long int n, k;

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    unsigned long long int max_sum, sec_sum, prom_sum, i;
    unsigned long long int counter = 0;
    max_sum = 0;
    sec_sum = 0;
    cin >> n >> k;
    unsigned long long int first[k];
    unsigned long long int prom[k];

    for (i=0; i<k; i++){
        cin >> first[i];
        prom[i] = first[i];
        max_sum+=first[i];
    }
    sec_sum = max_sum;
    prom_sum = max_sum;

    for (i=k; i<n; i++){
        if (counter == k)
            counter = 0;
        prom_sum -= prom[counter];
        cin >> prom[counter];
        prom_sum += prom[counter];
        if (prom_sum>max_sum){
            sec_sum = max_sum;
            max_sum = prom_sum;
        }else
            if ((prom_sum>sec_sum) and (prom_sum<=max_sum)){
            sec_sum = prom_sum;
            }

        counter++;
    }
    cout << sec_sum;
    return 0;
}
