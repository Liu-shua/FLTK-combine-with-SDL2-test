# Project: PALESDL

CPP  = g++ 
CC   = gcc
OBJ  = fltksdlrender.o bmprender.o main.o 
LINKOBJ  = fltksdlrender.o bmprender.o main.o 
LIBS =-lfltk_images -lfltk -lgdi32 -lSDL2main -lSDL2 -lSDL2_image
 
BIN  =  main.exe
CXXFLAGS = $(CXXINCS)   

RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before main.exe all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "main.exe" $(LIBS)

fltksdlrender.o: fltksdlrender.cxx
	$(CPP) -c fltksdlrender.cxx -o fltksdlrender.o $(CXXFLAGS)

bmprender.o: bmprender.cxx
	$(CPP) -c bmprender.cxx -o bmprender.o $(CXXFLAGS)

main.o: main.cxx
	$(CPP) -c main.cxx -o main.o $(CXXFLAGS)
