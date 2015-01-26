#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("forest.in", "r", stdin);
    freopen("forest.out", "w", stdout);

    long long int f_work, s_work, f_rest, s_rest, forest, i = 0;

    cin >> f_work >> f_rest >> s_work >> s_rest >> forest;

    while (forest > 0){
        i++;

        if (i % f_rest != 0){
            forest -= f_work;
        }


        if (i % s_rest != 0){
            forest -= s_work;
        }

    }

    cout << i;
}
