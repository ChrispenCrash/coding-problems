all: move_zeroes

move_zeroes:
	g++ -o move_zeroes move_zeroes.cpp

ifeq ($(wildcard /bin/uname),)
    rm = del /q
else
    rm = rm -f
endif

clean:
	$(rm) *.exe

run:
	./move_zeroes