CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -g -O0
CXXFLAGS = -Wall -Wextra -g -O0

C_FILES = bad_access.c memory_leak.c use_after_free.c double_free.c
CPP_FILES = bad_access.cpp memory_leak.cpp use_after_delete.cpp double_delete.cpp

all: c_programs cpp_programs

c_programs: $(C_FILES:.c=)
$(C_FILES:.c=): %: %.c
	$(CC) $(CFLAGS) $< -o $@

cpp_programs: $(CPP_FILES:.cpp=)
$(CPP_FILES:.cpp=): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

valgrind-c: all
	valgrind --leak-check=full --track-origins=yes ./$(PROGRAM)

valgrind-cpp: all
	valgrind --leak-check=full --track-origins=yes ./$(PROGRAM)

clean:
	rm -f bad_access memory_leak use_after_free double_free
	rm -f bad_access memory_leak use_after_delete double_delete
