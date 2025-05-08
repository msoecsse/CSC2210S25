#include <stdio.h>      // For standard input/output functions like printf
#include <stdlib.h>     // For general utility functions like exit
#include <unistd.h>     // For POSIX operating system API, including fork, getpid, getppid
#include <sys/wait.h>   // For wait function

// Define the maximum depth of the binary tree
#define MAX_DEPTH 3

/**
 * @brief Recursively creates a binary tree of processes.
 *
 * Each call to this function represents a node in the process tree.
 * It prints its own PID and its parent's PID, then attempts to fork
 * two child processes (left and right).
 *
 * @param level The current depth level in the tree (root is level 0).
 */
void create_process_tree(int level) {
    // Print information about the current process
    printf("Level %d: PID=%d, PPID=%d\n", level, getpid(), getppid());

    // Base case: If maximum depth is reached, do not fork further
    if (level >= MAX_DEPTH) {
        return;
    }

    pid_t left_child_pid, right_child_pid;

    // --- Create Left Child ---
    left_child_pid = fork();

    if (left_child_pid < 0) {
        // Fork failed
        perror("fork (left) failed");
        exit(EXIT_FAILURE);
    } else if (left_child_pid == 0) {
        // --- Code executed by the Left Child ---
        create_process_tree(level + 1); // Recursive call for the next level
        exit(EXIT_SUCCESS); // Child exits after its subtree is done
    }
    // --- Code executed by the Parent (after forking left child) ---
    // Continue in the parent process to create the right child

    // --- Create Right Child ---
    right_child_pid = fork();

    if (right_child_pid < 0) {
        // Fork failed
        perror("fork (right) failed");
        // Note: The left child might already be running.
        // A more robust solution might try to kill the left child here,
        // but for simplicity, we'll just exit the parent.
        exit(EXIT_FAILURE);
    } else if (right_child_pid == 0) {
        // --- Code executed by the Right Child ---
        create_process_tree(level + 1); // Recursive call for the next level
        exit(EXIT_SUCCESS); // Child exits after its subtree is done
    }

    // --- Code executed by the Parent (after forking both children) ---
    // Parent waits for both children to terminate
    int status;
    waitpid(left_child_pid, &status, 0);  // Wait for the left child
    waitpid(right_child_pid, &status, 0); // Wait for the right child
    // printf("Level %d (PID=%d): Both children finished.\n", level, getpid());
}

/**
 * @brief Main function to start the process tree creation.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return EXIT_SUCCESS on successful execution.
 */
int main(int argc, char *argv[]) {
    printf("Starting process tree creation (Max Depth = %d)...\n", MAX_DEPTH);
    printf("Root process: PID=%d\n", getpid());

    // Start creating the tree from level 0
    create_process_tree(0);

    printf("Root process (PID=%d) finished.\n", getpid());

    return EXIT_SUCCESS;
}
