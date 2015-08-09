INC_DIR:=./
SRC_DIR:=
SRCS:= $(wildcard *.cc)
LIBS:= -lpthread
CXXFLAGS:= -Wall -g -std=c++11 $(LIBS)
CXX:=g++

EXE:=main

$(EXE):$(SRCS)
	$(CXX) -o $@ $^ $(CXXFLAGS) 
clean:
	rm -f $(EXE)
