#!/usr/bin/tcc -run
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>

int pid;

void catcher(int sig)
{
    if (sig == SIGALRM)
    {
        kill(pid, SIGKILL);
        exit(-3);
    }
}

int main(int argc, char** argv, char** envp)
{
    struct sigaction sa;
    sa.sa_handler = catcher;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (argc < 2)
    {
        printf("usage: %s <command> <args to command>\n", argv[0]);
        exit(-2);
    }

    if (sigaction(SIGCHLD, &sa, NULL) == -1 || sigaction(SIGALRM, &sa, NULL))
    {
        perror("sigaction");
        exit(-1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(-1);
    } else if (pid == 0) {
        execvp(argv[1], argv + 1);
        perror("execvp");
        exit(-4);
    } else {
        alarm(2);
        int status;
        wait(&status);
        return 0;
    }
    return -2;
}
