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

            long min = X / (A + B);
            if (X % (A + B) > 0)
                min++;
            long max = min * 2;
            long tryval;
            //long tempmin = 0;
            //long tempmax = 0;
            while (true)
            {
                //tempmin = min;
                //tempmax = max;
                tryval = min + ((max - min) >> 1);
                long tmp_val_1 = A * (tryval - (long)(tryval / K));
                long tmp_val_2 = B * (tryval - (long)(tryval / M));

                long val = tmp_val_1 + tmp_val_2;

                if (tmp_val_1 < 0 || tmp_val_2 < 0 || val < 0)
                {
                    max = tryval;
                    continue;
                }
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
                //if (tempmin == min && tempmax == max) File.WriteAllText(@"forest.out", min.ToString());
            }
            //Array.BinarySearch(
            File.WriteAllText(@"forest.out", tryval.ToString());
        }
    }
}
