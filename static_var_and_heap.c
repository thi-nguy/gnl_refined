// ! Copy this to pythontutor to better understand static var and heap memory.

int get_next_line(char **line)
{
  static char *rest;
  char c;
  int i;
  
  c = 'a';
  rest = (char*)malloc((5 + 1) * sizeof(char));
  i = 0;
  while (i < 5)
  {
    rest[i] = c;
    c++;
    i++;
  }
  rest[i] = '\0';
  if (rest)
    {
        *line = rest;
        return (1);
    }
}

int main(void) {
  int status;
  char *line;
  
  status = get_next_line(&line);
  printf("Returned value: %d\t%s\n", status, line);
  free ((void *)line);
  line = "";
  return (0);
}