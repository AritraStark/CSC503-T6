#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>    // For O_* constants
#include <sys/stat.h> // For mode constants
#include <errno.h>
#include <string.h>

#define SEM_NAME "/mysem"

int main() {
    if (sem_unlink(SEM_NAME) == -1) {
        perror("sem_unlink");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore %s removed successfully\n", SEM_NAME);
    return 0;
}
