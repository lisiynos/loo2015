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
            int N = Convert.ToInt32(File.ReadAllText(@"circle.in"));
            File.WriteAllText(@"circle.out", (N * ((N % 2 == 0) ? (N - 2) : (N - 1))).ToString());
        }
    }
}
