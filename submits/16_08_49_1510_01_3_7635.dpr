program ol3;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n,k,i,j,p,c,l: integer;
 a : array[1..10000] of integer;
 b : array[1..2,1..100] of integer;
begin
  assign(input,'river.in');
  reset(input);
  read(n,p); readln;
  for i := 1 to n do
    read(a[i]); readln;
  read(k); readln;
  for i := 1 to k do
   for j := 1 to 2 do
     read(b[i,j]);
  close (input);
  assign(output,'river.out');
  rewrite(output);
      c:=0;

  for l := 1 to n do
    c:=c+a[l]*a[l];
   write(c); writeln; c:=0;

   for i := 1 to k do begin
     {for j := 1 to 2 do begin}
        if b[i,1]=1 then begin
          if (b[i,2]=1)  then begin
            a[b[i,2]+1]:=a[b[i,2]+1]+a[b[i,2]];
            for l := b[i,2] to n-1 do
             a[l]:=a[l+1];
            n:=n-1;
            end;
          if (b[i,2]=n) and (n<>1) then begin
            a[b[i,2]-1]:=a[b[i,2]+1]+a[b[i,2]];
            for l := b[i,2] to n-1 do
             a[l]:=a[l+1];
            n:=n-1;
            end;
          if (a[b[i,2]] mod 2=0) and (b[i,2]<n) and (b[i,2]>1) then begin
            a[b[i,2]+1]:=a[b[i,2]+1]+(a[b[i,2]] div 2);
            a[b[i,2]-1]:=a[b[i,2]-1]+(a[b[i,2]] div 2);
            n:=n-1;
            end;
          if (a[b[i,2]] mod 2>0) and (b[i,2]>1) and (b[i,2]<n) then begin
            a[b[i,2]+1]:=a[b[i,2]+1]+((a[b[i,2]]+1) div 2);
            a[b[i,2]-1]:=a[b[i,2]-1]+((a[b[i,2]]-1) div 2);
            for l := b[i,2] to n-1 do
             a[l]:=a[l+1];
            n:=n-1;
        end;end;

        if b[i,1]=2 then begin
          n:=n+1;
          for l := n-1 downto b[i,2]+1 do
            a[l+1]:=a[l];
          if (a[b[i,2]] mod 2=0) then begin
            a[b[i,2]+1]:=a[b[i,2]] div 2;
            a[b[i,2]]:=a[b[i,2]] div 2;
          end
          else {(a[b[i,2]] mod 2>0) then} begin
            a[b[i,2]+1]:=(a[b[i,2]]+1) div 2;
            a[b[i,2]]:=(a[b[i,2]]-1) div 2;
          end;end; {end;}

        for l := 1 to n do
         c:=c+a[l]*a[l];
         write(c); writeln;
          c:=0;
     end;




  close(output);
end.