program tilling;
var A, i, k, S, v, B:LONGINT;
begin

assign (input,'tilling.in'); reset (input);
assign (output, 'tilling.out'); rewrite (output);

read (A);

S:=2*A;

v:=0;


for i:=0 to A do begin
for k:=0 to S do begin
if S=2*i+k then v:=v+1;
 end;
 end;
write(v);
end.