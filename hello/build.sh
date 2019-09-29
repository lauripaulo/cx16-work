
# Compiler
cc65 -O -t cx16 hello.c

# Assembler
ca65 hello.s
ca65 -t cx16 text.s

# Linker
ld65 -o hello.prg -t cx16 hello.o text.o c64.lib

# Emulator
x16emu -prg hello.prg &