{$APPTYPE CONSOLE}
uses
  SysUtils, Math;
type versh = record
    num, child, y, l, r: longint;
end;

type pair = record
   left, right: longint;
end;

const zero: pair = (left: 0; right: 0);

var tree: array[0..300000]of versh;
    root, i, n, m, size, cnt: longint;
 a : array[0..300031] of int64;
 x, ans : int64;
e, v, j, r, l  :longint;

procedure calc(t : longint);
begin
  if (t <> 0) then
   tree[t].child := tree[tree[t].l].child + 1 + tree[tree[t].r].child;
end;


function split(v, num: longint): pair;
begin
  if v = 0 then begin result := zero; exit; end;
  if tree[tree[v].l].child + 1 <= num then
  begin
     result := split(tree[v].r, num - tree[tree[v].l].child - 1);
      tree[v].r := result.left;
      result.left := v;
    end else
    begin
      result := split(tree[v].l, num);
      tree[v].l := result.right;
      result.right := v;
    end;
  tree[v].child := tree[tree[v].l].child + tree[tree[v].r].child + 1;
end;

function merge(l, r: longint): longint;
begin
  if (r = 0)or(l = 0)then result := l or r else
    if tree[l].y > tree[r].y then
    begin
      result := l;
      tree[l].r := merge(tree[l].r, r);
    end else
    begin
      result := r;
      tree[r].l := merge(l, tree[r].l);
    end;
    calc(result);
end;

function get_y: longint;
begin
  result := randomrange(1, 1000000000);
end;                          

function get(t : longint; x :longint) : longint;
begin
  if (x <= tree[tree[t].l].child) then begin
     get := get(tree[t].l, x);
     exit;
  end else begin
      if (x > tree[tree[t].l].child + 1) then begin
         get := get(tree[t].r, x - tree[tree[t].l].child - 1);
         exit;
      end;
  end;
  get := tree[t].num;
end;


procedure remove(var t : longint; index : longint);
begin
  if (index = tree[tree[t].l].child + 1) then begin
    t := merge(tree[t].l, tree[t].r);
  end
  else
    if (index <= tree[tree[t].l].child) then
      remove(tree[t].l, index)
    else
      remove(tree[t].r, index - tree[tree[t].l].child - 1);
  calc(t);
end;


procedure insertp(var t : longint; item : longint; index : longint);
var
   p : pair;
begin
  if (t = 0) then
  begin
    t := item;
    exit;
  end;
  if (tree[item].y < tree[t].y) then
  begin
    p := split(t, index);
    tree[item].l := p.left;
    tree[item].r := p.right;

    t := item;
    calc(t);
    exit;
  end;    
  if (index <= tree[tree[t].l].child) then
    insertp(tree[t].l, item, index) else
    insertp(tree[t].r, item, index - tree[tree[t].l].child - 1);
  calc(t);

end;


procedure insert(var t  :longint; index : longint; value : longint);
begin
  inc(size);
  tree[size].num := value;
  tree[size].child := 1;
  tree[size].y := get_y;
  insertp(t, size, index); 
end;

procedure print(i: longint);
begin
  if i = 0 then exit;
  print(tree[i].l);
  write(a[tree[i].num], ' ');
  print(tree[i].r);
end;


var
  subtask: longint;

begin                           
  assign(input,'river.in');
  assign(output,'river.out');
  reset(input);
  rewrite(output);

  read(n);                      
  read(subtask);

  tree[0].child := 0;
 { for i := 0 to 300000 do
  begin
    tree[i].l := 0;
    tree[i].r := 0;
    tree[i].child := 0;
  end;             }
  randomize;
  randseed := 31;
  ans := 0;
  root := 1; 
  read(x);
  tree[1].num := 1;
  tree[1].child := 1;
  tree[1].y := get_y;
  a[1] := x;
  ans := a[1] * a[1];
                                   
  for i:=2 to n do
  begin
      read(x);
      a[i] := x;
      ans := ans + a[i] * a[i];
      tree[i].num := i;
      tree[i].child := 1;
      tree[i].y := get_y;
      root := merge(root, i);
  end;
//  print(root);
  size := n;
  read(m);                     
  cnt := n;           
  writeln(ans);    
  for i := 1 to m do
    begin
        read(e, v);            
        j := get(root, v);
        x := a[j];
        ans := ans - x * x;
        if (e = 1) then begin
            remove(root, v);
            if (v = 1) then begin
                r := get(root, 1);
                ans := ans - a[r] * a[r];
                a[r] := a[r] + x;
                ans := ans + a[r] * a[r];
            end else if (v = tree[root].child + 1) then
                begin
                    l := get(root, v - 1);
                    ans := ans - a[l] * a[l];
                    a[l] := a[l] + x;
                    ans := ans + a[l] * a[l];
        end else begin
                    r := get(root, v);
                    ans := ans - a[r] * a[r];
                a[r] := a[r] + (x div 2 + x mod 2);
                    ans := ans + a[r] * a[r];
                l := get(root, v - 1);
                    ans := ans - a[l] * a[l];
                    a[l] := a[l] + (x div 2);
                    ans := ans + a[l] * a[l]; 
                end;                   
        end else begin

           a[j] := x div 2;
           inc(cnt);
           a[cnt] := ((x div 2) + (x mod 2));
           ans := ans + (a[j] * a[j]) + (a[cnt] * a[cnt]);
 

           insert(root, v, cnt);

    end;                     
        writeln(ans); 
    //print(root);        
    end;                          
                                            
  close(output);                  
end.