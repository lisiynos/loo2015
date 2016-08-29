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
        mid = min + (max- min) / 2;
        if (get_val(mid) > x)
            max = mid - 1;
        else if (get_val(mid) < x)
            min = mid + 1;
        else
            return mid;
    }
    if (((get_val(get_max(max, min))) < x) and ((get_val(get_max(max, min) + 1) > x)))
        return get_max(max, min) + 1;
    else
        return get_max(max, min);
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