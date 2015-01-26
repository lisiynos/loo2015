program qq;
label 1;
var t:text;n,k,i,x,y,u,c,j:longint;a:array[1..100,1..2] of smallint;x0,y0,b,h:array[1..1000] of integer;
begin
assign(t,'tiling.in');
reset(t);
read(t,n,k);
for i:=1 to k do begin
read(t,x);
readln(t,y);
a[x,y]:=1;
end;
close(t);
k:=0;

1:c:=c+1;
 b[c]:=b[c]+1;
if c>0 then begin
for i:=b[c] to 5 do 
begin
y:=1;x:=1;
u:=0;
b[c]:=i;
while u=0 do begin
if a[x,y]=0 then u:=1 else 
if y=1 then y:=2 else begin  x:=x+1;y:=1;end;
end;
if x>n then u:=0;
if u=1 then begin
x0[c]:=x;
y0[c]:=y;

case i of 
1: begin a[x,y]:=1;h[c]:=i ;goto 1;end;
2:begin if (y<>2) and (a[x,2]=0) then begin a[x,1]:=1;a[x,2]:=1;h[c]:=i;goto 1;end; end;
3:begin if (y<>1) and (a[x,1]=0) then begin a[x,1]:=1;a[x,2]:=1;h[c]:=i;goto 1;end; end;
4:begin if (x<n) and (a[x+1,y]=0) then begin a[x,y]:=1;a[x+1,y]:=1;h[c]:=i;goto 1;end; end;
5:begin if (x>2) and (a[x-1,y]=0) then begin a[x,y]:=1;a[x-1,y]:=1;h[c]:=i;goto 1;end; end;
end;end;


if (b[c]=5) and (c>1)  then begin  b[c]:=0;c:=c-2;
j:=0;
x:=1;
y:=1;  
while j=0 do begin
if a[x,y]=0 then j:=1 else 
if y=1 then y:=2 else begin  x:=x+1;y:=1;end;
end;
if x>n then j:=0;
if j=0 then k:=k+1;
case h[c+1] of 
1: begin a[x0[c+1],y0[c+1]]:=0; end;
2:begin  a[x0[c+1],1]:=0;a[x0[c+1],2]:=0; end;
3:begin  a[x0[c+1],1]:=0;a[x0[c+1],2]:=0; end;
4:begin  a[x0[c+1],y0[c+1]]:=0;a[x0[c+1]+1,y0[c+1]]:=0; end;
5:begin  a[x0[c+1],y0[c+1]]:=0;a[x0[c+1]-1,y0[c+1]]:=0; end;
end;goto 1;end;
end;
end;
assign(t,'tiling.out');
rewrite(t);
write(t,k);
close(t);
end.