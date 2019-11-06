#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "path.h"

int
sys_set_path(void)
{
  char* in_dirs;


  if(argstr(0, &in_dirs) < 0)
    return -1;

  memset(path_list, 0, MAX_DIRS * MAX_PATH_LENGTH);
  int cur_dir=0;
  int cur_pos=0;

  int i;
  for(i=0; i<strlen(in_dirs); i++)
  {
    if(in_dirs[i] == ':')
    {
      path_list[cur_dir][cur_pos] = '\0';
      cur_pos = 0;
      cur_dir++;
    }
    else
    {
      if(cur_pos < MAX_PATH_LENGTH - 1)
      {
        path_list[cur_dir][cur_pos] = in_dirs[i];
        cur_pos++;
      }
    }
  }
  // for(i=0; i<MAX_DIRS; i++) {
  //   cprintf("str %d %s\n", i, path_list[i]);
  // }
  return 1;
}

int
sys_count_num_of_digits(void)
{
  int num;
  asm volatile("movl %%esi, %0" : "=r" (num));
  int count = 0;
  while(num > 0) {
    num /= 10;
    count ++;
  }
  cprintf("number of digits is = %d\n", count);
  return 1;
}

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
