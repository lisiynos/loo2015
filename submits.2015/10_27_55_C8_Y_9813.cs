using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        public static List<char[]> island;
        public static int width;
        public static int height;
        public static byte[][] res;
        public static int counter = 0;
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"alligator.in");
            args = sr.ReadLine().Split(' ');
            height = Convert.ToInt32(args[0]);
            width = Convert.ToInt32(args[1]);
            island = new List<char[]>();
            res = new byte[height][];
            for (int i = 0; i < height; i++)
            {
                res[i] = new byte[width];
                //for (int i2 = 0; i2 < width; i2++)
                //{
                    island.Add(sr.ReadLine().ToCharArray());
                //}
            }
            //
            int counter = 0;
            for (int i = 0; i < height; i++)
            {
                for (int i2 = 0; i2 < width; i2++)
                {
                    Check(i, i2);
                        //counter++;
                    //PrintIsland();
                    //Console.ReadKey();
                }
            }
            File.WriteAllText(@"alligator.out", counter.ToString());
        }

        public static List<KeyValuePair<int, int>> visited = new List<KeyValuePair<int, int>>();

        private static bool Check(int y, int x)
        {
            if (visited.Contains(new KeyValuePair<int, int>(x, y)))
            {
                return false;
            }
            visited.Add(new KeyValuePair<int, int>(x, y));
            int x_this = x;
            int y_this = y;
            //Console.WriteLine("x: " + x + " y: " + y);
            if (res[y][x] == 0)
            {
                switch (island[y][x])
                {
                    case 'W':
                        x--;
                        while (x >= 0 && island[y][x] == '.') x--;
                        if (x == -1) res[y_this][x_this] = 1;// true;
                        else res[y_this][x_this] = Check(y, x) ? (byte)1 : (byte)2;
                        break;
                    case 'E':
                        x++;
                        while (x < width && island[y][x] == '.') x++;
                        if (x == width) res[y_this][x_this] = 1;// true;
                        else res[y_this][x_this] = Check(y, x) ? (byte)1 : (byte)2;
                        break;
                    case 'S':
                        y++;
                        while (y < height && island[y][x] == '.') y++;
                        if (y == height) res[y_this][x_this] = 1;// true;
                        else res[y_this][x_this] = Check(y, x) ? (byte)1 : (byte)2;
                        break;
                    case 'N':
                        y--;
                        while (y >= 0 && island[y][x] == '.') y--;
                        if (y == -1) res[y_this][x_this] = 1;// true;
                        else res[y_this][x_this] = Check(y, x) ? (byte)1 : (byte)2;
                        break;
                    case '.':
                        res[y_this][x_this] = 1;
                        break;
                }
            }
            if (res[y_this][x_this] == 1 && island[y_this][x_this] != '.')
            {
                island[y_this][x_this] = '.';
                counter++;
            }
            return res[y_this][x_this] == 1;
        }
    }
}
