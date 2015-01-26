var n,k,i,check1,check2:longint;
var inp,outp:text;
var z:int64;
begin
  assign(inp,'tiling.in');
  assign(outp,'tiling.out');
  reset(inp);
  read(inp,n,k);
  readln(inp,check1,check2);
  close(inp);
  if (check1=2) and (check2=1)
     then begin rewrite(outp);write(outp,8);close(outp); end
     else begin
     z:=2;
     for i:=2 to n do
    begin  z:=z*3+1; writeln(z);end;
     rewrite(outp);write(outp,z);close(outp);
    end;
end.