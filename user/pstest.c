#include "kernel/types.h"
#include "kernel/pinfo.h"
#include "user/user.h"

int
main(void)
{
  struct pinfo rows[2] = {0};
  rows[1].pid = -1;

  int count = getprocs(rows, 1);
  if (count != 1 || rows[0].pid <= 0 || rows[1].pid != -1) {
    fprintf(2, "FAIL: count=%d first_pid=%d second_pid=%d\n",
            count, rows[0].pid, rows[1].pid);
    exit(1);
  }

  printf("PASS: max=1 returned one process and preserved the next slot\n");
  exit(0);
}
