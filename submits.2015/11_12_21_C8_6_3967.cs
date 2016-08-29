using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            args = File.ReadAllText(@"forest.in").Split(' ');
            long A = Convert.ToInt64(args[0]);
            long K = Convert.ToInt64(args[1]);
            long B = Convert.ToInt64(args[2]);
            long M = Convert.ToInt64(args[3]);
            long X = Convert.ToInt64(args[4]);

            long max = long.MaxValue;
            long min = 1;

            if (X % (A + B) > 0)
                max++;
            long tryval;
            long tempmin = 0;
            long tempmax = 0;
            while (true)
            {
                tempmin = min;
                tempmax = max;
                tryval = min + ((max - min + 1) >> 1);
                long val = A * (tryval - (long)(tryval / K)) + B * (tryval - (long)(tryval / M));
                long workinlastday = A * ((tryval % K == 0) ? 0 : 1) + B * ((tryval % M == 0) ? 0 : 1);
                if (val > X && val - X < workinlastday)
                    break;
                if (val > X)
                {
                    max = tryval;
                }
                else
                {
                    min = tryval;
                }
                if (tempmin == min && tempmax == max) File.WriteAllText(@"forest.out", min.ToString());
            }
            File.WriteAllText(@"forest.out", tryval.ToString());
        }
    }
}
