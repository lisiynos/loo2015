Imports System.IO
Module Module1 
    Dim i2, i, last, n, A, K, B, M, X, virubleno, endq As Integer
    Dim t1, f, qw(4), defaultPath, outPath As String
    Sub Main()
        last = 0
        n = 4
        virubleno = 0
        defaultPath = My.Application.Info.DirectoryPath
        outPath = defaultPath & "\forest.out"
        defaultPath = defaultPath & "\forest.in"
        f = My.Computer.FileSystem.ReadAllText(defaultPath)

        For i2 = 0 To n
            For i = last To f.Length - 1
                If f.Substring(i, 1) = " " Then
                    t1 = ""
                    last = i + 1
                    Exit For
                Else
                    t1 = t1 & f.Substring(i, 1)
                    qw(i2) = t1

                End If
            Next
        Next


        A = qw(0)
        K = qw(1)
        B = qw(2)
        M = qw(3)
        X = qw(4)



        For i = 1 To 100000000
            If Not i = K Then
                virubleno += A
            End If

            If Not i = M Then
                virubleno += B
            End If

            If virubleno > X Then
                endq = i
                Exit For
            End If
        Next

        ' My.Computer.FileSystem.WriteAllText(outPath, endq, False)
        File.WriteAllText(outPath, endq)

    End Sub
End Module