#include "HUBTEST.h"

int main(int argc, char *const argv[]) {
  if (argc != 2) {
    cout << "program needs 1 argument" << endl;
    return EXIT_FAILURE;
  }

  if (HUBTEST::GetInstance()->CheckUserInput(argv[1]) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  } else {
    HUBTEST::GetInstance()->CloseHub(argv[1]);    
  }

  return EXIT_SUCCESS;
}
