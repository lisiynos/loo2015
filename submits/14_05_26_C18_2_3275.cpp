#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream cin ("prizes.in");
    ofstream cout ("prizes.out");
    long long min = 0, tmp;
    int n, k;
    bool good;
    cin >> n >> k;

    long long sums[n];
    int przs[n];
    for(int i = 0; i < n; i++){
        cin >> przs[i];
        sums[i] = przs[i];
        for(int j = i-1; j >= 0 && i - j < k; j--){
            sums[j] += przs[i];
            if(sums[j] > min)
                min = sums[j];
        }
    }
    /*
    cerr << min << endl;


    for(int i = 0; i < n; i++)
        cerr << sums[i] << " ";
    cerr << endl;
    */

    good = true;
    for(int i = 0; i < n; i++){
        //cerr << i << endl;
        tmp = 0;
        for(int j = 0; j < n; j++){
            if(i-j < k && i-j > 0)
                tmp += przs[j];
            good = (sums[j] <= sums[i] || (i-j < k && i-j > 0 && tmp <= sums[i]) || (j-i < k && j-i >= 0));
            //cerr << "  " << j << " " << (sums[j] <= sums[i]) << " " << (abs(j-i) < k) << endl;
            if(!good)
                break;
        }
        if(good && sums[i] < min){
            min = sums[i];
            //cerr << "min changed " << i << endl;
        }
    }
    cout << min << endl;
    return 0;
}
