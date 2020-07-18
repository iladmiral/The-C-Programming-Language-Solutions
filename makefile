#Compiler 
CXX := g++

#Sources code
CODE_SOURCE := chapter-4/4-13-reverse.c


#-O is the optimization level
#levels 0 - 1 - 2 - 3 - s(size) - g (debugging) - fast
CXXFLAGS := -Os

#Errors level -W  -Wall -Werror
CXXFLAGS += -W

#Enable debugging flags
CXX_DEBUG_FLAGS := -g
CXX_DEBUG_FLAGS += -Og
CXX_DEBUG_FLAGS += -Wall


#Output excu name
FILE_EXCU := program.exe

#Output excu name (debug version)
FILE_DEBUG_EXCU := program_debug.exe

build:
	@echo "I am building your code"
	@ -std=c11 $(CXX) $(CXXFLAGS) $(CODE_SOURCE) -o $(FILE_EXCU)
	@size $(FILE_EXCU)

clean:
	@echo "Claning your code repository"
	@rm *.exe

run: clean build
	@echo "----------------RUN----------------"
	@$(FILE_EXCU)

debug:
	@ -std=c11 $(CXX) $(CXX_DEBUG_FLAGS) $(CODE_SOURCE) -o $(FILE_DEBUG_EXCU)
	@size $(FILE_DEBUG_EXCU)
