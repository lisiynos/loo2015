program hall;

var a,b,c,d,i,j,k,n,kol,h,l:integer;
    s:array [1..1000] of int64;

BEGIN

assign(input,'hall.in');
reset(input);
assign(output,'hall.out');
rewrite(output);

read(a,b,c,d);
kol:=0;
h:=0;
n:=0;
while a < d do begin
   for i:=1 to d do begin
      s[i]:=a*i;
      if s[i] <= b then begin
         if (s[i]*2 >= c) and (s[i]*2 <= d) then begin
         inc(n);
         inc(kol);
         for j:=n to n do begin
         s[j]:=s[i];
         end;
         end;
      end;
   end;
   a:=a+1;
end;
j:=1;
for k:=1 to n do begin
s[k]:=s[j];
j:=j+1;
end;
k:=0;
while k<=n do begin
   k:=k+1;
   for j:=k to n do begin
      if s[k]<>s[j] then inc(h);
   end;
     l:=n-1;
     if h=l then begin kol:=kol-1;
     end;
end;

write(kol);
     
   
   

close(input);
close(output);

END.