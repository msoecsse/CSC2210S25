#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler(int sig) {
    printf("Alarm triggered!\n");
}

int main() {
    signal(SIGALRM, alarm_handler);
    printf("Setting 3-second alarm...\n");
    alarm(3);  // After 3 seconds, SIGALRM is raised

    pause();  // Wait for the signal
    return 0;
}
