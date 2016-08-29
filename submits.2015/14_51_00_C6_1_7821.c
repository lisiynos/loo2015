#include "stdio.h"
#include "math.h"

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
    int a, b, c, d, i, j, answer = 0;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    i = 1;
    j = 1;
   // a = 1;
    //b = 1000;
   // c = 1;
   // d = 1000;
    for (; ((4*i <= d) and (i * i <= b)); i++)
    {
        for (j = i; ((2*(i + j) <= d) and (i * j <= b)); j++)
        {
            if ((2*(i + j) >= c) and (i * j >= a))
                answer++;
            //printf("%d%d\n", i, j);
        }
    }
    printf("%d", answer);
    return 0;
}
