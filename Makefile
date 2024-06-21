CC = gcc
CFLAGS = -Wall -g -I./src  # Add -I./src to include the src directory
LDFLAGS = -lX11 -lgtk-3

SRCS = src/main.c src/event.c src/window.c
OBJS = $(SRCS:.c=.o)

solaris: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f solaris $(OBJS)
