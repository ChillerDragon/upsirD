.DEFAULT_GOAL := upsirD

deps/raylib/src/libraylib.a:
	make -C deps/raylib/src

upsirD: deps/raylib/src/libraylib.a src/main.c
	clang src/main.c ./deps/raylib/src/libraylib.a -lm -o upsirD

clean:
	rm upsirD
	rm deps/raylib/src/libraylib.a

