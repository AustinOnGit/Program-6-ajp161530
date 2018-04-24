#Austin Prochaska
#Ajp161530
#ajp161530@utdallas.edu

CXX = g++
CDXXFLAGS = -Wall -g -Wno-write-strings
CPPFLAGS  = -I/scratch/perkins/include
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

EXECFILE = program6

OBJS = program6CDK.o

all: $(EXECFILE)

clean:
	@rm -f $(OBJS) $(EXECFILE) *.P *~ \#*

$(EXECFILE): $(OBJS)
	@$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
