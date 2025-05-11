#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
    const char *device = "/dev/input/event3";  // Change based on your system
    struct input_event ev;
    int fd;

    // Open the device
    fd = open(device, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open device");
        return EXIT_FAILURE;
    }

    printf("Reading from %s (Press Ctrl+C to exit)...\n", device);

    while (1) {
        ssize_t bytes = read(fd, &ev, sizeof(ev));
        if (bytes < (ssize_t) sizeof(ev)) {
            perror("Read failed");
            close(fd);
            return EXIT_FAILURE;
        }

        if (ev.type == EV_KEY) {
            if (ev.value == 1) {  // Key press
                printf("Key Pressed: code[%d]\n", ev.code);
            } else if (ev.value == 0) {  // Key release
                printf("Key Released: code[%d]\n", ev.code);
            } else if (ev.value == 2) {  // Key hold
                printf("Key Held: code[%d]\n", ev.code);
            }
        }
    }

    close(fd);
    return 0;
}
