#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

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

  // Open directory
  DIR *d = opendir(path);
  if (d == NULL) {
    fprintf(stderr, "Error opening directory.\n");
    exit(1);
  } 

  // Repeatly read and print entries
  struct dirent *ent;
  struct stat buf;

  while ((ent = readdir(d)) != NULL) {
    char *file_name = ent->d_name;
    stat(file_name, &buf);
    printf("%10lld  %s\n", buf.st_size, file_name);
  }

  // Close directory
  closedir(d);

  return 0;
}