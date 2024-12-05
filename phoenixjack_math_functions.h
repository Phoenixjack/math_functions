#include <stdio.h> // For strtol

long hexStringToLong(const String& hexString) {
  char buffer[hexString.length() + 1];
  hexString.toCharArray(buffer, sizeof(buffer));
  char* endptr;
  long value = strtol(buffer, &endptr, 16);
  if (*endptr != '\0') {
    // Handle conversion error
    // For example, return a default value or indicate error
  }
  return value;
}
long hexCharsToLong(const char* hexString) {
  char* endptr;
  long value = strtol(hexString, &endptr, 16);
  if (*endptr != '\0') {
    // Handle conversion error
    // For example, return a default value or indicate error
  }
  return value;
}
int getweightedavg(int* curr, int* samples, int* avg) {
  int tempval = *samples * *avg;
  tempval += *curr;
  tempval /= (*samples + 1);
  return tempval;
}
bool isNumber(const char* str) {
  bool hasDecimal = false;
  if (*str == '-') {  // Check for negative sign
    str++;
  }
  while (*str) {
    if (!isdigit(*str) && *str != '.') {
      return false;
    }
    if (*str == '.') {
      if (hasDecimal) {
        return false;  // Only allow one decimal point
      }
      hasDecimal = true;
    }
    str++;
  }
  return true;
}
int integerpart(float* value) {
  return (int)(abs(*value));
}
int decimalpart(float* value) {
}
