CC = gcc
CFLAGS = -std=c11 -Wall -g -Iinclude -O2

SPATH = $(p)
SFILES = $(SPATH)/$(s)
OFILES = $(SFILES:.c=.o)
OUT = $(SPATH)/a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT): $(OFILES)
	$(CC) $^ -o $@ -lm

build: clean $(OUT)

run: clean $(OUT)
	$(OUT)

all: run

clean:
	@rm -f $(OFILES) $(OUT)
