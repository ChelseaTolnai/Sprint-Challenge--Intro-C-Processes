#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "You cannot provide more than two arguments.\n");
    return -1;
  } 
  char *directory = (argc == 2) ? argv[1] : argv[0];

  printf("%s\n", directory);

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}