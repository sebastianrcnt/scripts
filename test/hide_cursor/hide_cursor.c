// https://syzkaller.appspot.com/bug?id=defb47bf56e1c14d5687280c7bb91ce7b608b94b
// autogenerated by syzkaller (https://github.com/google/syzkaller)

#define _GNU_SOURCE

#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};

int main(void)
{
  syscall(__NR_mmap, 0x1ffff000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
  syscall(__NR_mmap, 0x20000000ul, 0x1000000ul, 7ul, 0x32ul, -1, 0ul);
  syscall(__NR_mmap, 0x21000000ul, 0x1000ul, 0ul, 0x32ul, -1, 0ul);
  intptr_t res = 0;
  memcpy((void*)0x20000500, "/dev/fb0\000", 9);
  res = syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000500ul, 0ul, 0ul);
  if (res != -1)
    r[0] = res;
  *(uint32_t*)0x20000000 = 0x2b;
  *(uint32_t*)0x20000004 = 1;
  syscall(__NR_ioctl, r[0], 0x4610, 0x20000000ul);
  memcpy((void*)0x20000000, "/dev/fb0\000", 9);
  res =
      syscall(__NR_openat, 0xffffffffffffff9cul, 0x20000000ul, 0x800180ul, 0ul);
  if (res != -1)
    r[1] = res;
  *(uint32_t*)0x20000040 = 1;
  *(uint32_t*)0x20000044 = 1;
  syscall(__NR_ioctl, r[1], 0x4610, 0x20000040ul);
  return 0;
}