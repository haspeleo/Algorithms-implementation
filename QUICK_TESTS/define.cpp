#include <stdio.h>

#define DEBUG_MODE 
#define OPTION


int main() {

#ifdef DEBUG_MODE
  printf(">>> debug mode ...\n");
#else
  printf("Normal mode \n");
#endif

#ifdef OPTION
  printf("Activating an option \n");
#else
  printf("Option desactivated !\n");
#endif

  return 0;
}
