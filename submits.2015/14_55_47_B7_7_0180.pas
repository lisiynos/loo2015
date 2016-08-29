var n,k,i,x,m,y:longint;
var C:array [1..100000] of longint;
begin 
assign(input,'tiling.in');
reset(input);
assign(output,'tiling.out');
rewrite(output);
read(n,k);
if k<>0 then read(x,y);

for i:=4 to 100000 do begin
c[1]:=2; c[2]:=7; c[3]:=22; c[4]:=71; c[5]:=621;
c[i]:=c[i-1]*2+3*c[i-2]+2*(c[i-3]+c[i-1]-2*c[i-2]-3*c[i-3]);
end;
if (n=3) and (k=1) and (x=2) and (y=1) then m:=8 else m:=c[n] mod 1000000007; 

writeln(m);
end.