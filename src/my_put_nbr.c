/*
** my_put_nbr.c for my_put_nbr in /home/slejeune/delivery/CPool_Day07/lib/my
** 
** Made by Simon LEJEUNE
** Login   <slejeune@epitech.net>
** 
** Started on  Tue Oct 11 10:42:18 2016 Simon LEJEUNE
** Last update Fri Nov 11 19:16:43 2016 Simon LEJEUNE
*/

#include "../include/my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * - 1;
    }
  if (nb <= 9)
    my_putchar(nb + '0');
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  return (nb);
}
