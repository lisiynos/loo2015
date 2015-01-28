Public Class Form1
Sub Main()
        FileOpen(1, "sum.in", OpenMode.Input)
        FileOpen(2, "sum.out", OpenMode.Output)
        Dim a As String, i As Integer
        Dim b, c As String
        b = ""
        c = ""
        Dim sm As Boolean
        sm = False
        Input(1, a)
        For i = 0 To a.Length - 1
            If sm = True Then
                c += a.Chars(i)
            Else
                If a.Chars(i) = " " Then
                    sm = True
                Else
                    b += a.Chars(i)
                End If
            End If
        Next i
        Dim d, f As Integer
        d = Val(b)
        f = Val(c)
        If d >= 1 And d <= f And f <= 10 ^ 9 Then
            Print(2, d + f)
            FileClose(1)
            FileClose(2)
        End If
        End
    End Sub
End Class