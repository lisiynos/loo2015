#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
                //StreamReader sr = new StreamReader(@"hall.in");
            //args = sr.ReadLine().Split(' ');
            int minp, maxp, minsqrt, maxsqrt;
            cin >> minsqrt >> maxsqrt >> minp >> maxp;
            minp = minp / 2;
            maxp = maxp / 2;
            //int minp = Convert.ToInt32(args[0]) / 2;
            //int maxp = Convert.ToInt32(args[1]) / 2;

            //int minsqrt = Convert.ToInt32(args[2]);
            //int maxsqrt = Convert.ToInt32(args[3]);

            int to = maxp - minp;
            if(to % 2 == 1) to = (to / 2) + 1;
            else to = to / 2;
            
            int counter = 0;
            for (int i = 1; i <= to; i++)
            {
                for (int i2 = max(minp - i, (int)ceil((float)maxsqrt / i)); i2 <= min(maxp - i, (int)ceil((float)maxsqrt / i)); i2++)
                {
                    int p = 2 * (i + i2);
                    int sqrt = i * i2;
                    if (p <= maxp && p >= minp && sqrt <= maxsqrt && sqrt >= minsqrt)
                        counter++;
                }
            }
            cout << counter;
            //File.WriteAllText(@"hall.out", counter.ToString());
    //cout << "Hello world!" << endl;
    return 0;
}
