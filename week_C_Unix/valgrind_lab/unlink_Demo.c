//
// Created by bhattacharya on 5/1/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Simulated structure of heap chunk metadata
struct fake_chunk {
    struct fake_chunk *fd;
    struct fake_chunk *bk;
};

int main() {
    char victim[8];               // Target to overwrite
    struct fake_chunk fake;       // Fake chunk of memory
    struct fake_chunk helper;     // Helper chunk to simulate free list

    // Print original victim value
    strcpy(victim, "SAFE");
    printf("Before attack: victim = %s\n", victim);

    /
    // GOT () Is a table used by dynamic linkers to resolve function addresses
    // Suppose attacker wants to overwrite victim[0] with "EVIL"

    // Step 1: Setup fake chunk memory
      // uintptr_t is used to ensure pointer arithmetic is done correctly

    fake.fd = (struct fake_chunk *)((uintptr_t)&victim - sizeof(void*)); // victim - 8
    fake.bk = (struct fake_chunk *)"EVIL";  // What we want to write

   // Translates to: *(victim) = "EVIL"


    // Step 3: Simulate unlink
      /*This mimics a heap free chunk from the old allocator:
fd: forward pointer in the free list.
bk: backward pointer.
These are used by unlink() during memory deallocation to update the double-linked list.
* */
    // In this case, we are simulating the unlink operation
    struct fake_chunk *FD = fake.fd; // Simulate FD pointer FD pointer is a
    struct fake_chunk *BK = fake.bk; // Simulate BK pointer

    // Simulate what unlink would do
    // 8 bytes before the victim
    // *(victim - 8) = BK; // This would be the original fd pointer
    // *(victim - 8) = FD; // This would be the original fd pointer
    FD->bk = BK;   // *(victim - 8 + 8) = "EVIL" → *(victim) = "EVIL"

    // Print the overwritten value
    printf("After attack: victim = %s\n", victim);

    return 0;
}
