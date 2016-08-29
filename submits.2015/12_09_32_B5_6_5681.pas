program _1;

var
  A, B, X, M, K, i, f, kk, mm: integer;

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
  while X > 0 do
  begin
    i := i + 1;
    kk:=kk-1;
    mm:=mm-1;
    
    f := 0;
    if (kk = 0) and (mm = 0) then 
      
      f := 1 Else
    begin
      if (kk = 0) and (f=0) then
      begin
        X := X - B;
       
             end;
      if (mm = 0)  then
      begin
        kk := kk - 1;
        X := X - A;
             end;
      if (kk <> 0) and (mm <> 0)  then 
      begin
      X := X - (A + B);
     
      
      
      end;
    end;
    
    if kk=0 then kk:=K;
    if mm=0 then mm:=M;
  end;
  write(i);
end.