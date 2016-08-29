program choosingTheHall;
var SA, SB, PA, PB, m, i, k, o, r, j:longint;
begin

read (SA, SB, PA, PB);
m:=0;
begin
for i:=PA to PB do
for k:=SA to SB do
if i mod 2=0 then begin
j:=i div 2;
  for o:=1 to j do
for r:=1 to j do
if (o<=r) and(o+r=j) and (o*r=k) then
m:=m+1;
end;
end;
write (m);
read;
end.