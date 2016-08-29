program summkv;
var a, b, sumsqr:longint;
begin
assign (input, 'sumsqr.in'); reset (input);
assign (output, 'sumsqr.out'); rewrite (output);
read(a, b);
sumsqr:=sqr(a)+sqr(b);
write (sumsqr);
read;
end.