#!/bin/bash
# Demo script for semaphore programs (based on Stevens UNP Vol. 2, Ch. 10)

SEM_NAME="/mysem"

echo "==== Test 1: Create and print value ===="
./sem_create 1
./sem_getval
echo

echo "==== Test 2: Run wait, then abort, then get value ===="
# Run sem_wait in foreground and kill it after it prints
( ./sem_wait & sleep 1; pkill -f sem_wait )
./sem_getval
echo

echo "==== Test 3: Run wait in background and then print ===="
./sem_wait &
sleep 1
./sem_getval
echo

echo "==== Test 4: Post to semaphore ===="
./sem_post
echo

echo "==== Cleanup ===="
./sem_unlink
echo
