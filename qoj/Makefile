CC = g++
CFLAGS = -std=c++23 -Ofast -DONLINE_JUDGE -I .
LIBS = -lm
TARGET = $(t)

.PHONY: all template format clean

all: code

code: $(TARGET)
	$(CC) $(CFLAGS) $(LIBS) $(TARGET) -o code

template:
	./gent.sh $(TARGET)

format:
	git ls-files | grep -E '\.(c|cpp|cc|h)$$' | xargs clang-format -i

clean:
	@ fd -I 'code' | xargs rm -rf
	@ fd -I '.*\.(out|exe|exp|pdb|lib|dSYM)' | xargs rm -rf
