#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/*
# base var
*/
const char *PromptString = "Theshell> ";

/*
# init func
*/
void Prompt();
char *UserEntry();
void Loop();
void GetTabCommand(char *Entry);
void ListDir();
/*
# Main
*/
int main()
{
  Loop();
  return 0;
}

/*
# Loop input user and prompt
*/
void Loop()
{
  Prompt();
  char *Entry = UserEntry();
  GetTabCommand(Entry);
  Loop();
}

void Prompt()
{
  printf("%s", PromptString);
}

char *UserEntry()
{
  static char Entry[1000];
  fgets(Entry, sizeof(Entry), stdin);
  Entry[strcspn(Entry, "\n")] = '\0';
  return Entry;
}

/*
# Parsing
*/
void GetTabCommand(char *Entry)
{
  if (strcmp(Entry, "ls") == 0)
  {
    ListDir();
  }
}

/*
# Commande
*/
void ListDir(){
  struct dirent *entity;
  DIR *dp;
  dp = opendir(".");
  if(dp == NULL){
    perror("opendir");
  }

  while((entity = readdir(dp))){
    printf("%s\n", entity -> d_name);
  }

  closedir(dp);
}
