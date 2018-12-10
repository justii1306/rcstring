main: main.o rcstring.o
	g++ -g -Wall $^ -o $@

rcstring.o: rcstring.cpp rcstring.h rctext.h cref.h
	g++ -g -c -Wall $< -o $@

main.o: main.cpp rcstring.h cref.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm rcstring.o main.o main
