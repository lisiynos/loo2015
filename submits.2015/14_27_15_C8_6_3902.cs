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
            long tempmin = 0;
            long tempmax = 0;
            while (true)
            {
                tempmin = min;
                tempmax = max;
                tryval = min + ((max - min) >> 1);
                //if((tryval - (long)(tryval / K)) > long.MaxValue / A)
                long tmp_val_1 = A * (tryval - (long)(tryval / K));
                long tmp_val_2 = B * (tryval - (long)(tryval / M));

                //long tmp_val_12 = A * ((tryval - 1) - (long)((tryval - 1) / K));
                //long tmp_val_22 = B * ((tryval - 1) - (long)((tryval - 1) / M));

                long val = tmp_val_1 + tmp_val_2;
                long workinlastday = A * ((tryval % K == 0) ? 0 : 1) + B * ((tryval % M == 0) ? 0 : 1);
                long prev_val = val - workinlastday;

                if (tmp_val_1 < 0 || tmp_val_2 < 0 || val < 0)
                {
                    max = tryval;
                    continue;
                }

                if (prev_val < X && val > X)
                    break;
                if (val > X)
                {
                    max = tryval;
                }
                else
                {
                    min = tryval;
                }
                if (tempmin == min && tempmax == max)
                {
                    File.WriteAllText(@"forest.out", tryval.ToString());
                    break;
                }
            }
            //Array.BinarySearch(
            File.WriteAllText(@"forest.out", tryval.ToString());
        }
    }
}
