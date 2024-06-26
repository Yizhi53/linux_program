#include "HUBTEST.h"

HUBTEST::~HUBTEST(){}

int HUBTEST::CheckUserInput(char *value) {
  string i = "0", j = "1";
  int check = EXIT_SUCCESS;
  if (value != i && value != j) {
    cout << "argument only use 0 or 1" << endl;
    check = EXIT_FAILURE;
  }
  return check;
}

void HUBTEST::GetUsbDeviceCount() {
  SPUsbManager *manager = SPUsbManager::GetInstance();
  usb_count = manager->getUsbDeviceCount();
  SPUsbManager::ReleaseInstance(manager);
}

int HUBTEST::CloseHub(char *hub_state) {
  int set_hub;
  uint32_t hub_level_value = atoi(hub_state) == 0 ? 0 : 5;
  
  GetUsbDeviceCount();
  SPUsbManager *manager = SPUsbManager::GetInstance();
  
  if (usb_count > 0) {
    cout << "Remove all usb device" << endl;
    return EXIT_FAILURE;
  }
 
  manager->shutdown();
  set_hub = manager->setMaxHubTier(hub_level_value);
  manager->startup();
  SPUsbManager::ReleaseInstance(manager);
 
  if(atoi(hub_state) == true){	  
	  cout << "insmod usbserial.ko" << endl;
	  InsMod(Module::usbserial);
	  std::this_thread::sleep_for(std::chrono::milliseconds(500));
	  cout << "insmod cp210x.ko" << endl;
	  InsMod(Module::cp210x);
  }else{
	  cout << "rmmod usbserial.ko & cp210x.ko" << endl;
	  RmMod(Module::cp210x);
	  RmMod(Module::usbserial);
  }

   return EXIT_SUCCESS;
  
}

int HUBTEST::InsMod(Module module) {
	/*
  string str_command;	
  
  if (module == Module::usbserial)
    str_command = "insmod /usr/local/drivers/usbserial.ko";
  else if (module == Module::cp210x)
    str_command = "insmod /usr/local/drivers/cp210x.ko";
  
  popen(str_command.c_str(), "r");

  return EXIT_SUCCESS;
  */
  const char *params;
  string str_path;
  size_t image_size;
  struct stat st;
  void *image;
  int fd;
	
  if (module == Module::usbserial)
    str_path = "/usr/local/drivers/usbserial.ko";
  else
    str_path = "/usr/local/drivers/cp210x.ko";

  fd = open(str_path.c_str(), O_RDONLY);
  fstat(fd, &st);
  image_size = st.st_size;
  image = malloc(image_size);
  read(fd, image, image_size);
  close(fd);
  if (init_module(image, image_size, params) != 0) {
            perror("init_module");
  }
  free(image);

  return EXIT_SUCCESS;
}

int HUBTEST::RmMod(Module module) {
  string str_path;
  
  if (module == Module::usbserial)
    str_path = "usbserial";
  else if (module == Module::cp210x)
    str_path = "cp210x";

  if (remove_module(str_path.c_str(), O_NONBLOCK) != 0) {
    perror("remove_module");
  } 
  
  return EXIT_SUCCESS;
}
