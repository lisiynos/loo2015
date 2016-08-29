var a, k, b, m, x, l, t: int64;
    i :integer;
begin
assign(input, 'forest.in')
reset(input);
assign(output, 'forest.out');
rewrite(output);
readln(a, k , b, m, x);
l := floor((x*k*m)/(a*m*(k-1)+b*k*(m-1)));
for i := -50 to 50 do
   begin
   t := l+i;
   if (t-floor(t/k))*a+(t-floor(t/m))*b >= x then
      begin
      write(t);
      break;
      end;
   end;
end.