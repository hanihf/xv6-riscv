#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/pinfo.h"
#include "user/user.h"

static struct pinfo processes[NPROC];

static const char *
state_name(int state)
{
  static const char *const names[] = {
    "unused", "used", "sleep", "ready", "running", "zombie"
  };

  if (state < 0 || state >= (int)(sizeof(names) / sizeof(names[0])))
    return "unknown";
  return names[state];
}

int
main(void)
{
  int count = getprocs(processes, NPROC);
  if (count < 0) {
    fprintf(2, "ps: getprocs failed\n");
    exit(1);
  }

  printf("PID\tPPID\tSTATE\tSIZE\tNAME\n");
  for (int i = 0; i < count; i++) {
    struct pinfo *p = &processes[i];
    printf("%d\t%d\t%s\t%lu\t%s\n",
           p->pid, p->ppid, state_name(p->state), p->sz, p->name);
  }
  exit(0);
}
