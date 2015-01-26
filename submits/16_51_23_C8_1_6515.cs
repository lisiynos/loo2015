using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"hall.in");
            args = sr.ReadLine().Split(' ');
            int minp = Convert.ToInt32(args[2]) / 2;
            int maxp = Convert.ToInt32(args[3]) / 2;

            int minsqrt = Convert.ToInt32(args[0]);
            int maxsqrt = Convert.ToInt32(args[1]);

            int to = (maxp - 1);
            if(to % 2 == 1) to = (to / 2) + 1;
            else to = to / 2;
            int counter = 0;
            for (int i = 1; i <= to; i++)
            {
                for (int i2 = Math.Max(Math.Max(minp - i, (int)Math.Ceiling((float)minsqrt / i)), i); i2 <= Math.Min(maxp - i, maxsqrt / i); i2++)
                {
                    int p = i + i2;
                    int sqrt = i * i2;
                    if (p <= maxp && p >= minp && sqrt <= maxsqrt && sqrt >= minsqrt)
                        counter++;
                }
            }
            File.WriteAllText(@"hall.out", counter.ToString());
        }
    }
}   