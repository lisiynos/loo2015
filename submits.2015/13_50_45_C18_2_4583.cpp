#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream cin ("prizes.in");
    ofstream cout ("prizes.out");
    long long min = 0;
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
    cerr << min << endl;


    for(int i = 0; i < n; i++)
        cerr << sums[i] << " ";
    cerr << endl;


    good = true;
    for(int i = 0; i < n; i++){
        cerr << i << endl;
        for(int j = 0; j < n; j++){
            good = (sums[j] <= sums[i] || abs(j-i) < k);
            cerr << "  " << j << " " << (sums[j] <= sums[i]) << " " << (abs(j-i) < k) << endl;
            if(!good)
                break;
        }
        if(good && sums[i] < min){
            min = sums[i];
            cerr << "min changed " << i << endl;
        }
    }
    cout << min << endl;
    return 0;
}
