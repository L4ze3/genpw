CC = gcc
LIB = -lsodium

genpw: genpw.c
	$(CC) genpw.c -o genpw $(LIB)

clean:
	rm -f genpw.c

install:
	mv genpw /usr/bin

uninstall:
	rm -f /usr/bin/genpw
