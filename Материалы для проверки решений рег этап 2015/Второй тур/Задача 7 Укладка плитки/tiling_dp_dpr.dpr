uses SysUtils;

const maxn = 100000;
const modulo = 1000000007;

procedure add(var value : integer; x : integer);
begin
    inc(value, x);
    if value >= modulo then
        dec(value, modulo);
end;

function getBit(msk : integer; bit : integer) : integer;
begin
    result := (msk shr bit) and 1;
end;

function notBit(msk : integer; bit : integer) : integer;
begin
    if getBit(msk, bit) = 1 then
        result := 0
    else
        result := 1;
end;

var dp : array[0..maxn, 0..3, 0..3] of integer;
    used : array[0..maxn, 0..1] of integer;
    msk : array[0..maxn] of integer;
    n, k : integer;
    i, x, y : integer;
    bit, msk_left, msk_right : integer;

begin
    reset(input, 'tiling.in');
    rewrite(output, 'tiling.out');
    read(n, k);
    for i := 1 to k do begin
        read(x, y);
        used[x, y - 1] := 1;
    end;

    for i := 1 to n do begin
        msk[i] := used[i, 0];
        msk[i] := msk[i] + 2 * used[i, 1];
    end;
                                          
    dp[1, 0, 0] := 2;
    dp[1, 0, 1] := 1;
    dp[1, 0, 2] := 1;
    dp[1, 0, 3] := 1;

    for i := 2 to n do
    for msk_left := 0 to 3 do
    for msk_right := 0 to 3 do begin
        dp[i, msk_left, msk_right] := 0;
        if msk_right = 3 then begin
            dp[i, msk_left, msk_right] := dp[i - 1, msk[i - 2], msk_left];
            continue;
        end;
        if msk_left = 3 then begin
            add(dp[i, msk_left, msk_right], ((notBit(msk_right, 0) + notBit(msk_right, 1)) * dp[i - 1, msk[i - 2], msk_left]) mod modulo);
            continue;
        end;
        if msk_right = 0 then begin
            add(dp[i, msk_left, msk_right], (dp[i - 1, msk[i - 2], msk_left] * 2) mod modulo);
            if msk_left = 0 then begin
                if i >= 3 then
                    add(dp[i, msk_left, msk_right], dp[i - 2, msk[i - 3], msk[i - 2]])
                else
                    add(dp[i, msk_left, msk_right], 1);
                add(dp[i, msk_left, msk_right], (dp[i - 1, msk[i - 2], 2] + dp[i - 1, msk[i - 2], 1]) mod modulo);
            end else begin
                if i >= 3 then 
                    add(dp[i, msk_left, msk_right], dp[i - 2, msk[i - 3], msk[i - 2]])
                else
                    add(dp[i, msk_left, msk_right], 1);
            end;
            continue;
        end;
        for bit := 0 to 1 do begin
            if (notBit(msk_right, bit) = 1) then
                add(dp[i, msk_left, msk_right], dp[i - 1, msk[i - 2], msk_left]);
            if (notBit(msk_right, bit) = 1) and (notBit(msk_left, bit) = 1) then
                add(dp[i, msk_left, msk_right], dp[i - 1, msk[i - 2], msk_left or (1 shl bit)]);
        end;
    end;
    writeln(dp[n, msk[n - 1], msk[n]]);
end.