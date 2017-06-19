/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_FASTAtools_2016
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Mon Jun 19 09:30:50 2017 Mathias
** Last update Mon Jun 19 19:26:18 2017 Mathias
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char **append_chartab(char **tab, char *str)
{
  int i;

  i = -1;
  while (tab[++i] != NULL);
  tab = realloc(tab, sizeof(char *) * (i + 2));
  tab[i] = str;
  tab[i + 1] = NULL;
  return (tab);
}

char *append_str(char *str, char *c)
{
  int i;
  int count;

  i = -1;
  count = i;
  while (c[++count] != '\0');
  while (str[++i] != '\0');
  if ((str = realloc(str, sizeof(char) * (i + 2 + count))) == NULL)
    return (NULL);
  count = -1;
  while (c[++count] != '\0')
    {
      str[i] = c[count];
      i += 1;
    }
  str[i] = '\0';
  return (str);
}

char *append_char(char *str, char c)
{
  int i;

  i = -1;
  while (str[++i] != '\0');
  if ((str = realloc(str, sizeof(char) * (i + 2))) == NULL)
    return (NULL);
  str[i] = c;
  str[i + 1] = '\0';
  return (str);
}

char **free_gaf(char **tab, char *str)
{
  int i;

  if (str != NULL)
    free(str);
  if (tab != NULL)
    {
      i = -1;
      while (tab[++i] != NULL)
	free(tab);
      free(tab);
    }
  return (NULL);
}

char **get_all_file(int fd)
{
  char *str;
  char **tab;
  char c;

  if ((str = calloc(1, sizeof(char))) == NULL ||
      (tab = malloc(sizeof(char *))) == NULL)
    return (NULL);
  tab[0] = NULL;
  while (1)
    if (read(fd, &c, 1) <= 0 || c < 0)
      break;
    else if (c == '\n' && str[0] != '\0')
      {
	if ((tab = append_chartab(tab, str)) == NULL ||
	    (str = calloc(1, sizeof(char))) == NULL)
	  return (free_gaf(tab, str));
      }
    else if (c != '\n')
      {
	if ((str = append_char(str, c)) == NULL)
	  return (free_gaf(tab, str));
	else if (c == '\0')
	  break;
      }
  return ((c != '\n' && c > 0 ? append_chartab(tab, str) : tab));
}

void my_upper(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 122 && str[i] >= 97)
	str[i] -= 32;
      i += 1;
    }
}

int is_in_sec(char c)
{
  if (c == 'A' || c == 'T' || c == 'G' || c == 'C' || c == 'N')
    return (0);
  return (1);
}

void disp_fasta(char **tab, int i)
{
  int k;

  i = -1;
  while (tab[++i] != NULL && tab[i][0] != '>');
  printf("%s\n", tab[i]);
  i += 1;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '>')
	printf("\n%s\n", tab[i]);
      else if ((k = -1) == -1)
	while (tab[i][++k] != '\0')
	  if (is_in_sec(tab[i][k]) == 0)
	    printf("%c", tab[i][k]);
      i += 1;
    }
  printf("\n");
}

void disp_arn(char **tab, int i)
{
  int k;

  i = -1;
  while (tab[++i] != NULL && tab[i][0] != '>');
  printf("%s\n", tab[i]);
  i += 1;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '>')
	printf("\n%s\n", tab[i]);
      else if ((k = -1) == -1)
	while (tab[i][++k] != '\0')
	  (is_in_sec(tab[i][k]) == 0 ?
	   (tab[i][k] == 'T' ? printf("U") : printf("%c", tab[i][k])) : 1);
      i += 1;
    }
  printf("\n");
}

void disp_rev_char(char c)
{
  char *st;
  char *to;
  int i;

  i = 0;
  st = "ATGC";
  to = "TACG";
  while (st[i] != '\0')
    {
      if (c == st[i])
	printf("%c", to[i]);
      i += 1;
    }
}

void disp_rev(char **tab, int i)
{
  int k;

  i = -1;
  while (tab[++i] != NULL && tab[i][0] != '>');
  printf("%s\n", tab[i]);
  while (tab[++i] != NULL && tab[i][0] != '>');
  while (--i != -1)
    if (tab[i][0] == '>')
      {
	while (tab[++i] != NULL && tab[i][0] != '>');
	if (tab[i] == NULL)
	  break;
	printf("\n%s\n", tab[i]);
	while (tab[++i] != NULL && tab[i][0] != '>');
      }
    else
      {
	k = -1;
	while (tab[i][++k] != '\0');
	while (--k != -1)
	  disp_rev_char(tab[i][k]);
      }
  printf("\n");
}

void disp_kmers(char **tab, int nb)
{
  printf("j'ai pas encore compris\n");
}

int my_cmp(char *str, char *cmp)
{
  int i;

  i = 0;
  while (str[i] != '\0' && cmp[i] != '\0')
    {
      if (str[i] != cmp[i])
	return (1);
      i += 1;
    }
  if (cmp[i] == '\0')
    return (0);
  return (1);
}

