TARGET = $(t)
PROBLEM = $(p)
suf = $(suffix $(TARGET))
ifeq ($(suf), .c)
CC = gcc
CFLAGS = -std=gnu2x -O2 -I. -lm
else
CC = g++
CFLAGS = -std=gnu++23 -O2 \
		 -Wall -Wextra \
		 -mtune=native -march=native \
		 -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
		 -I.
endif

.PHONY: all template format clean

all: a.out

a.out: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET) -o a.out

template:
	# ./gent.sh $(TARGET)
	python util.py template -p $(PROBLEM)

format:
	git ls-files | grep -E '\.(c|cpp|cc|h)$$' | xargs clang-format -i

clean:
	@# find -E . -regex '.*\.(out|exe|exp|pdb|lib|dSYM)' | xargs rm -rf
	rm -rf *.o *.out *.dSYM

