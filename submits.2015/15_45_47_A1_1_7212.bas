Imports System.IO
Module Module1
    Dim f, t1, t2, t3, t4, defaultPath, outPath As String
    Dim i, i2, i3, last, A, B, C, D, chZAL, povtZAL As Integer
    Dim perimetrs(1000000), squares(1000000) As Integer
    Sub Main()
        defaultPath = My.Application.Info.DirectoryPath
        outPath = defaultPath & "\hall.out"
        defaultPath = defaultPath & "\hall.in"
        f = My.Computer.FileSystem.ReadAllText(defaultPath)
        t1 = ""
        t2 = ""
        t3 = ""
        t4 = ""
        chZAL = 0
        povtZAL = 0
        For i = 0 To f.Length - 1
            t1 = t1 & f.Substring(i, 1)
            If f.Substring(i, 1) = " " Then
                last = i + 1
                Exit For
            End If
        Next

        For i = last To f.Length - 1
            t2 = t2 & f.Substring(i, 1)
            If f.Substring(i, 1) = " " Then
                last = i + 1
                Exit For
            End If
        Next

        For i = last To f.Length - 1
            t3 = t3 & f.Substring(i, 1)
            If f.Substring(i, 1) = " " Then
                last = i + 1
                Exit For
            End If
        Next

        For i = last To f.Length - 1
            t4 = t4 & f.Substring(i, 1)
        Next
        A = t1
        B = t2
        C = t3
        D = t4

        cacl()

        ' My.Computer.FileSystem.WriteAllText(outPath, povtZAL, False)
        File.WriteAllText(outPath, povtZAL)
    End Sub
    Sub cacl()
        For i = 1 To B
            For i2 = 1 To D
                If (i * i2) >= A And (i * i2) <= B And ((i + i2) * 2) >= C And ((i + i2) * 2) <= D Then
                    chZAL += 1
                    For i3 = 0 To chZAL
                        If perimetrs(i3) = i * i2 Then
                            perimetrs(i3) = 0
                            povtZAL += 1
                            Exit For
                        End If
                        If squares(i3) = (i + i2) * 2 Then
                            squares(i3) = 0
                            povtZAL += 1
                            Exit For
                        End If
                    Next
                    perimetrs(chZAL) = i * i2
                    squares(chZAL) = (i + i2) * 2
                End If
            Next
        Next
    End Sub
End Module