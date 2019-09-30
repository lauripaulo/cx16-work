
# Compiler
cc65 -Or -v -t cx16 cballs.c

# Assembler
ca65 -v -t cx16 cballs.s
ca65 -v -t cx16 text.s

# Linker
ld65 -v -o cballs.prg \
  -t cx16 \
  -Ln cballs.lbl \
  -m cballs.map \
  cballs.o text.o \
  c64.lib

# Emulator
x16emu -run -prg cballs.prg &
