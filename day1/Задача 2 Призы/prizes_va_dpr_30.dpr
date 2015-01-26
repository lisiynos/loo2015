uses SysUtils, Math;

var
  a: array[1..1000000] of integer;
  n, k, m, s2, i, j, q: integer;
  best: int64;

begin
    reset(input, 'prizes.in');
    rewrite(output, 'prizes.out');

    readln(n, k);

    for i := 1 to n do begin
        read(a[i]);
    end;

    best := 1000000000;
    for i := 1 to n - k + 1 do begin
        m := 0;
        for j := 1 to n - k + 1 do begin
            if (max(i, j) < min(i + k, j + k)) then
                continue;
            s2 := 0;
            for q := 1 to k do begin
                s2 := s2 + a[j + q - 1];
            end;
            m := max(m, s2);
        end;

        best := min(best, m);
     end;

    writeln(best);
end.
