using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        //public static long[] sqrsums;
        //public static int len;
        public static int pos = 0;
        public static int[] sumarr;
        public static long sum;
        public static long max = 0;
        public static int maxpos = 0;
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"prizes.in");
            args = sr.ReadLine().Split(' ');

            int n = Convert.ToInt32(args[0]);
            int k = Convert.ToInt32(args[1]);

            int[] prizes = new int[n];
            sumarr = new int[k];
            for (int i = 0; i < n; i++)
            {
                int cost = sr.ReadTextInt32();
                sum -= sumarr[pos];
                sum += cost;
                sumarr[pos] = cost;
                pos = (pos + 1) % k;
                prizes[i] = cost;
                if (sum > max)
                {
                    max = sum;
                    maxpos = i - k + 1;
                }
            }
            if (maxpos <= k)
                for (int i = 0; i < maxpos + k; i++)
                    prizes[i] = 0;
            else if (n - (maxpos + k) < k)
                for (int i = maxpos; i < n; i++)
                    prizes[i] = 0;
            else
                for (int i = 0; i < k; i++)
                    prizes[maxpos + k] = 0;
            sum = 0;
            sumarr = new int[k];
            for (int i = 0; i < n; i++)
            {
                sum -= sumarr[pos];
                sum += prizes[i];
                sumarr[pos] = prizes[i];
                pos = (pos + 1) % k;
                if (sum > max)
                {
                    max = sum;
                    maxpos = i - k;
                }
            }


            File.WriteAllText(@"prizes.out", sum.ToString());
        }
    }
    public static class Ext
    {
        public static int ReadTextInt32(this StreamReader sr)
        {
            string strint = "";
            char t = '\0';
            char[] buff = new char[1];
            while (!char.IsNumber(t))
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
