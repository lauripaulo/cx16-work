.PHONY: all clean
all: hero.prg

hero.prg: hero.c
	cl65 -t cx16 -O -o $@ $<

#balloon.inc: balloon.png
#	python3 ../tools/png2sprite.py -n balloon $< $@

clean:
	rm -f *.inc *.o *.prg
