echo Visual Basic (.NET 4.5)
SET VBC="C:\Windows\Microsoft.NET\Framework\v4.0.30319\vbc"
SET ORIGIN=A1_6_forest
SET FIXED=A1_6_forest_fixed

%VBC% %ORIGIN%.bas
%ORIGIN%.exe
copy forest.out forest_BOM.out

%VBC% %FIXED%.bas
%FIXED%.exe

fc %ORIGIN%.bas %FIXED%.bas > diff.txt
fc /b forest.out forest_BOM.out >> diff.txt

SET SUM=C9_W_sum
%VBC% %SUM%.bas
%SUM%.exe
