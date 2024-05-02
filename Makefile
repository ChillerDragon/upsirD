.DEFAULT_GOAL := upsirD

deps/raylib/src/libraylib.a:
	make -C deps/raylib/src

upsirD: deps/raylib/src/libraylib.a src/main.c
	clang src/*.c -I./deps/raylib/src/ ./deps/raylib/src/libraylib.a -lm -o upsirD

clean:
	rm upsirD
	cd deps/raylib/src && make clean
	rm compile_commands.json

