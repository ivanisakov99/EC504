.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  power

C_SOURCES =  myPower.cpp
C_OBJS     = myPower.o
MY_INCLUDES =

CCX = g++
CXXFLAGS = -g -std=c++11  -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

$(TARGET) :   $(C_OBJS)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================

ALL_SOURCES = makeFind $(C_SOURCES) $(MY_INCLUDES)

INPUT_FILES  =  Sorted100.txt  Sorted100K.txt  Sorted1M.txt

clean:
	rm -f $(TARGET) $(C_OBJS) core *~

tar: $(ALL_SOURCES) $(INPUT_FILES)
	tar cvf $(TARGET).tar $(ALL_SOURCES)  $(INPUT_FILES)

$(TARGET).ps: $(ALL SOURCES) 
	enscript -pcode.ps $(ALL_SOURCES)


