var
    a, b, c, d: longint;
    x, miny, maxy: longint;
    ans: int64;
begin
    assign(input, 'hall.in');
    reset(input);
    assign(output, 'hall.out');
    rewrite(output);

    read(a, b, c, d);
    ans := 0;

    for x := 1 to d div 2 do begin
        if x * x > b then
            break;
        miny := x;
        if (c + 1) div 2 - x > miny then
            miny := (c + 1) div 2 - x;
        if (a + x - 1) div x > miny then
            miny := (a + x - 1) div x;
        maxy := d div 2 - x;
        if b div x < maxy then
            maxy := b div x;
        if maxy >= miny then
            ans := ans + (maxy - miny + 1);
    end;
    writeln(ans);

    close(input);
    close(output);
end.
