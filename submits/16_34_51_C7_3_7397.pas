var
a:array[1..100000000] of longint;w,n,k,i,j,c,f,h,q,x:integer;t,m:text;
begin
assign(t,'river.in');
reset(t);
assign(m,'river.out');
rewrite(m);
read(t,h);readln(t,k);
for i:=1 to h-1 do 
read(t,a[i]);
readln(t,a[h]);
readln(t,q);
 for j:=1 to h do
 x:=x+a[j]*a[j];
 writeln(m,x);
 x:=0;
for i:=1 to q do begin
read(t,c);readln(t,f);
if c=1 then begin 
 if f=1 then begin a[2]:=a[2]+a[i]; for j:=1 to h do
 a[j]:=a[j+1]
 end;
 if a[f+1]=0 then begin a[f-1]:=a[f-1]+a[f];a[f]:=0;end;
 if (a[f+1]<>0) and (f<>1) then begin a[f-1]:=a[f-1]+a[f] div 2;a[f+1]:=a[f+1]+a[f]-a[f] div 2;for j:=f to h do  a[j]:=a[j+1];end;h:=h-1;
 end;
if c=2 then begin 
for j:=h+1 downto f+1 do
a[j]:=a[j-1];
a[f]:=a[f+1] div 2;
a[f+1]:=a[f+1]-a[f+1]div 2;
h:=h+1;
 end;
 for j:=1 to h do
 x:=x+a[j]*a[j];
 writeln(m,x);
 x:=0;
 end;
 close(t);
 close(m);
 end.
