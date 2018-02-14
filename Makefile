all:

	gcc -o armonica_fork armonica_fork.c
    gcc -o armonica_clone armonica_clone.c
    gcc -o armonica_posix armonica_posix.c -pthread


clean:

	-f armonica_fork
    -f armonica_clone
	-f armonica_posix
