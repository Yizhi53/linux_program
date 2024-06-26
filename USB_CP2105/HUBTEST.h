#pragma once
#ifndef HUBTEST_H
#define HUBTEST_H

#include <iostream>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include "SPUsbManager.h"

using namespace std;
using namespace sp_usb;

#define finit_module(fd, param_values, flags) syscall(__NR_finit_module, fd, param_values, flags)
#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)
#define remove_module(mod, flags) syscall(__NR_delete_module, mod, flags)
#define search_max 10

class HUBTEST {
 public:
  enum Module {usbserial, cp210x};
  static HUBTEST *GetInstance() {
    static HUBTEST instance_;
    return &instance_;
  } 
  
  int CloseHub(char *);
  int CheckUserInput(char *); 
  ~HUBTEST();

 private:
  size_t usb_count = 0;
  
  int InsMod(Module);
  int RmMod(Module);
  void GetUsbDeviceCount();
};

#endif // !HUBTEST_H
