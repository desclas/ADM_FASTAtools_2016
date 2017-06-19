/*
** requirement.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_FASTAtools_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 19 09:04:24 2017 Mathias
** Last update Mon Jun 19 09:20:12 2017 Mathias
*/

int is_alphanum(char c)
{
  if (!(c <= 122 && c >= 97) && !(c <= 90 && c >= 65) & !(c <= 58 && c >= 47))
    return (1);
  return (0);
}

char *my_strcapitalize_synthesis(char *str)
{
  int i;

  i = 1;
  if (str[0] <= 122 && str[0] >= 97)
    str[0] -=  32;
  while (str[i] != '\0')
    {
      if (is_alphanum(str[i]) != 0)
	{
	  while (is_alphanum(str[i]) != 0)
	    i += 1;
	  if (str[i] <= 122 && str[i] >= 97)
	    str[i] -= 32;
	}
      else if (str[i] <= 90 && str[i] >= 65)
	str[i] += 32;
      i += 1;
    }
  return (str);
}
