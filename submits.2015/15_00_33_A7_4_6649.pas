Var i1,j,i,n,p,k:integer;
a:array[1..1000] of string;
b:array[1..1000] of string;

Begin
assign(input,'search.in');reset(input);
assign(output,'search.out');rewrite(output);
readln(n,p);  // N&P
for i := 1 to n do // А Массив
 readln(a[i]);

readln(k);  //K

 for j := 1 to k do
 readln(b[j]);
 
 if p = 2 then  //Вторая подзадача
 
 for j := 1 to k do
 Begin
 If a[i] = b[j]  then
 writeln(j)
 else 
 writeln(0);
 end                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
 end.
 