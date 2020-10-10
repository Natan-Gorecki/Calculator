:: Generate embarcadero linking library
mkexp Calculator_BCC.a "..\..\..\..\out\bin\x64\Debug\Calculator.dll"


:: Create directory if doesnt exist
mkdir "..\..\..\..\out\lib\x64\Debug\"


:: Move linking libraries to lib directory
move "..\..\..\..\out\bin\x64\Debug\Calculator.lib" "..\..\..\..\out\lib\x64\Debug\"
move Calculator_BCC.lib "..\..\..\..\out\lib\x64\Debug\"