#include <stdio.h>
#include <stdlib.h>
#include "dirScan.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void scanDirectory(char const *path){
  printf("Printing statistics from directory:\n");
  DIR *stream = opendir(path);
  struct dirent *entry;
  off_t size = 0;
  struct stat sb;
  char fullPath[256];

  printf("Files/Directories:\n");
  while(entry = readdir(stream)){ //runs until files end
    sprintf(fullPath, "%s%s", path, entry->d_name);
    stat(fullPath, &sb);
    size += sb.st_size;
    printf("\t%s", entry->d_name);
    printf(entry->d_type == DT_DIR ? " (DIRECTORY) \n" : " (FILE) \n");
  }
  printf("The contents of the directory consist of %ld  bytes.\n", size);
  closedir(stream);
}

