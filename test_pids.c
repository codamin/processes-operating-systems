#include "types.h"
#include "user.h"

int main(int argc, char* argv[])
{
    int children;
    int pid = getpid();

    fork();
    fork();
    if (pid == getpid()) {
        fork();
    }
    sleep(200);
    if (pid == getpid()) {
        write(1,"start from pid : ",sizeof("start from pid : "));printi(pid);write(1, ".\n", sizeof(".\n"));
        children = get_children(3);
        write(1, "children of process 3 : ", sizeof("children of process 3 : "));printi(children);write(1, ".\n", sizeof(".\n"));
        children = get_children(4);
        write(1, "children of process 4 : ", sizeof("children of process 4 : "));printi(children);write(1, ".\n", sizeof(".\n"));
        children = get_children(5);
        write(1, "children of process 5 : ", sizeof("children of process 5 : "));printi(children);write(1, ".\n", sizeof(".\n"));
        children = get_children(6);
        write(1, "children of process 6 : ", sizeof("children of process 6 : "));printi(children);write(1, ".\n", sizeof(".\n"));
        children = get_children(7);
        write(1, "children of process 7 : ", sizeof("children of process 7 : "));printi(children);write(1, ".\n", sizeof(".\n"));
        write(1, "\n", sizeof("\n"));
    }
    
    sleep(1000);
    // wait();
    // int pid = getpid();
    // int parent_pid = get_parent_id();
    // write(1, "-- Parent of his process with pid = ", sizeof("-- Parent of his process with pid = "));printi(pid);
    // write(1, " is a process with pid = ", sizeof(" is a process with pid = "));printi(parent_pid);write(1, ".\n", sizeof(".\n"));
    // write(1, "finish.\n", sizeof("finish.\n"));
    exit();
}