program prize;
var
s,a :array[1..100000] of integer;
n,k,m,max,i,j:integer;

begin
assign(input,'prizes.in'); reset(input);
assign(output,'prizes.out'); rewrite(output);
 read(n,k);
  for i:=1 to n do
  read(a[i]);
  

   for i:=1 to n do
   for j:=1 to k do 
   s[i]:=a[i+j-1]+s[i];
   
  
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
       s[i]:=0;
       
       for i:=1 to n do
       for j:=1 to k do
       s[i]:=a[i+j-1]+s[i];
       
       max:=0;
       for i:=1 to n do
       if s[i]>max then max:=s[i];

write(max);
end.