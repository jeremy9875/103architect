/*
** 103architect.c for 103architect in /home/VSridhar78/103architect
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Mon Dec 12 09:25:48 2016 Sridhar Vengadesan
** Last update Mon Dec 12 17:00:37 2016 Sridhar Vengadesan
*/
#include <math.h>
#include <stdio.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putnbr(int nb)
{
  if(nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if(nb >= 0 && nb <= 9)
    {
      my_putchar('0' + nb);
    }
  else
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  return(0);
}

int	translation(char **av, int i)
{
  int	matrice[3][3] = {1.00, 0.00, -1.00, 0.00, 1.00, 1.00, 0.00, 0.00, 1.00};
  int	a;
  int	b;
  
  printf("Translation by the vector (%s, %s)\n", av[i + 1], av[i + 2]);
  a = atoi(av[i - 1]) + atoi(av[i + 1]);
  b = atoi(av[i - 2]) + atoi(av[i + 2]);
  //my_putnbr(atoi(av[i - 1]));
  printf("(%s, %s) => (%d.00, %d.00)\n", av[i - 1], av[i - 2], a, b);
}

int	homothety(char **av, int i)
{
  printf("Homothety by the rations %s and %s\n", av[i + 1], av[i + 2]);
}

int	rotation(char **av, int i)
{
  printf("Rotation at a %s degree angle\n", av[i + 1]);
}

int	symmetry(char **av, int i)
{
  printf("Symmetry about an axis inclined with an angle of %s degrees\n", av[i + 1]);
}

int	main(int ac, char **av)
{
  int	i;
  int	n;

  n = 0;
  i = 1;
  while(av[i] != '\0')
    {
      if(av[i][n] = '-')
	{
	  n = n + 1;
	  if(av[i][n] == 't')
	    {
	      //printf("a");
	      if((av[i + 1][0] <= 57 && av[i + 1][0] >= 48) || av[i + 1][0] == 45) 
	       {
		 translation(av, i);
		 //printf("b");
	       }
	    }
	  if(av[i][n] == 'h')
	    {
	      homothety(av, i);
	    }
	  if(av[i][n] == 'r')
	    {
	      rotation(av, i);
	    }
	  if(av[i][n] == 's')
	    {
	      symmetry(av, i);
	    }
	}
      else
	printf("Error");
      i = i + 1;
      n = 0;
    }
}
