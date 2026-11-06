CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

studentai: main.cpp funkcijos.h studentas.h
	$(CXX) $(CXXFLAGS) main.cpp -o studentai

clean:
	rm -f studentai studentai.exe
