program _1;

var
 A,B, X,S, M, K, f, kk, mm: integer;
 i:real;

begin
assign(input,'forest.in');
assign(output,'forest.out');
reset(input);
rewrite(output);

  i := 0;
  
  f := 0;
  readln(A, K, B, M, X);
  mm := M;
  kk := K;
  S:=A+B;
  
  if mm>kk then mm:=kk ;
  if (X/(A+B))<mm then
  begin
    i:=round((x/(A+B)));
    if x mod S= 1 then i:=i+1;
  end
  Else
    begin
  
  
  
  
  while X > 0 do
  begin
    i := i + 1;
    f := 0;
    if (kk = 0) and (mm = 0) then 
      
      f := 1 Else
    begin
      if (kk = 0)and (f=0) then
      begin
        X := X - B;
        mm := mm - 1;
             end;
      if (mm = 0)  then
      begin
        kk := kk - 1;
        X := X - A;
             end;
      if (kk <> 0) and (mm <> 0)  then 
      begin
      X := X - (A + B);
      mm:=mm-1;
      
      kk:=kk-1;
      end;
    end;
    
    if kk=0 then kk:=K+1;
    if mm=0 then mm:=M+1;
  end;
  end;
  write(i);
end.