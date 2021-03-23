CXX=g++
SOURCES=speed.cpp util.cpp
CXXFLAGS=-pthread -O3
EXECUTABLE=speedtest
PREFIX=/usr/local/bin

all:
	$(CXX) $(SOURCES) $(CXXFLAGS) -o $(EXECUTABLE)

install: all
	cp $(EXECUTABLE) $(PREFIX)/

uninstall:
	rm -f $(PREFIX)/$(EXECUTABLE)

run: all
	./$(EXECUTABLE)

clean: $(EXECUTABLE)
	rm -f $(EXECUTABLE)
