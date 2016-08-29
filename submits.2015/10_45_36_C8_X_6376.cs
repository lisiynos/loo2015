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
            StreamReader sr = new StreamReader(@"sumsqr.in");
            args = sr.ReadLine().Split(' ');
            var a = Convert.ToInt64(args[0]);
            var b = Convert.ToInt64(args[1]);
            File.WriteAllText(@"sumqrt.out", (a * a + b * b).ToString());
        }
    }
}
