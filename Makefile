all: temcon


WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2


temcon: Makefile main.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) main.c

clean:
	rm -f temcon

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./temcon

