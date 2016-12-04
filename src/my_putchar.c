/*
** my_putchar.c for my_putchar in /home/slejeune/delivery/CPool_Day07/lib
** 
** Made by Simon LEJEUNE
** Login   <slejeune@epitech.net>
** 
** Started on  Tue Oct 11 10:35:28 2016 Simon LEJEUNE
** Last update Fri Nov 11 19:14:56 2016 Simon LEJEUNE
*/

#include <unistd.h>
#include "../include/my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
}
