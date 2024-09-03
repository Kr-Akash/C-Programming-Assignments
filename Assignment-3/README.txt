Assignment 3


All the required explanation of the code are written in respected .cpp file.

To run the main.cpp, the command used on the console/terminal:

g++ main.cpp revwords.cpp
./a.out

or can be done using this way:

g++ -c revwords.cpp
g++ main.cpp revwords.o
./a.out


The latter way gives more flexibility in modifying the main.cpp and don't need to compile all the other .cpp files again if unmodified (i.e. compile only once) as opposed to the former method where all the .cpp files are getting compiled.

