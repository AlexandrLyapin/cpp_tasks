#include "cstring.h"
#include <cstdlib>
size_t Strlen(const char* str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

int Strcmp(const char* first, const char* second) {
  int i;
  for (i = 0; first[i] == second[i]; i++) {
    if (first[i] == '\0') {
      return 0;
    }
  }
  return first[i] - second[i];
}

int Strncmp(const char* first, const char* second, size_t count) {
  size_t i;
  for (i = 0; first[i] == second[i] && i < count; i++) {
    if (first[i] == '\0') {
      return 0;
    }
  }
  if (i == count && count != 0) {
    i--;
    return first[i] - second[i];
  }
  if (i == count && count == 0) {
    return 0;
  }
  return first[i] - second[i];
}

char* Strcpy(char* dest, const char* src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t i = 0;
  while (src[i] != '\0' && i < count) {
    dest[i] = src[i];
    i++;
  }
  if (i < count) {
    while (i < count) {
      dest[i] = '\0';
      i++;
    }
  }
  return dest;
}

char* Strcat(char* dest, const char* src) {
  int i = 0;
  while (dest[i] != '\0') {
    i++;
  }
  int y = 0;
  while (src[y] != '\0') {
    dest[i] = src[y];
    y++;
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  size_t i = 0;
  while (dest[i] != '\0') {
    i++;
  }
  size_t y = 0;
  while (src[y] != '\0' && y < count) {
    dest[i] = src[y];
    y++;
    i++;
  }
  dest[i] = '\0';
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  int i = 0;
  while (str[i] != '\0' && str[i] != symbol) {
    i++;
  }
  if (symbol == '\0') {
    return str + i;
  }
  if (str[i] == '\0') {
    return nullptr;
  }
  return str + i;
}

const char* Strrchr(const char* str, char symbol) {
  int i = 0;
  int kmax = -1;
  while (str[i] != '\0') {
    if (str[i] == symbol) {
      kmax = i;
    }
    i++;
  }
  if (symbol == '\0') {
    return str + i;
  }
  if (kmax == -1) {
    return nullptr;
  }
  return str + kmax;
}

size_t Strspn(const char* dest, const char* src) {
  size_t i, j;
  i = 0;
  while (dest[i]) {
    j = 0;
    while (src[j]) {
      if (dest[i] == src[j]) {
        break;
      }
      j++;
    }
    if (!src[j]) {
      return i;
    }
    i++;
  }
  return i;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t i, j;
  i = 0;
  while (dest[i]) {
    j = 0;
    while (src[j]) {
      if (dest[i] == src[j]) {
        return i;
      }
      j++;
    }
    i++;
  }
  return i;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  size_t i, j;
  i = 0;
  while (dest[i]) {
    j = 0;
    while (breakset[j]) {
      if (dest[i] == breakset[j]) {
        return dest + i;
      }
      j++;
    }
    i++;
  }
  return nullptr;
}

const char* Strstr(const char* str, const char* pattern) {
  int i, j;
  i = 0;
  j = 0;
  int size_pattern = 0;
  int sum = 0;
  while (pattern[size_pattern] != '\0') {
    size_pattern++;
  }
  if (pattern[0] == '\0') {
    return str;
  }
  while (str[i] != '\0') {
    int y = i;
    while (pattern[j] != '\0') {
      if (str[i] == pattern[j]) {
        sum++;
        i++;
        j++;
      } else {
        break;
      }
    }
    if (sum == size_pattern) {
      return str + y;
    }
    j = 0;
    sum = 0;
    i = y;
    i++;
  }
  return nullptr;
}