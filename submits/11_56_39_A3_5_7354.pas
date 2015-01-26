var
  a, k, b, m, x, kolvo, dni:longint;
begin
  assign(input,'forest.in'); reset(input);
  assign(output,'forest.out'); rewrite(output);
  read(a, k, b, m, x);
  kolvo:=0;
  dni:=0;
  while (kolvo < x) do
  begin
    dni:=dni + 1;
    if (dni mod k <> 0) then kolvo:=kolvo + a;
    if (dni mod m <> 0) then kolvo:=kolvo + b;
  end;
  write(dni);
end.  