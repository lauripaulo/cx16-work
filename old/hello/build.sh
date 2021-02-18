
# Compiler
cc65 -Or -v -t cx16 hello.c

# Assembler
ca65 -v -t cx16 hello.s
ca65 -v -t cx16 text.s

# Linker
ld65 -v -o hello.prg -t cx16 -Ln hello.lbl -m hello.map hello.o text.o c64.lib

# Emulator
x16emu -run -prg hello.prg &
