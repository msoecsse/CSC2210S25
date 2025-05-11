# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable name -> this is the name of the final executable
TARGET = output

# Source files and object files -> this is the list of source files to be compiled
SRCS = main.c function.c # Add your source files here
OBJS = $(SRCS:.c=.o) # Convert .c files to .o files

# Default target
all: $(TARGET) # This is the default target that will be built when you run 'make'

# Linking rule -> this rule links the object files to create the final executable
$(TARGET): $(OBJS) # This rule specifies how to create the target executable
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)  

# Compilation rule -> this rule compiles the source files into object files	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ # Compile the source file into an object file

# Clean rule -> this rule removes the object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

