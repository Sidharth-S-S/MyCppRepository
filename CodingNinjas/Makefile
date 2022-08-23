#Very basic make file for building the project and cleaning the executables when necesary
# Any file to add to which is already defining a lot of make file settings, then we need to use "include" e.g. include C:/myFolder/include/MakeDefs.win64
CFLAGS=-Wall -g
clean:
	rm -f BasicFile
all:
	CFLAGS=-Wall -g
	-MyFile.o -MyFile1.o

#custom make file
#DISABLE RTTI INFO    -fno-rtti
ELIDE = -fno-elide-constructors
# nm -g -C --defined-only ${PROGNAME}.o
FILE=lambda_defaultargs
all:EXE
   
EXE:OBJ
    g++ -std=c++11 ${FILE}.o -o ${FILE}.exe
OBJ:${FILE}.cpp
    g++ -std=c++11 -Wall -c  ${FILE}.cpp
MODULES:${FILE}.cpp
    g++ -fmodules-ts -std=c++2a -c ${FILE}.cpp
ASM:${FILE}.cpp
    g++ -std=c++11 -S -O0 ${FILE}.cpp
PRE:${FILE}.cpp
    g++ -std=c++11 -E  ${FILE}.cpp > ${FILE}.pre
RUN:
    .\${FILE}.exe
CLEAN:
   
    del /Q *.exe
    del /Q *.o
    del /Q *.s
    del /Q *.pre

