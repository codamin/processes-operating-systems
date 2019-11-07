#include "types.h"
#include "user.h"

int main(int argc, char* argv[])
{
    int elapsed_time;
    
    if (argc != 2)
        write(1, "Not enough arguments", sizeof("Not enough arguments"));
    else
    {
        int begin = get_time();
        proc_sleep(atoi(argv[1]));
        write(1, "**************************\n", sizeof("**************************\n"));
        int end = get_time();
        elapsed_time = end - begin;
        char digit[0];
        while(elapsed_time > 0)
        {
            digit[0] = elapsed_time % 10 + '0';
            elapsed_time /= 10;
            write(1, "calculated sleep duration ====>  ", sizeof("calculated sleep duration ====>  "));
            write(1, digit, 1);
        }
        write(1, "\n", 1);
        write(1, "**************************\n", sizeof("**************************\n"));
    }
}