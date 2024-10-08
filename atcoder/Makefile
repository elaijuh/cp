CC = g++
CFLAGS = -g -Wall -Wextra -std=gnu++20 -O2 -I .
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

