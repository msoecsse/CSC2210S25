#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void sigchld_handler(int signum) {
    int status;
    pid_t pid = waitpid(-1, &status, WNOHANG);
    if (pid > 0) {
        printf("[Signal] Child %d terminated.\n", pid);
    }
}

int main() {
    // 1. Get current process ID
    pid_t pid = getpid();
    printf("Current PID: %d\n", pid);

    // 2. Get parent process ID
    pid_t ppid = getppid();
    printf("Parent PID: %d\n", ppid);

    // 7. Register signal handler for SIGCHLD
    signal(SIGCHLD, sigchld_handler);

    // 3. Use fork to create process
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // In child process
        printf("In child process. PID: %d, PPID: %d\n", getpid(), getppid());

        // 9. High precision timestamp
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        printf("Child Timestamp: %ld.%09ld seconds\n", ts.tv_sec, ts.tv_nsec);

        // 4. Use exec to run another program (e.g., 'ls')
        char *args[] = {"/bin/ls", "-l", NULL};
        execvp(args[0], args);

        // If exec fails
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // In parent process



	// 4b. Use exec to run 'cp' to copy a file
        // Make sure input.txt exists in your current directory
        char *args[] = {"/bin/cp", "input.txt", "copy_of_input.txt", NULL};
        execvp(args[0], args);

        // If exec fails
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // In parent process




        // 5. Fork and exec again to run another program
        pid_t child2 = fork();
        if (child2 == 0) {
            printf("Second child (exec) PID: %d\n", getpid());
            execlp("echo", "echo", "Hello from exec'd child!", NULL);
            perror("execlp failed");
            exit(EXIT_FAILURE);
        }

        // 6. Wait for child to exit
        int status;
        waitpid(child_pid, &status, 0);
        printf("Child process %d exited with status %d\n", child_pid, status);

        // 8. Get CPU usage with times
        struct tms cpu_times;
        clock_t real_time = times(&cpu_times);
        printf("CPU times - User: %ld, System: %ld\n", cpu_times.tms_utime, cpu_times.tms_stime);

        // Wait for second child
        waitpid(child2, &status, 0);
        printf("Second child %d exited.\n", child2);
    }

    return 0;
}
