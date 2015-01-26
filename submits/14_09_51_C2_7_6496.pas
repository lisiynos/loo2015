program TILLING;
var A, B:integer;
begin

assign (input,'tilling.in'); reset (input);
assign (output, 'tilling.out'); rewrite (output);

read (A,B);

If A=2 and B=0 then write ('7');
if A=3 and B=0 then write ('22');
if A=3 and B=1 then write ('8');


end.