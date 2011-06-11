clear
echo -e '\E[47;31m'"Kopiuje plik parser.cpp"; tput sgr0

cp ../../parser.cpp ./

echo -e '\E[47;31m'"Kopiuje plik parser.h"; tput sgr0

cp ../../parser.h ./

echo -e '\E[47;31m'"Kompiluje testy"; tput sgr0

qmake
make clean
make

clear
echo -e '\E[47;31m'"Uruchamiam testy"; tput sgr0

./parserTest
