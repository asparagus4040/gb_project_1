CC = C:\gbdk\bin\lcc
PNG = C:\gbdk\bin\png2asset
FLAG = -spr8x8 -noflip
SRC = main maps
GEN = HelmetLeft HelmetRight LegLeft1 LegLeft2 LegLeft3 LegRight1 LegRight2 LegRight3 Floor Brick
CLEANTARGET = *.o *.asm *.lst *.sym

game.gb: $(foreach src,$(SRC), src/$(src).o) $(foreach gen, $(GEN), gen/$(gen).o)
	$(CC) -o $@ $^ $(info $@)

src/%.o: src/%.c
	$(CC) -c -o $@ $^ $(info $@)

gen/%.o: gen/%.c
	$(CC) -c -o $@ $^ $(info $@)

gen/%.c: png/%.png
	$(PNG) $^ -c $@ $(FLAG) $(info $@)

.PHONY: clean cleanpng

.PRECIOUS: $(foreach gen, $(GEN), gen/$(gen).c)

clean:
	rm $(foreach cleantarget, $(CLEANTARGET), src/$(cleantarget)) *.ihx

cleanpng:
	rm $(foreach cleantarget, $(CLEANTARGET), gen/$(cleantarget))
