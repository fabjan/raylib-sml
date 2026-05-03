main: main.sml core.sml raylib.sml libmraylib.so
	$(MOSMLHOME)/bin/mosmlc -o main core.sml raylib.sml main.sml

libmraylib.so: raylib.sml.c
	$(CC) -fPIC -I$(MOSMLHOME)/include/mosml -I./raylib-5.5_linux_amd64/include/ -o libmraylib.so -shared raylib.sml.c -L./raylib-5.5_linux_amd64/lib/ -l:libraylib.a -lm

raylib.sml raylib.sml.c: ./raylib_parser
	./raylib_parser -f SML -i ./raylib-5.5_linux_amd64/include/raylib.h -o raylib.sml

raylib_parser: raylib_parser.c
	$(CC) -Wall -Wextra -o raylib_parser raylib_parser.c
