.SUFFIXES:
.SUFFIXES: .o .cpp

TARGET = IK FK

C_SOURCES = integerKnapsack.cpp
C_OBJS = integerKnapsack.o

CCX = g++
CXXFLAGS = -g -std=c++11 -Wall

# all: integerKnapsack fractionalKnapsack
all: $(TARGET)

.o:.cpp
	$(CCX)  -c  $(CXXFLAGS) $<  

IK : integerKnapsack.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

FK : fractionalKnapsack.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@


clean: 
	rm -f $(TARGET) $(C_OBJS) core *~


# integerKnapsack: integerKnapsack.o
# 	$(CCX) integerKnapsack.o -o integerKnapsack

# integerKnapsack.o: integerKnapsack.cpp
# 	$(CCX) $(CXXFLAGS) integerKnapsack.cpp

# fractionalKnapsack: fractionalKnapsack.o
# 	$(CCX) fractionalKnapsack.o -o fractionalKnapsack

# fractionalKnapsack.o: fractionalKnapsack.cpp
# 	$(CCX) $(CXXFLAGS) fractionalKnapsack.cpp

# ford: ford.o
# 	$(CCX) ford.o -o ford

# ford.o: ford.cpp
# 	$(CCX) $(CXXFLAGS) ford.cpp

# preflowPush: preflowPush.o
# 	$(CCX) preflowPush.o -o preflowPush

# preflowPush.o: preflowPush.cpp
# 	$(CCX) $(CXXFLAGS) preflowPush.cpp

# clean:
# 	rm -rf *o *~ integerKnapsack integerKnapsack.out fractionalKnapsack fractionalKnapsack.out ford ford.o preflowPush preflowPush.o