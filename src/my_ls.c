/*
** my_ls.c for my_ls in /home/slejeune/Unix_System_Prog/PSU_2016_my_ls/src
** 
** Made by Simon LEJEUNE
** Login   <slejeune@epitech.net>
** 
** Started on  Thu Dec  1 14:53:40 2016 Simon LEJEUNE
** Last update Thu Dec  1 15:12:14 2016 Simon LEJEUNE
*/

#include "my.h"
#include "t_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/type.h>

void            print_rights(struct stat dp)
{
  ((dp.st_mode & S_IFDIR) != 0) ? putstr("d") : putstr("-");
  ((dp.st_mode & S_IRUSR) != 0) ? putstr("r") : putstr("-");
  ((dp.st_mode & S_IWUSR) != 0) ? putstr("w") : putstr("-");
  ((dp.st_mode & S_IXUSR) != 0) ? putstr("x") : putstr("-");
  ((dp.st_mode & S_IRGRP) != 0) ? putstr("r") : putstr("-");
  ((dp.st_mode & S_IWGRP) != 0) ? putstr("w") : putstr("-");
  ((dp.st_mode & S_IXGRP) != 0) ? putstr("x") : putstr("-");
  ((dp.st_mode & S_IROTH) != 0) ? putstr("r") : putstr("-");
  ((dp.st_mode & S_IWOTH) != 0) ? putstr("w") : putstr("-");
  ((dp.st_mode & S_IXOTH) != 0) ? putstr("x") : putstr("-");
}

int     ls_l(char *directory)
{
  DIR   *dir;
  struct dirent *dirent;
  struct stat   *sb;
  struct passwd *passwd;
  struct group  *grp;
  char          *mtime;

  dirent = malloc(sizeof (*dirent));
  sb = malloc(sizeof (*sb));
  passwd = malloc(sizeof (*passwd));
  grp = malloc(sizeof(*grp));
  chdir(directory);
  dir = opendir(".");
  if(!directory)
    {
      exit(0);
    }
  putstr("total");
  putchar('\n');
  while((dirent = readdir(dir)) != 0)
    {
      if ((dirent->d_name[0] != '.'))
	{
	  stat(dirent->d_name, sb);
	  passwd = getpwuid(sb->st_uid);
	  putchar(' ');
	  print_rights(*sb);
	  putstr("   ");
	  putnbr(sb->st_nlink);
	  putstr("  ");
	  putstr(passwd->pw_name);
	  putchar(' ');
	  grp = getgrgid(sb->st_gid);
	  putstr(grp->gr_name);
	  putchar(' ');
	  putnbr(sb->st_size);
	  putstr(" ");
	  mtime = ctime(&(sb->st_mtimespec.tv_sec));
	  write(1, mtime + 4, 12);
	  putstr(" ");
	  putstr(dirent->d_name);
	  putchar('\n');
	}
    }
  closedir(dir);
}
