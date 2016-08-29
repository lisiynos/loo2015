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
            StreamReader sr = new StreamReader(@"sum.in");
            args = sr.ReadLine().Split(' ');
            File.WriteAllText(@"sum.out", (Convert.ToInt64(args[0]) + Convert.ToInt64(args[1])).ToString());
        }
    }
}
