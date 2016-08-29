#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <bool> > b;
vector <int> t1;
vector <int> t2;
vector <int> t3;
vector <int> t4;
const int h = 1000000007;

/*int ft1(int x) {
    if (t1[x] != -1) return (t1[x]);
    else {
        if (b[x][1]) t1[x] = ft2(x);
        else {
            if (b[x][2]) t1[x] = ft4(x);
            else {
                if (b[x + 1][1])
                    t1[x] = ft3(x) + ft2(x + 1);
                else {
                    t1[x] = t2[x] + t1[x + 1] + t3[x];
                }
            }
        }
    }
    return (t1[x]);
}

int ft2(int x) {
    if (t2[x] != -1) return (t2[x]);
    else {
        if (b[x][2]) t2[x] = ft1(x + 1);
        else {
            if (b[x + 1][2])
                t2[x] = ft4(x - 1);
            else{
                t2[x] = ft1(x + 1) + ft4(x + 1)
            }
        }
    }
    return (t2[x]);
}

const int ft3(int x) {
    if (t3[x] != -1) return (t3[x]);
    else {
        if (b[x][2]) t3[x] = ft2(x + 1);
        else {
            if (b[x + 1][2]) t3[x] = ft1(x + 2);
            else {
                t3[x] = ft2(x + 1) + ft1(x + 2);
            }
        }
    }
    return(t3[x])
}

const int ft4(int x) {
    if (t4[x] != -1) return (t4[x]);
    else {
        if (b[x][1]) t4[x] = ft1(x + 1);
        else {
            if (b[x + 1][1]) t4[x] = ft2(x + 1);
            else {
                t4[x] = ft1(x + 1) + ft2(x + 1);
            }
        }
    }
    return(t4[x]);
}*/

int ft(int index, int x) {
    if (index == 1) {
        if (t1[x] != -1) return (t1[x]);
        else {
            if (b[x][1]) t1[x] = ft(2, x);
            else {
                if (b[x][2]) t1[x] = ft(4, x);
                else {
                    if (b[x + 1][1])
                        t1[x] = (ft(3, x) + ft(2, x + 1)) % h;
                    else {
                        t1[x] = (ft(2, x) + ft(1, x + 1) + ft(3, x)) % h;
                    }
                }
            }
    }
    return (t1[x]);
    }
    if (index == 2) {
        if (t2[x] != -1) return (t2[x]);
        else {
            if (b[x][2]) t2[x] = ft(1, x + 1);
            else {
                if (b[x + 1][2])
                    t2[x] = ft(4, x + 1);
                else{
                    t2[x] = (ft(1, x + 1) + ft(4, x + 1)) % h;
                }
            }
        }
        return (t2[x]);
    }
    if (index == 3) {
        if (t3[x] != -1) return (t3[x]);
        else {
            if (b[x][2]) t3[x] = ft(2, x + 1);
            else {
                if (b[x + 1][2]) t3[x] = ft(1, x + 2);
                else {
                    t3[x] = (ft(2, x + 1) + ft(1, x + 2)) % h;
                }
            }
        }
        return(t3[x]);
    }
    if (index == 4) {
        if (t4[x] != -1) return (t4[x]);
        else {
            if (b[x][1]) t4[x] = ft(1, x + 1);
            else {
                if (b[x + 1][1]) t4[x] = ft(2, x + 1);
                else {
                    t4[x] = (ft(1, x + 1) + ft(2, x + 1)) % h;
                }
            }
        }
        return(t4[x]);
    }
}



int main()
{
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    int n, k, x, y;
    cin >> n >> k;
    b.resize(n + 1);
    t1.resize(n + 1);
    t2.resize(n + 1);
    t3.resize(n + 1);
    t4.resize(n + 1);
    for (int i = 0; i <= n; i++)
        b[i].resize(3);
    for (int i = 0; i <= n; i++) {
        t1[i] = -1;
        t2[i] = -1;
        t3[i] = -1;
        t4[i] = -1;
        for (int j = 0; j <= 2; j++)
            b[i][j] = false;
    }
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        b[x][y] = true;
    }
    if (b[n][1]) {
        t4[n] = 0;
        if (b[n][2]) {
            t1[n] = 0;
            t2[n] = 0;
            t3[n] = 0;
            t4[n] = 0;
        }
        else {
            t1[n] = 1;
            t2[n] = 1;
            t3[n] = 1;
            t4[n] = 0;
        }
    }
    else {
        if (b[n][2]) {
            t1[n] = 1;
            t2[n] = 0;
            t3[n] = 0;
            t4[n] = 1;
        }
        else {
            t1[n] = 2;
            t2[n] = 1;
            t3[n] = 1;
            t4[n] = 1;
        }
    }
    if (n > 1) {
        if (b[n][2])
            if (b[n - 1][2]) t3[n - 1] = 0;
            else t3[n - 1] = 1;
        else
            if (b[n - 1][2]) t3[n - 1] = 1;
            else t3[n - 1] = 2;
    }
    cout << ft(1, 1);
}
