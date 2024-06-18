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

data_race:
	g++ -std=c++11 -o data_race_err data_race_err.cpp -lpthread

data_race_fix:
	g++ -std=c++11 -o data_race_fix data_race_fix.cpp -lpthread

