CXX = g++
CXXFLAGS = -std=c++11
INCLUDES = -isystem benchmark/include
LIB_DIR = benchmark/build/src
LIBS = -lbenchmark -lpthread

SRCS = google_benchmark_hello_world.cc
EXEC = build/google_benchmark_hello_world

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -L$(LIB_DIR) $^ $(LIBS) -o $@

clean:
	rm -f $(EXEC)