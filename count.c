#include "types.h"
#include "user.h"

int main(int argc, char* argv[])
{  
    int number;
    if (argc != 2)
        write(1, "Not enough arguments", sizeof("Not enough arguments"));
    else
    {
        number = atoi(argv[1]);
        int old_reg_value;
        asm volatile("movl %%esi, %0" : "=r" (old_reg_value));
        asm volatile("movl %0, %%esi" : : "r" (number));
        count_num_of_digits(number);
        asm volatile("movl %0, %%esi" : : "r" (old_reg_value));
    }
}