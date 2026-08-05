# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Target executable
TARGET = main.out

# Source and object files
SRCS = main.cpp account.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: ${TARGET}

# Link object files into exevutable
${TARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${TARGET} ${OBJS}

# Compile .cpp files into .o files
%.o: %.cpp account.h
	${CXX} ${CXXFLAGS} -c $<

# Remove generated files
clean:
	rm -rf ${OBJS} ${TARGET}

# Rebuild everything
rebuild: clean all