FileOpen(1, "hall.in", OpenMode.Input)
        FileOpen(2, "hall.out", OpenMode.Output)
        Dim s1, s2, s3 As Boolean, z As String, l As Byte, a1, b1, c1, d1 As String
        Dim kol As Integer
        kol = 0
        Dim a, b, c, d As Integer
        z = "" : a1 = "" : b1 = "" : c1 = "" : d1 = ""
        Input(1, z)
        For l = 0 To z.Length - 1
            If s1 = True Then
                If s2 = True Then
                    If s3 = True Then
                        d1 += z.Chars(l)
                    Else
                        c1 += z.Chars(l)

                    End If
                Else
                    b1 += z.Chars(l)
                End If
            Else
                a1 += z.Chars(l)
            End If
        Next
        a = Val(a1) : b = Val(b1) : c = Val(c1) : d = Val(d1)
        Dim xmas(0 To b - 1), xzap As Integer
        For xzap = 0 To b - 1
            xmas(xzap) = xzap + 1
        Next xzap


        Dim ymas(0 To b - 1, 0 To b - 1), yzap1, yzap2 As Integer
        For yzap1 = 0 To b - 1
            For yzap2 = 0 To b - 1
                ymas(yzap1, yzap2) = xmas(yzap1) + yzap1
            Next yzap2
        Next yzap1


        Dim provs1, provs2 As Integer
        For provs1 = 0 To b - 1
            For provs2 = 0 To b - 1
                If xmas(provs1) * ymas(provs1, provs2) > b Or xmas(provs1) * ymas(provs1, provs2) < a Or 2 * (xmas(provs1) + ymas(provs1, provs2)) > d Or 2 * (xmas(provs1) + ymas(provs1, provs2)) < c Then
                    ymas(provs1, provs2) = 0
                Else
                    kol = kol + 1
                End If
            Next provs2
        Next provs1
        Print(2, kol)
        End