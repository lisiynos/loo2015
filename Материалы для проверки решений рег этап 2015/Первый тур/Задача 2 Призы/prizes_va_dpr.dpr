uses SysUtils, Math;

var
  a: array[1..1000000] of integer;
  s, pref, suff: array[1..1000001] of int64;
  n, k, i: integer;
  best: int64;

begin
    reset(input, 'prizes.in');
    rewrite(output, 'prizes.out');

    readln(n, k);

    for i := 1 to n do begin
        read(a[i]);
        s[i + 1] := s[i] + a[i];
    end;

    for i := k to n do begin
        pref[i + 1] := max(pref[i], s[i + 1] - s[i - k + 1]);
    end;

    for i := n - k + 1 downto 2 do begin
        suff[i] := max(suff[i + 1], s[i + k]  - s[i]);
    end;

    best := 1000000000;
    best := best * best;
    for i := 1 to n - k + 1 do begin
        best := min(best, max(pref[i], suff[i + k]));
    end;

    writeln(best);
end.
