program circle;
var A, B, C:longint;
begin

assign (input,'circle.in'); reset (input);
assign (output, 'circle.out'); rewrite (output);

read (A);

if A mod 2 = 0 then B:=A-2;
if A mod 2<>0 then B:=A-1;

C:=B*A;
 
 write (C);
 
 end.