    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        FileOpen(1, "sumsqr.in", OpenMode.Input)
        FileOpen(2, "sumsqr.out", OpenMode.Output)
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

        d = Val(b) ^ 2
        f = Val(c) ^ 2
        If d >= 1 And f >= d And f <= 10 ^ 9 Then
            Print(2, d + f)
        End If
        FileClose(1)
        FileClose(2)
        End
    End Sub