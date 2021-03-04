.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  sort topdownsplay

C_SOURCES =  sortScaling.cpp
C_OBJS     = sortScaling.o
MY_INCLUDES = sorting.h



CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

sort :   sortScaling.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

topdownsplay :   topdownsplay.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET) $(C_OBJS) core *~




