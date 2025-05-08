# Make File

-- **Makefile**: A file containing a set of directives used with the make build automation tool to generate a target/goal.


# Syntax
```makefile
# Makefile syntax consists of rules, targets, dependencies, and commands.
# A rule defines how to build a target from its dependencies.
# The syntax is as follows:
target: dependencies
    command
```
# Example
```makefile
# Example Makefile
CC = gcc
CFLAGS = -Wall -g
TARGET = my_program
SOURCES = main.c utils.c
OBJECTS = $(SOURCES:.c=.o)
# Rule to build the target
$(TARGET): $(OBJECTS) # Target depends on object files
    $(CC) $(CFLAGS) -o $@ $^ # $@ is the target file and $^ are all dependencies
# Rule to build object files
%.o: %.c #Pattern rule to compile .c files into .o files
    $(CC) $(CFLAGS) -c $< -o $@ # $< is the first dependency and $@ is the target file
# Clean rule to remove generated files
clean:
    rm -f $(OBJECTS) $(TARGET)
```
# Explanation
- **CC**: The compiler to use (e.g., `gcc`).
- **CFLAGS**: Compiler flags (e.g., `-Wall` for warnings, `-g` for debugging).
- **TARGET**: The name of the final executable.
- **SOURCES**: The source files to compile.
- **OBJECTS**: The object files generated from the source files.
- **Rule to build the target**: Specifies how to create the target from its dependencies.

# Running the Makefile
- To build the target, run `make` in the terminal. This will compile the source files and create the executable.
- To clean up the generated files, run `make clean`. This will remove the object files and the executable.
- You can also specify a target to build by running `make <target>`, where `<target>` is the name of the target you want to build.
- If you want to build a specific target, you can run `make <target>` in the terminal. For example, `make my_program` will build the `my_program` target.

# Additional Notes
- Makefiles can be complex and support advanced features like variables, conditionals, and functions.
- Makefiles are commonly used in C/C++ projects, but they can be used for any type of project that requires build automation.
- Makefiles are platform-independent, but the commands and syntax may vary slightly between different operating systems.
