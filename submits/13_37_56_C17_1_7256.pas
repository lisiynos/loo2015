program hall;

var a,b,c,d,kol,i:integer;
    s:array [1..1000] of int64;

BEGIN

assign(input,'hall.in');
reset(input);
assign(output,'hall.out');
rewrite(output);

read(a,b,c,d);
kol:=0;
while a < c do begin
   for i:=1 to d do begin
      s[i]:=a*i;
      if s[i] <= b then begin
         if (s[i]*2 >= c) and (s[i]*2 <= d) then inc(kol);
      end;
   end;
   a:=a+1;
end;

write(kol);

close(input);
close(output);

END.