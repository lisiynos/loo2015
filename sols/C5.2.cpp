#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, t, k, x, m_alice, m_bob;
    cin >> n >> k;
    vector <int> prizes;
    vector <int> sums;
    for (int i = 0; i < n; i++) {
        cin >> x;
        prizes.push_back(x);
        sums.push_back(0);
    }
    for (int i = 0; i < k; i++)
        sums[0] += prizes[i];
    m_alice = sums[0];
    m_bob = 0;
    for (int i = 1; i < n - k + 1; i++) {
        sums[i] = sums[i - 1] - prizes[i - 1] + prizes[i + k - 1];
        if (sums[i] > m_alice) {
            m_bob = m_alice;
            m_alice = sums[i];
        }
        else if (sums[i] > m_bob) m_bob = sums[i];
    }
    cout << m_bob;
}