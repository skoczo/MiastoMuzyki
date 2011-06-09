cp ../../parser.cpp ./
cp ../../parser.h ./
qmake
make clean
make
./parserTest
