#include <fstream>

using namespace std;

long long a, b, k, m, x;

long long get_val(int day)
{
    return a * day - ((int) (day / k)) * a + b * day - ((int) (day / m)) * b;
}

int get_max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int get_day()
{
    int min, max, mid;
    min = x / (a + b);
    max = 2 * min;
    while (min <= max)
    {
        mid = (max- min) / 2;
        if (get_val(mid) > x)
            max = mid - 1;
        else if (get_val(mid) < x)
            min = mid + 1;
        else
            return mid;
    }
    for (int i = -10000; i < 10001; i++)
        if (max + i > 0)
            if (get_val(max + i) > x)
                return max + i;
    return max;
}

int main()
{
    ifstream in ("forest.in");
    in >> a >> k >> b >> m >> x;
    in.close();
    ofstream out ("forest.out");
    out<<get_day();
    out.close();
    return 0;
}
