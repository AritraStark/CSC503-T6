#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    // For O_* constants
#include <sys/stat.h> // For mode constants
#include <semaphore.h>
#include <errno.h>
#include <string.h>

#define SEM_NAME "/mysem"

int main(int argc, char *argv[]) {
    int initval = 1; // default
    if (argc == 2)
        initval = atoi(argv[1]);

    sem_t *sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, initval);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore %s created with initial value %d\n", SEM_NAME, initval);
    sem_close(sem);
    return 0;
}
