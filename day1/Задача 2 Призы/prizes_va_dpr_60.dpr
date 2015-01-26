uses SysUtils, Math;

var
  a: array[1..1000000] of integer;
  s: array[1..1000001] of int64;
  n, k, m, i, j: integer;
  best: int64;

begin
    reset(input, 'prizes.in');
    rewrite(output, 'prizes.out');

    readln(n, k);

    for i := 1 to n do begin
        read(a[i]);
        s[i + 1] := s[i] + a[i];
    end;

    best := 1000000000;
    for i := 1 to n - k + 1 do begin
        m := 0;
        for j := 1 to n - k + 1 do begin
            if (max(i, j) < min(i + k, j + k)) then
                continue;
            m := max(m, s[j + k] - s[j]);
        end;

        best := min(best, m);
    end;

    writeln(best);
end.
