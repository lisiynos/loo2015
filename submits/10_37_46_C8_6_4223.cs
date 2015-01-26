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

            long max = 2 * X / (A + B);
            long min = max / 2;

            if (X % (A + B) > 0)
                max++;
            long tryval;
            while (true)
            {
                tryval = min + ((max - min) >> 1);
                long val = A * (tryval - (long)(tryval / K)) + B * (tryval - (long)(tryval / M));
                if (val > X && val - X < A + B)
                    break;
                if (val > X)
                {
                    max = tryval;
                }
                else
                {
                    min = tryval;
                }
            }
            File.WriteAllText(@"forest.out", tryval.ToString());
        }
    }
}
