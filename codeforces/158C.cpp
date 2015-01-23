#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
void pwd(char list[][500], int top)
{
  char pwd[500] = "/";
  for(int i=1; i<=top; i++)
  {
    strcat(pwd,list[i]);
    strcat(pwd, "/");
  }
  puts(pwd);
}

int main()
{
  int n,top=0;
  char cmd[5], str[500], list[500][500];
  cin >> n;
  while(n--)
  {
    cin >> cmd;
    if(strcmp(cmd, "pwd") == 0)
      pwd(list, top);
    else
    {
      cin>> str;
      if(str[0] == '/') top = 0;
      char *sub;
      sub = strtok(str, "/");
      while(sub != NULL)
      {
        if(strcmp(sub,"..") == 0)
          top--;
        else if(strcmp(sub,"") != 0)
          strcpy(list[++top],sub);
        sub = strtok(NULL, "/");
      }

    }
  }

  return 0;
}


      
