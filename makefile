CC = C:\gbdk\bin\lcc
SRC := $(patsubst %.c, %, $(wildcard src/*.c)) $(patsubst %.c, %, $(wildcard gen/*.c))
CLEANTARGET := *.o *.asm *.lst *.sym

game.gb: $(foreach src, $(SRC), $(src).o)
	$(CC) -o $@ $^ $(info $@)

gen/%.o: gen/%.c
	$(CC) -c -o $@ $^ $(info $@)

src/%.o: src/%.c
	$(CC) -c -o $@ $^ $(info $@)

.PHONY: clean print

clean:
	rm $(foreach cleantarget, $(CLEANTARGET), src/$(cleantarget)) *.ihx

cleangen:
	rm $(foreach cleantarget, $(CLEANTARGET), gen/$(cleantarget))

print:
	$(info $(foreach src, $(SRC), $(src).o))
