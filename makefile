CC = gcc
CFLAGS = -std=c11 -Wall -g -Iinclude -O2

SFILES = $(P)
OFILES = $(SFILES:.c=.o)
OUT = a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT): $(OFILES)
	$(CC) $^ -o $@ -lm

all: $(OUT)

clean:
	@rm -f $(OFILES) $(OUT)
