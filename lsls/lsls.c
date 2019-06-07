#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

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
    
    if ((buf.st_mode & S_IFDIR) != 0) {
      char *path_sub = (char *) malloc(strlen(path) + 1 + strlen(file_name) + 1);
      strcpy(path_sub, path);
      strcat(path_sub, "/");
      strcat(path_sub, file_name);

      DIR *d_sub = opendir(path_sub);
      if (d_sub == NULL) {
        printf("%10lld  %s\n", buf.st_size, file_name);
        continue;
      } 
      printf("%10s  %s\n", "<DIR>", file_name);
      struct dirent *ent_sub;
      struct stat buf_sub;
      while ((ent_sub = readdir(d_sub)) != NULL) {
        char *file_name_sub = ent_sub->d_name;
        stat(file_name_sub, &buf_sub);
        if ((buf_sub.st_mode & S_IFDIR) != 0) {
          printf("          %10s  %s\n", "<DIR>", file_name_sub);
        } else {
          printf("          %10lld  %s\n", buf.st_size, file_name_sub);
        }
      }
    } else {
      printf("%10lld  %s\n", buf.st_size, file_name);
    }
  }

  // Close directory
  closedir(d);

  return 0;
}