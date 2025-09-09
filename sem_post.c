#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <errno.h>

#define SEM_NAME "/mysem"

int main() {
    sem_t *sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    if (sem_post(sem) == -1) {
        perror("sem_post");
        exit(EXIT_FAILURE);
    }

    int val;
    if (sem_getvalue(sem, &val) == -1) {
        perror("sem_getvalue");
        exit(EXIT_FAILURE);
    }

    printf("After sem_post, semaphore value = %d\n", val);
    sem_close(sem);
    return 0;
}
