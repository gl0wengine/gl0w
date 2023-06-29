exec = gl0w
sources = $(wildcard src/*.cpp)
objects = $(sources:.c=.o)
flags = -g -fPIC -Wall -rdynamic
CFLAGS = -I/opt/local/include
LDFLAGS = -L/opt/local/lib -lglfw -lglm

$(exec): $(objects)
	g++ $(objects) $(flags) $(CFLAGS) $(LDFLAGS) -o $(exec) 

%.o: %.cpp include/%.h include/%/%.h
	g++ -c $(flags) $< -o $@

clean:
	-rm gl0w
	-rm *.o
	-rm *.a
	-rm src/*.o
	-rm src/include/*.o
lint:
	clang-tidy src/*.cpp src/include/*.h