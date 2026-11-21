#ifndef XV6_PINFO_H
#define XV6_PINFO_H

struct pinfo {
  int pid;
  int ppid;
  int state;
  uint64 sz;
  char name[16];
};

#endif
