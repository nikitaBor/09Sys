#include <stdio.h>
#include <stdlib.h>
#include "dirScan.h"
#include <dirent.h>
#include <sys/types.h>

void scanDirectory(char *path){
  DIR *stream = opendir(path);
  struct dirent *entry;
  int size;
  struct stat sb;
  
  printf("Directories:\n");
  while((entry = readdir(stream)) && !entry->d_type){
    printf("\t%s\n", entry->d_name);
    size += entry->d_off;
  }
  printf("Files:\n");
  while(entry = readdir(stream)){
    printf("\t%s\n", entry->d_name);
    stat(strcat("path/",entry->d_name),buffer);
  }
  printf("%d\n", size);
  closedir(stream);
}
