var m:int64;
var n,f,j,k,i,z:longint;
var inp,outp:text;
var a:array[1..100000] of  longint;
begin
  assign(inp,'prizes.in');
  assign(outp,'prizes.out');
  reset(inp);
  readln(inp,n,k);
  for i:=1 to n do
   Read(inp,a[i]);
  close(inp);
  for i:=1 to n-k+1 do
   begin
   m:=0;
   for j:=i to i+k-1 do
    begin
    m:=m+a[j];
    if m>z then begin z:=m; f:=j-k+1;  end;
    end;
   end;
  for i:=f to f+k-1 do
   a[i]:=0;
  z:=0;
  for i:=1 to n-k+1 do
   begin
   m:=0;
   for j:=i to i+k-1 do
    begin
    m:=m+a[j];
    if m>z then begin z:=m; f:=j-k+1;  end;
    end;
   end;
 for i:=1 to n do
  write(a[i]);
  rewrite(outp);
  write(outp,z);
  close(outp);
end.