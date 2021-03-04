.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  heapmoves KMP

C_SOURCES =  main.cpp KMP.cpp
C_OBJS     = main.o KMP.o

CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

heapmoves :   main.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

KMP :   KMP.o
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================

clean:
	rm -f $(TARGET) $(C_OBJS) core *~




