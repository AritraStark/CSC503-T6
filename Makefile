CC = gcc
CFLAGS = -Wall -pthread
PROGS = sem_create sem_getval sem_wait sem_post sem_unlink

all: $(PROGS)

sem_create: sem_create.c
	$(CC) $(CFLAGS) -o $@ $^

sem_getval: sem_getval.c
	$(CC) $(CFLAGS) -o $@ $^

sem_wait: sem_wait.c
	$(CC) $(CFLAGS) -o $@ $^

sem_post: sem_post.c
	$(CC) $(CFLAGS) -o $@ $^

sem_unlink: sem_unlink.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS)
