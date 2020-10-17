:: Generate embarcadero linking library
implib -a Calculator_BCC.lib "..\..\..\..\out\bin\x86\Debug\Calculator.dll"


:: Create directory if doesnt exist
mkdir "..\..\..\..\out\lib\x86\Debug\"


:: Move linking libraries to lib directory
move "..\..\..\..\out\bin\x86\Debug\Calculator.lib" "..\..\..\..\out\lib\x86\Debug\"
move Calculator_BCC.lib "..\..\..\..\out\lib\x86\Debug\"