/*
** my_putstr.c for my_putstr in /home/slejeune/delivery/CPool_Day07/lib/my
** 
** Made by Simon LEJEUNE
** Login   <slejeune@epitech.net>
** 
** Started on  Tue Oct 11 11:03:26 2016 Simon LEJEUNE
** Last update Fri Nov 11 19:15:29 2016 Simon LEJEUNE
*/

#include "../include/my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
