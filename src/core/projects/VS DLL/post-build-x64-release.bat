:: Generate embarcadero linking library
mkexp Calculator_BCC.a "..\..\..\..\out\bin\x64\Release\Calculator.dll"


:: Create directory if doesnt exist
mkdir "..\..\..\..\out\lib\x64\Release\"


:: Move linking libraries to lib directory
move "..\..\..\..\out\bin\x64\Release\Calculator.lib" "..\..\..\..\out\lib\x64\Release\"
move Calculator_BCC.lib "..\..\..\..\out\lib\x64\Release\"