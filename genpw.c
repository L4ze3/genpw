#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sodium.h>

void print_help() {
  printf("genpw - generate strong passwords\n");
  printf("\n");
  printf("Usage:  genpw [option] lenght\n");
  printf("\n");
  printf("Options:\n");
  printf("  -l  specify lenght of password\n");
}


void generate_password(int length) {

  char characters[95] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"§$%&/()=?+#-.,*'_:;<>[]{}^~'\\";
  
  unsigned int random_num;
  
  for (int i = 0; i <= length; i++) {
    random_num = randombytes_uniform(94);
    printf("%c", characters[random_num]);
  }
  printf("\n");
}


int main(int argc, char *argv[]) {
  
  int opt;

  while ((opt = getopt(argc, argv, "l:")) != -1) {
    switch (opt) {
      case 'l':
        generate_password(atoi(optarg));
        break;

      default:
        print_help();
        exit(EXIT_FAILURE);
    }
  }

  return 0;
}
