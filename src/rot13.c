#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "rot13.h"

static
const char
ROT13_ALPHABET[] = {
  'a','b','c','d','e',
  'f','g','h','i','j',
  'k','l','m','n','o',
  'p','q','r','s','t',
  'u','v','w','x','y',
  'z', '\0'
};

static
const size_t
ROT13_ALPHABET_LENGTH = strlen(ROT13_ALPHABET);

static
char
rot13_get_char(int j) {
  int index = j + 13;

  if(index >= ROT13_ALPHABET_LENGTH)
  {
    index = index - ROT13_ALPHABET_LENGTH;
  }

  return ROT13_ALPHABET[index];
}

extern
char*
rot13(const char *str)
{
  size_t strlength = strlen(str);
  char *result  = malloc(strlength + 1);

  for(int i = 0; i < strlength; i++)
  {
    char c = str[i];
    /* non-alpha chars are left untouched */
    if(!isalpha(c))
    {
      result[i] = c;
      continue;
    }
    for(int j = 0; j < ROT13_ALPHABET_LENGTH; j++)
    {
      /* uppercase alphabet char */
      if(isupper(c))
      {
        if(tolower(c) == ROT13_ALPHABET[j])
        {
          result[i] = toupper(rot13_get_char(j));
          break;
        }
      }
      /* lowercase alphabet char */
      else
      {
        if(c == ROT13_ALPHABET[j])
        {
          result[i] = rot13_get_char(j);
          break;
        }
      }
    }
  }
  result[strlength] = '\0';

  return result;
}