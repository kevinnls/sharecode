#include<stdio.h>
#include<stdlib.h>

int
main (int argc, char **argv)
{
  if (argc < 2)
    return 5;

  for (int i = 1; i < argc; i++)
    {
      int integer = atoi (argv[i]);
      char buffer[BUFSIZ];
      sprintf (buffer, "%d", integer);
      printf ("%d is %lu digits long\n", integer, strlen (buffer));
    }
}
