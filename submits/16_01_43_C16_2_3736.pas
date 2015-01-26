program prizes;

 var
  n,k,x,maxa,maxb,b:int64;
  e,i:longint;
  f,d:text;
  A:array[1..100000000] of int64;
  S:array[1..100000000] of int64;


 begin

  assign(f, 'prizes.in');
  reset(f);
  readln(f, n, k);
  assign(d, 'prizes.out');
  rewrite(d);

  x:=n-k+1;

  for i:=1 to n do
   read(f, A[i]);

  for i:=1 to x do

   for e:=i to (i+k-1) do
    S[i]:=S[i]+A[e];



   for i:=1 to (x-1) do
    for e:=(i+1) to x do
     if S[e]>s[i] then
    begin
     b:=S[i];
     S[i]:=S[e];
     S[e]:=b;
    end;

    writeln(d, S[3]);

    close(d);
 end.