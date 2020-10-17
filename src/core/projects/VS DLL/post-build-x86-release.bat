:: Generate embarcadero linking library
implib -a Calculator_BCC.lib "..\..\..\..\out\bin\x86\Release\Calculator.dll"


:: Create directory if doesnt exist
mkdir "..\..\..\..\out\lib\x86\Release\"


:: Move linking libraries to lib directory
move "..\..\..\..\out\bin\x86\Release\Calculator.lib" "..\..\..\..\out\lib\x86\Release\"
move Calculator_BCC.lib "..\..\..\..\out\lib\x86\Release\"