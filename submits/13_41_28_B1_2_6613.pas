program prize;
var
s,a :array[1..100000] of longint;
n,k,m,max,i,j:longint;

begin
assign(input,'prizes.in'); reset(input);
assign(output,'prizes.out'); rewrite(output);
 read(n,k);
  for i:=1 to n do
  read(a[i]);
  

   for i:=1 to n do
   for j:=1 to k do 
   s[i]:=a[i]+a[j];
   
  
     max:=0;
     for i:=1 to n do
     if s[i]>max then 
     begin
     max:=s[i];
     m:=i;
     end;
     
       a[m]:=0;
       for i:=1 to k  do   
       a[m+i]:=0;

       for i:=1 to n do
       for j:=1 to k do
       s[i]:=a[i]+a[j];
       
       max:=0;
       for i:=1 to n do
       if s[i]>max then max:=s[i];

write(max);
end.