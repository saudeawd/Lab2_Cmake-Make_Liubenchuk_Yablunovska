.PHONY: all library examples clean

all: library examples

library:
	$(MAKE) -C library all

examples: library
	$(MAKE) -C examples all

clean:
	$(MAKE) -C examples clean
	$(MAKE) -C library clean
