# all:
# g++ -std=c++11 Arrays.cpp BinomialTree.cpp BlackScholesFormulas.cpp Normals.cpp Parameters.cpp PayOff3.cpp PayOffBridge.cpp PayOffForward.cpp TreeAmerican.cpp TreeEuropean.cpp TreeProducts.cpp TreeMain.cpp -o a.out


CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=


SOURCES=Arrays.cpp BinomialTree.cpp BlackScholesFormulas.cpp Normals.cpp Parameters.cpp PayOff3.cpp PayOffBridge.cpp PayOffForward.cpp TreeAmerican.cpp TreeEuropean.cpp TreeProducts.cpp TreeMain.cpp


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

