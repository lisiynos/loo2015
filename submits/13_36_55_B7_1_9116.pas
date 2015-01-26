var n,i,k,x:integer;s:string;
    a:array[1..100000] of integer;
begin
assign(input, 'prizes.in');
reset(input);
assign(output, 'prizes.out');
rewrite(output);
readln(n,k);
for i:=1 to k do begin
readln(a[i]); s[i]:=s[i]+a[i];
end;
writeln(s[i]);
end.