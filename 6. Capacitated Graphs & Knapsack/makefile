CC = g++

CFLAGS = -c -Wall -std=c++11

all: integerKnapsack fractionalKnapsack

integerKnapsack: integerKnapsack.o
	$(CC) integerKnapsack.o -o integerKnapsack

integerKnapsack.o: integerKnapsack.cpp
	$(CC) $(CFLAGS) integerKnapsack.cpp

fractionalKnapsack: fractionalKnapsack.o
	$(CC) fractionalKnapsack.o -o fractionalKnapsack

fractionalKnapsack.o: fractionalKnapsack.cpp
	$(CC) $(CFLAGS) fractionalKnapsack.cpp

clean:
	rm -rf *o *~ integerKnapsack integerKnapsack.out fractionalKnapsack fractionalKnapsack.out