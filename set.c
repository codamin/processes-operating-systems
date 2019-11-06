#include "types.h"
#include "user.h"

int main(int argc, char* argv[])
{
    if(argc != 3)
        write(1, "Not enough arguments\n", sizeof("Not enough arguments\n"));
    else
    {
        if(strcmp(argv[1], "PATH") == 0)
            set_path(argv[2]);
        else
            write(1, "variable does not exist\n", sizeof("variable does not exist\n"));
    }
    return 0;
}