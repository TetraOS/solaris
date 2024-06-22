CC = gcc
CFLAGS = -Wall -g -I./src -I./include  # Add -I./src to include the src directory
LDFLAGS = -lX11 -lgtk-3

SRCS = src/main.c src/event.c src/window.c include/event.h include/window.h
OBJS = $(SRCS:.c=.o)

solaris: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f solaris $(OBJS)
