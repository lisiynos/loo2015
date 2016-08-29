program ol2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var c,d,i,j,k,l,n,max: integer;
 a,b : array[1..10000] of int64;
begin
  assign(input,'prizes.in');
  reset(input);
  read(n,k);
  for i := 1 to n do
    read(a[i]);
  close (input);

  for i := 1 to n-k+1 do begin
    for j := i to (i+k-1) do
      b[i]:=b[i]+a[j];
  end;

  max:=b[1];  l:=b[1];

  for i := 1 to n-k+1 do
   if (b[i]>b[1]) then max:=b[i];

  for i := 1 to n-k+1 do
   if (b[i]=max) then begin
    b[i]:=0; break;  end;

   for i := 1 to n-k+1 do
   if (b[i]>b[1]) then l:=b[i];



  assign(output,'prizes.out');
  rewrite(output);
  write(l);
  close(output);
end.