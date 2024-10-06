CC = g++-14
CFLAGS = -g -Wall -std=c++17 -I .
LIBS = -lm
TARGET = $(t)

.PHONY: all format clean

all: a.out

a.out: $(TARGET)
	$(CC) $(CFLAGS) $(LIBS) $(TARGET) -o a.out

format:
	git ls-files | grep -E '\.(c|cpp|cc|h)$$' | xargs clang-format -i

clean:
	@# find -E . -regex '.*\.(out|exe|exp|pdb|lib|dSYM)' | xargs rm -rf
	rm -rf *.o *.out *.dSYM

