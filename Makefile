#generate executable file

CC := gcc
CFLAGS := -Wall -Wextra -O2
SRCS := src/app/main.c src/app/logic.c

all: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o gameoflife.exe
	$(CC) $(CFLAGS) $(SRCS) -o gameoflife

clean:
	rm -f gameoflife.exe