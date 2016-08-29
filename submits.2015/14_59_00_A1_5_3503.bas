Imports System
Imports System.IO
Imports System.Text
Module Module1
    Dim defaultPath, outPath, f, n As String
    Dim st, stations, ahome, bhome, endq, homeA(100), homeB(100), sht As Integer
    Dim t, b As Double
    Sub Main()
        defaultPath = My.Application.Info.DirectoryPath
        outPath = defaultPath & "\circle.out"
        defaultPath = defaultPath & "\circle.in"
        f = My.Computer.FileSystem.ReadAllText(defaultPath)
        n = f
        endq = 0
        sht = 0


        For ahome = 1 To n
            For bhome = 1 To n
                t = ahome / 2
                b = bhome / 2
                If t = ahome \ 2 And Not b = bhome \ 2 Then
                    endq += 1
                    homeA(sht) = ahome
                    homeB(sht) = bhome
                    sht += 1
                End If
                If Not t = ahome \ 2 And b = bhome \ 2 Then
                    endq += 1
                    homeA(sht) = ahome
                    homeB(sht) = bhome
                    sht += 1
                End If


            Next
        Next

        File.WriteAllText(outPath, endq)


    End Sub

End Module