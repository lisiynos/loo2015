Visual Basic BOM
================

Компилятор Visual Basic .NET 4.5 при вызове:
My.Computer.FileSystem.WriteAllText(outPath, endq & vbNewLine, False).

добавляет в начало текстового файла так называемую BOM-сигнатуру:
символы с шетнадцатеричными кодами 37 EF.

Проверяющая система открывает выходной файл как обычный текстовый ASCII-файл и не может его прочитать.
При этом она возвращает ошибку участнику: PE (Presentation error): * Формат в/в * invalid character in answer.

Приложенные файлы:
------------------
* A1_6_forest.bas - решение без исправлений.
* A1_6_forest_fixed.bas - исправленное решение.
* diff.txt - различия в решениях и выводе решений.