char **disp_cod_sec_sequel(char *tab, char **res, char **str, int sv)
{
  int k;

  if (my_cmp(&tab[sv], "ATG") == 0)
    {
      k = sv;
      while (tab[k] != '\0' && my_cmp(&tab[k], "TAA") != 0 &&
	     my_cmp(&tab[k], "TAG") != 0 && my_cmp(&tab[k], "TGA") != 0)
	{
	  if (strlen(&tab[k]) > 2)
	    strncat((*str = realloc(*str, sizeof(char) * strlen(*str) + 3)),
		    &tab[k], 3);
	  (strlen(&tab[k]) > 2 ? (k += 3) : (k += strlen(&tab[k])));
	}
      if (tab[k] == '\0')
	{
	  free(*str);
	  *str = calloc(1, sizeof(char));
	}
      else
	{
	  res = append_chartab(res, *str);
	  *str = calloc(1, sizeof(char));
	}
    }
  return (res);
}

void my_sort_tab(char **tab)
{
  int i;
  int k;
  char *tmp;

  i = -1;
  while (tab[++i] != NULL)
    if (tab[i] != NULL && tab[i + 1] != NULL)
      {
	k = 0;
	while (tab[i][k] != '\0' && tab[i + 1][k] != '\0')
	  {
	    if (tab[i][k] < tab[i + 1][k])
	      break;
	    else if (tab[i][k] > tab[i + 1][k])
	      break;
	    k += 1;
	  }
	if (tab[i][k] > tab[i + 1][k])
	  {
	    tmp = tab[i];
	    tab[i] = tab[i + 1];
	    tab[i + 1] = tmp;
	    i = -1;
	  }
      }
}

void disp_cod_sec_final(char **tab)
{
  int i;

  i = -1;
  while (tab[++i] != NULL)
    {
      printf("%s\n", tab[i]);
      free(tab[i]);
    }
  free(tab);
}

void disp_cod_sec(char **tab, int i)
{
  int sv;
  char **res;
  char **str;

  res = malloc(sizeof(char *));
  res[0] = NULL;
  *str = (char *)calloc(1, sizeof(char));
  while (tab[++i] != NULL)
    {
      if (tab[i][0] == '>')
	i += 1;
      sv = -1;
      while (tab[i][++sv] != '\0')
	res = disp_cod_sec_sequel(tab[i], res, str, sv);
    }
  free(*str);
  my_sort_tab(res);
  disp_cod_sec_final(res);
}

void free_final_tab(char **tab)
{
  int i;

  if (tab != NULL)
    {
      i = -1;
      while (tab[++i] != NULL)
	free(tab[i]);
      free(tab);
    }
  exit(0);
}

void opt(int av, char **ac, char **s)
{
  int i;
  char *str;
  void (*tab[5])(char **, int);

  tab[0] = &disp_fasta;
  tab[1] = &disp_arn;
  tab[2] = &disp_rev;
  tab[3] = &disp_kmers;
  tab[4] = &disp_cod_sec;
  str = "12345";
  if (strlen(ac[1]) == 1)
    {
      i = -1;
      while (str[++i] != '\0' && ac[1][0] != str[i]);
      if (ac[1][0] == str[i])
	{
	  tab[i](s, -1);
	  free_final_tab(s);
	}
    }
}

void clear_tab_sequel(char **tab)
{
  int i;
  int k;

  i = 0;
  while (tab[i] != NULL)
    {
      k = 0;
      if (tab[i][0] == '>')
	i += 1;
      while (tab[i][k] != '\0')
	{
	  if (is_in_sec(tab[i][k]) != 0)
	    {
	      while (tab[i][k] != '\0')
		{
		  tab[i][k] = tab[i][k + 1];
		  k += 1;
		}
	      k = -1;
	    }
	  k += 1;
	}
      i += 1;
    }
}

void clear_tab(char **tab)
{
  int i;

  i = -1;
  while (tab[++i] != NULL)
    {
      if (tab[i][0] == '>')
	i += 1;
      if (tab[i] != NULL && tab[i + 1] != NULL && tab[i + 1][0] != '>')
	{
	  tab[i] = realloc(tab[i], strlen(tab[i]) + strlen(tab[i + 1]) + 1);
	  strcat(tab[i], tab[i + 1]);
	  free(tab[i + 1]);
	  while (tab[++i] != NULL)
	    tab[i] = tab[i + 1];
	  i = -1;
	}
    }
  clear_tab_sequel(tab);
}

int main(int av, char **ac)
{
  char *str;
  char **tab;
  int i;

  if (av <= 3 && av > 1)
    {
      if ((tab = get_all_file(0)) == NULL)
	return (printf("FAIL\n") * 0 + 84);
      i = 0;
      while (tab[i] != NULL)
	{
	  if (tab[i][0] != '>')
	    my_upper(tab[i]);
	  i += 1;
	}
      clear_tab(tab);
      opt(av, ac, tab);
    }
  return (84);
}
