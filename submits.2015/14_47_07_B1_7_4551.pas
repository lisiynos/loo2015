var
n1,n,p,i,a,k:uint64;
begin
//assign(input,'tiling.in'); reset(input);
//assign(output,'tiling.out'); rewrite(output);
read(n1,p);
n:=n1-p;
k:=n1-n;
n:=round((n*2-1)*power(2,(n-1)))+1*(n-1);
for i:=1 to p do
read(a);
n:=n+k;
write(n);
end.