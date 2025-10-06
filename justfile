cc := "gcc"
cxx := "g++"
cflags := "-std=gnu11 -Wall -O2"
cxxflags := "-std=c++23 -Wall -g -O2"
s := "a.c"

@c:
	{{cc}} {{cflags}} {{s}} -lm -o a.out

@cpp:
	{{cxx}} {{cxxflags}} {{s}} -lm -o a.out

@clean:
	rm -rf *.out





