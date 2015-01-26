program meganet;
var 
n,p,i,j,k,m:longint;
s:array [1..100] of string;
a,t:string;


begin
 assign(input,'search.in'); reset(input);
 assign(output,'search.out'); rewrite(output);
          read(n,p);
           
           
           for i:=1 to n do
           begin
           readln(t);
           if t[1]='*' then delete(t,1,2);
           s[i]:=t;
           if t[length(t)]='*' then delete(t,length(t)-1,2);
           end;
           
           read(k);
           
           for i :=1 to k do
           begin
           m:=0;
           readln(a);
           
           for k:=1 to length(a) do
           for j:=1 to n do
           if s[j]=a then inc(m);
           writeln(m);
           end;


end.