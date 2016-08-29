program meganet;
var 
n,p,i,j,k,m:longint;
a,b:array [1..100] of string;



begin
 assign(input,'search.in'); reset(input);
 assign(output,'search.out'); rewrite(output);
          readln(n,p);
           
           
           for i:=1 to n do
           begin
           readln(a[i]);
           
           end;
           
           read(k);
           
           for i :=1 to k do
           begin
           readln(b[i]);
           m:=0;
           for j:=1 to n do
           if a[i]=b[j] then inc(m);
           writeln(m);
           end;


end.
