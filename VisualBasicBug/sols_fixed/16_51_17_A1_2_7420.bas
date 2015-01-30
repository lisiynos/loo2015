Imports System.IO
Module Module1
    Dim f, t1, t2, t3, t4, defaultPath, outPath As String
    Dim i, i2, i3, last, n, k, C, D, chZAL, povtZAL, summa, max, r1, r2 As Integer
    Dim qw(100000) As Integer
    Dim sloh(100000) As Integer
    Sub Main()
        defaultPath = My.Application.Info.DirectoryPath
        outPath = defaultPath & "\prizes.out"
        defaultPath = defaultPath & "\prizes.in"
        summa = 0
        max = 0
        f = My.Computer.FileSystem.ReadAllText(defaultPath)
        For i = 0 To f.Length - 1
            t1 = t1 & f.Substring(i, 1)
            If f.Substring(i, 1) = " " Then
                last = i + 1
                Exit For
            End If
        Next

        For i = last To f.Length - 1

            If f.Substring(i, 1) = "0" Or f.Substring(i, 1) = "1" Or f.Substring(i, 1) = "2" Or f.Substring(i, 1) = "3" Or f.Substring(i, 1) = "4" Or f.Substring(i, 1) = "5" Or f.Substring(i, 1) = "6" Or f.Substring(i, 1) = "7" Or f.Substring(i, 1) = "8" Or f.Substring(i, 1) = "9" Then
                t2 = t2 & f.Substring(i, 1)
            Else
                last = i + 2
                Exit For
            End If
        Next
        n = t1
        k = t2
        For i2 = 0 To n - 1
            For i = last To f.Length - 1
                If f.Substring(i, 1) = " " Then
                    last = i + 1
                    Exit For
                Else
                    t3 = f.Substring(i, 1)
                    If Not t3 = "" Then qw(i2) = t3

                End If
            Next
        Next
        '==========================================================================================================================================================================================
        If Not k = 1 Then
            For i = 0 To n - 1
                summa = qw(i) + qw(i + 1)
                If max < summa Then
                    max = summa
                    r1 = i
                    r2 = i + 1
                End If
            Next
            qw(r1) = 0
            qw(r2) = 0
        Else
            For i = 0 To n - 1
                If max < qw(i) Then
                    max = qw(i)
                    r1 = i
                End If
            Next
            qw(r1) = 0
        End If
      
        max = 0

        If Not k = 1 Then
            For i = 0 To n - 1
                summa = qw(i) + qw(i + 1)
                If max < summa Then
                    max = summa
                End If
            Next
        Else
            For i = 0 To n - 1
                If max < qw(i) Then
                    max = qw(i)
                    r1 = i
                End If
            Next
        End If

        ' My.Computer.FileSystem.WriteAllText(outPath, max, False)
        File.WriteAllText(outPath, max) 
    End Sub

End Module