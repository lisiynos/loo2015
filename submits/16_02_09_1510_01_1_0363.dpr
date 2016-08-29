program ol1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a,b,c,d,i,j,k,l: integer;
begin
  assign(input,'hall.in');
  reset(input);
  read(a,b,c,d);
  close (input);
   k:=0; l:=0;

  for i := 1 to 10000 do begin
    for j := 1 to 10000 do begin
      if (a<=i*j) and (b>=i*j) and (2*(i+j)>=c) and (2*(i+j)<=d)
        then k:=k+1;
      if (a<=i*j) and (b>=i*j) and (2*(i+j)>=c) and (2*(i+j)<=d) and (i<>j)
        then l:=l+1;

       
 end;end;


  assign(output,'hall.out');
  rewrite(output);
  write(k-(l div 2));
  close(output);
end.