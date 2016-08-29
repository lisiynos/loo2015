program _1;
var i,j,A,B,C,D,S,P,k,l:integer;
h,n:array[1..10000] of integer;

begin
assign(input,'hall.in');
assign(output,'hall.out');
reset(input);
rewrite(output);

k:=1;
l:=0;

readln(A,B,C,D);
if B>D then
begin

For i:=1 to B do

For j:=1 to B do
begin
S:=i*j;
P:=2*(i+j);
if (S>=A) and ( S<=B) and (P>=C) and (P<=D) then 
begin
h[k]:=S;
n[k]:=p;
k:=k+1;
l:=l+1;
end;
end;
end 

Else
begin
For i:=1 to D do
For j:=1 to D do
begin
S:=i*j;
P:=2*(i+j);
if (S>=A) and ( S<=B) and (P>=C) and (P<=D) then 
begin
h[k]:=S;
n[k]:=p;
k:=k+1;
l:=l+1;
end;
end;
end;





write(l-2);
end.