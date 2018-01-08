#include <iostream>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <unistd.h>

static pid_t child  = 0;
static pid_t parent = 0;

void
sustain()
{
    std::cout << "enter sustain..." << std::endl;
    parent = getpid();

    /*
    signal (SIGINT, stop);
    signal (SIGHUP, stop);
    signal (SIGUSR1, xxx);
    signal (SIGUSR2, xxx);
    */

    for (size_t index = 1; ; index++)
    {
        std::cout << "enter for ... " << std::endl;

        child  = fork ();

        if (child == -1)
            _exit (0);

        if (child == 0)
        {
            /*
            signal (SIGINT, SIG_DFL);
            signal (SIGHUP, SIG_DFL);
            signal (SIGUSR1, SIG_DFL);
            signal (SIGUSR2, SIG_DFL);
            */

            std::cout << "New child " << index << " start --------" << std::endl;
            return;
        }

        std::cout << "before sleep(1)" << std::endl;
        sleep (1);

        for (;;)
        {
            std::cout << "Wait to kill child" << std::endl;
            int i;
            waitpid (child, &i, 0);
            if (kill (child, 0)) {
                std::cout << "killed and break" << std::endl;
                break;
            }
            sleep (1);
        }

        std::cout << "end for ..." << std::endl;
    }
}

int main()
{
    std::cout << "main----------------------" << std::endl;

    sustain();
}
                                                                                                                                        1,1           Top
