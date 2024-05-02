.DEFAULT_GOAL := upsirD

SOURCES := $(wildcard src/*.c)
HEADERS := $(wildcard src/*.h)

deps/raylib/src/libraylib.a:
	make -C deps/raylib/src

upsirD: $(SOURCES) $(HEADERS) deps/raylib/src/libraylib.a 
	clang $(SOURCES) -I./deps/raylib/src/ ./deps/raylib/src/libraylib.a -lm -o upsirD

clean:
	rm upsirD
	cd deps/raylib/src && make clean
	rm compile_commands.json

