#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "You cannot provide more than two arguments.\n");
    exit(1);
  } 
  const char *path = (argc == 2) ? argv[1] : ".";

  printf("%s\n", path);

  // Open directory
  DIR *d = opendir(path);
  if (d == NULL) {
    fprintf(stderr, "Error opening directory.\n");
    exit(1);
  } 

  // Repeatly read and print entries
  struct dirent *ent;

  while ((ent = readdir(d)) != NULL) {
    printf("%s\n", ent->d_name);
  }


  // Close directory

  return 0;
}