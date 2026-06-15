#pragma once

#include <Arduino.h>
#include <ctype.h>
#include <stdlib.h>

// Convert an Arduino String containing hexadecimal characters to a long.
// Invalid trailing characters are currently ignored by strtol behavior.
long hexStringToLong(const String& hexString) {
  char buffer[hexString.length() + 1];
  hexString.toCharArray(buffer, sizeof(buffer));

  char* endptr;
  long value = strtol(buffer, &endptr, 16);

  return value;
}

// Convert a null-terminated C string containing hexadecimal characters to a long.
// Invalid trailing characters are currently ignored by strtol behavior.
long hexCharsToLong(const char* hexString) {
  char* endptr;
  long value = strtol(hexString, &endptr, 16);

  return value;
}

// Return a simple running weighted average.
// samples is the number of previous samples represented by avg.
int getWeightedAvg(const int* curr, const int* samples, const int* avg) {
  int tempval = (*samples) * (*avg);
  tempval += *curr;
  tempval /= (*samples + 1);
  return tempval;
}

// Return true if the supplied C string looks like a signed decimal number.
bool isNumber(const char* str) {
  if (str == nullptr || *str == '\0') {
    return false;
  }

  bool hasDecimal = false;

  if (*str == '-') {
    str++;
  }

  if (*str == '\0') {
    return false;
  }

  while (*str) {
    if (!isdigit((unsigned char)*str) && *str != '.') {
      return false;
    }

    if (*str == '.') {
      if (hasDecimal) {
        return false;
      }
      hasDecimal = true;
    }

    str++;
  }

  return true;
}

// Return the absolute integer portion of a float.
int integerPart(const float* value) {
  return (int)(abs(*value));
}

// Return the first two decimal digits of the absolute value of a float.
// Example: 12.345 -> 34
int decimalPart(const float* value) {
  float absValue = abs(*value);
  int whole = (int)absValue;
  return (int)((absValue - whole) * 100);
}
