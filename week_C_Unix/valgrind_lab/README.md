# Valgrind Lab - Memory Errors

## Tasks

1. Run each program under Valgrind.
2. Identify type of error (bad access, leak, use-after-free, etc.)
3. Fix the programs.
4. Verify corrected programs show no errors.

## Commands

make
make PROGRAM=bad_access valgrind-c
make PROGRAM=bad_access valgrind-cpp
make clean

Happy debugging!
