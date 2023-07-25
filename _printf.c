#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...) {
  int count = 0;
  va_list args;

  va_start(args, format);
  for (char *c = format; *c; c++) {
    if (*c == '%') {
      switch (*++c) {
        case 'c': {
          char ch = va_arg(args, int);
          count += printf("%c", ch);
          break;
        }
        case 's': {
          char *str = va_arg(args, char *);
          count += printf("%s", str);
          break;
        }
        case '%': {
          count += printf("%%");
          break;
        }
        default: {
          /* Invalid format specifier */
          count = -1;
          break;
        }
      }
    } else {
      count += printf("%c", *c);
    }
  }
  va_end(args);

  return count;
}

