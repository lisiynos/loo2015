using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"river.in");
            StreamWriter sw = new StreamWriter(@"river.out");
            //BinaryReader br = new BinaryReader(sr);
            args = sr.ReadLine().Split(' ');
            int n = Convert.ToInt32(args[0]);
            int p = Convert.ToInt32(args[1]);

            List<int> ranges = new List<int>(n);
            List<long> sqrranges = new List<long>(n);
            long sum = 0;

            for (int i = 0; i < n; i++)
            {
                int val = sr.ReadTextInt32();
                ranges.Add(val);
                sqrranges.Add((long)val * val);
                sum += (long)val * val;
            }
            sw.WriteLine(sum);
            sr.ReadLine();
            int count = Convert.ToInt32(sr.ReadLine());
            for (int i = 0; i < count; i++)
            {
                args = sr.ReadLine().Split(' ');
                int number = Convert.ToInt32(args[1]) - 1;
                if (args[0] == "1")
                {
                    if (number == 0)
                    {
                        sum -= sqrranges[0];
                        sum -= sqrranges[1];
                        sqrranges.RemoveAt(0);
                        ranges[1] += ranges[0];
                        ranges.RemoveAt(0);
                        sqrranges[0] = (long)ranges[0] * ranges[0];
                        sum += sqrranges[0];
                    }
                    else if (number == ranges.Count)
                    {
                        sum -= sqrranges[number];
                        sum -= sqrranges[number - 1];
                        sqrranges.RemoveAt(number);
                        ranges[number - 1] += ranges[number];
                        ranges.RemoveAt(number);
                        sqrranges[number - 1] = (long)ranges[number - 1] * ranges[number - 1];
                        sum += sqrranges[number - 1];
                    }
                    else
                    {
                        int top;
                        int bot;
                        bot = top = ranges[number] / 2;
                        if (ranges[number] % 2 == 1)
                            ++bot;

                        sum -= sqrranges[number];
                        sum -= sqrranges[number - 1];
                        sum -= sqrranges[number + 1];
                        ranges[number - 1] += top;
                        ranges[number + 1] += bot;
                        sqrranges[number - 1] = (long)ranges[number - 1] * ranges[number - 1];
                        sqrranges[number + 1] = (long)ranges[number + 1] * ranges[number + 1];
                        sum += sqrranges[number - 1];
                        sum += sqrranges[number + 1];
                        ranges.RemoveAt(number);
                        sqrranges.RemoveAt(number);
                    }
                }
                else
                {
                    int val = ranges[number];
                    int top = val / 2;
                    int bot = top;
                    if (val % 2 == 1)
                        ++bot;
                    sum -= sqrranges[number];
                    sqrranges[number] = (long)top * top;
                    sqrranges.Insert(number + 1, (long)bot * bot);
                    sum += sqrranges[number];
                    sum += sqrranges[number + 1];
                    ranges[number] = top;
                    ranges.Insert(number + 1, bot);
                }
                sw.WriteLine(sum);
            }
            sw.Close();
            //Console.ReadKey();
        }
    }
    public static class Ext
    {
        public static int ReadTextInt32(this StreamReader sr)
        {
            string strint = "";
            char t = '\0';
            char[] buff = new char[1];
            while (!char.IsNumber(t) )
            {
                t = (char)sr.Peek();
                sr.Read(buff, 0, 1);
            }
            while (char.IsNumber(t))
            {
                strint += t;
                t = (char)sr.Peek();
                sr.Read(buff, 0, 1);
            }
            return Convert.ToInt32(strint);
        }
    }
}
