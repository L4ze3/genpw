CC = gcc
LIB = -lsodium

genpw: genpw.c
	$(CC) genpw.c -o genpw $(LIB)

install:
	mv genpw /usr/bin

uninstall:
	rm -f /usr/bin/genpw
