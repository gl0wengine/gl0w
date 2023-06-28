exec = gl0w
sources = $(wildcard src/*.cpp)
objects = $(sources:.c=.o)
flags = -g -fPIC -lm -ldl -Wall -rdynamic

$(exec): $(objects)
	g++ $(objects) $(flags) -o $(exec)

%.o: %.cpp include/%.h include/%/%.h
	g++ -c $(flags) $< -o $@

clean:
	-rm seec
	-rm *.o
	-rm *.a
	-rm src/*.o
	-rm src/include/*.o
lint:
	clang-tidy src/*.cpp src/include/*.h