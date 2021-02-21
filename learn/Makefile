
all:			default

default: 	cx16

cx16:			cl65 -t cx16 -O -m helloc.map -o HELLOC.PRG hello.c second.c

run:			x16emu -scale 2 -prg HELLOC.PRG -run -debug
