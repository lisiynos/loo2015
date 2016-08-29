using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication5
{
    class Program
    {
        public class Tree
        {
            public class Node
            {
                public char Value;
                public Dictionary<char, Node> Childs = new Dictionary<char, Node>();
                public int EndCount;

                public Node(char val = '\0')
                {
                    Value = val;
                }

                public void Add(string word, int pos = 0)
                {
                    if (pos == word.Length)
                    {
                        EndCount++;
                    }
                    else
                    {
                        if (!Childs.ContainsKey(word[pos]))
                            Childs.Add(word[pos], new Node(word[pos]));//.Add(word, pos + 1);
                        //else
                        //    Childs.Add(new Node(word, pos + 1));
                        Childs[word[pos]].Add(word, pos + 1);
                    }
                }

                public int Check(string word, int pos = 0)
                {
                    if (pos == word.Length)
                    {
                        if (Childs.ContainsKey('&'))
                            return EndCount + Childs['&'].EndCount;
                        return EndCount;
                    }
                    int res = 0;
                    if (Childs.ContainsKey(word[pos]))
                        res += Childs[word[pos]].Check(word, pos + 1);
                    //else
                    //{
                        if (Childs.ContainsKey('*'))
                        {
                            var ch = Childs['*'];
                            for (int i = pos; i <= word.Length; i++)
                            {
                                res += ch.Check(word, i);
                            }                            
                            //while (true)
                            //{
                            //    while (!ch.Childs.ContainsKey(word[pos]))
                            //    {
                            //        pos++;
                            //        if (pos == word.Length) return ch.EndCount + res;
                            //    }
                            //    res += ch.Childs[word[pos]].Check(word, pos + 1);
                            //}
                        }
                        else if ((this.EndCount > 0 || word[pos] == '/') && Childs.ContainsKey('&'))
                        {
                            res += Childs['&'].EndCount;// +res;
                        }
                    //}
                    return res;
                }
            }

            public Node RootNode;
            public Tree()
            {
                RootNode = new Node();
            }
            public void Add(string word)
            {
                RootNode.Add(word);
            }
            public int Check(string word)
            {
                return RootNode.Check(word);
            }
        }
        static void Main(string[] args)
        {
            Tree tree = new Tree();
            StreamReader sr = new StreamReader(@"search.in");
            StreamWriter sw = new StreamWriter(@"search.out");
            args = sr.ReadLine().Split(' ');
            int count = Convert.ToInt32(args[0]);
            for (int i = 0; i < count; i++)
            {
                tree.Add(sr.ReadLine().Replace("*.", "*").Replace("/*", "&"));
            }
            count = Convert.ToInt32(sr.ReadLine());
            //int res = 0;
            for (int i = 0; i < count; i++)
            {
                sw.WriteLine(tree.Check(sr.ReadLine()));
            }
            sw.Close();
            //File.WriteAllText(@"search.out", res.ToString());
        }
    }
}
