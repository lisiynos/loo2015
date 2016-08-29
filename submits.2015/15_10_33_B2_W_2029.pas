program reka;
type dlin = array of longint;
var n,p,s,i,k,ki:longint;
    a,vi,ei:dlin;
begin
  assign(input,'river.in');
  assign(output,'river.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n-1 do
    read(a[i]);
  readln(a[n]);
  readln(k);
  for ki:=1 to k do
    readln(ei[ki],vi[ki]);
  s:=0;
  for i:=1 to n do
    s:=s+sqr(a[i]);
  writeln(s);
  for ki:=1 to k do
    begin
      if ei[ki]=1 then
        begin
          if vi[ki]=1 then
            begin
              s:=s-sqr(a[1])-sqr(a[2])+sqr(a[1]+a[2]);
              a[1]:=a[1]+a[2];
              for i:=2 to n-1 do
                  a[i]:=a[i+1]
            end
          else
            begin
              if vi[ki]=n then
                begin
                  s:=s-sqr(a[n-1])-sqr(a[n])+sqr(a[n-1]+a[n]);
                  a[n-1]:=a[n]
                end
              else
                begin
                  s:=s-sqr(a[vi[ki]-1])-sqr(a[vi[ki]])-sqr(a[vi[ki]+1]);
                  if a[vi[ki]] mod 2 = 0 then a[vi[ki]-1]:=a[vi[ki]-1]+a[vi[ki]] div 2
                  else a[vi[ki]-1]:=a[vi[ki]-1]+a[vi[ki]] div 2 +1;
                  a[vi[ki]+1]:=a[vi[ki]+1]+a[vi[ki]] div 2;
                  for i:=vi[ki] to n-1 do
                    a[vi[ki]]:=a[vi[ki]+1];
                  s:=s+sqr(a[vi[ki]-1])+sqr(a[vi[ki]])
                end
            end;
          writeln(s);
          n:=n-1
        end
      else
        begin
          n:=n+1;
          s:=s-sqr(a[vi[ki]]);
          for i := n  downto vi[ki]+2 do
            a[i]:=a[i+1];
          if a[vi[ki]] div 2=0 then a[vi[ki]]:=a[vi[ki]]div 2
          else a[vi[ki]]:=a[vi[ki]]div 2+1;
          a[vi[ki]+1]:=a[vi[ki]]div 2;
          s:=s+sqr(a[vi[ki]+1])+sqr(a[vi[ki]]);
          writeln(s)
        end
    end;
  close(input);
  close(output)
end.
