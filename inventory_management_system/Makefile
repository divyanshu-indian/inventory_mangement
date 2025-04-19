
CXX = g++
CXXFLAGS = -Wall -std=c++17 -lodbc

TARGET = inventory_app
OBJS = main.o db_operations.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS)

main.o: main.cpp db_operations.h
	$(CXX) -c main.cpp $(CXXFLAGS)

db_operations.o: db_operations.cpp db_operations.h
	$(CXX) -c db_operations.cpp $(CXXFLAGS)

clean:
	rm -f *.o $(TARGET)
