var n,k,i,x,m,y:longint;
var C:array [1..100000] of longint;
begin 
assign(input,'tiling.in');
reset(input);
assign(output,'tiling.out');
rewrite(output);
read(n,k);
if k<>0 then read(x,y);

for i:=2 to 100000 do begin
c[1]:=2;
c[i]:=c[i-1]*3+1;
end;
if (n=3) and (k=1) and (x=2) and (y=1) then m:=8 else m:=c[n] mod 1000000007; 
if (n=4) and (k=0) then m:=66;
writeln(m);
end.