# https://codeforces.com/blog/entry/121114
TARGET = $(t)
CONTEST = $(c)
PROBLEM = $(p)
suf = $(suffix $(TARGET))
ifeq ($(suf), .c)
CC = gcc
CFLAGS = -std=c11 -static -fno-asm -lm -s -O2
else
CC = g++
CFLAGS = -std=c++23 -static -O2
endif

.PHONY: all template format clean

all: a.out

a.out: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET) -o a.out

template:
	# ./gent.sh $(TARGET)
	python util.py template -c $(CONTEST) -p $(PROBLEM)

format:
	git ls-files | grep -E '\.(c|cpp|cc|h)$$' | xargs clang-format -i

clean:
	@# find -E . -regex '.*\.(out|exe|exp|pdb|lib|dSYM)' | xargs rm -rf
	rm -rf *.o *.out *.dSYM

