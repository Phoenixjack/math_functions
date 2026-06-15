# math_functions

Small Arduino helper functions for common numeric and conversion tasks.

This repository contains a lightweight header-only collection of utility functions originally written for Arduino projects. The helpers cover simple hexadecimal conversion, numeric string validation, running average calculation, and basic float-part extraction.

## Project Status

Prototype / utility code.

This is not intended to be a full math library. It is a small collection of convenience functions used across embedded/Arduino experiments.

## Features

Included helper functions:

| Function            | Purpose                                                              |
| ------------------- | -------------------------------------------------------------------- |
| `hexStringToLong()` | Convert an Arduino `String` containing hex characters into a `long`  |
| `hexCharsToLong()`  | Convert a C string containing hex characters into a `long`           |
| `getWeightedAvg()`  | Calculate a simple running weighted average                          |
| `isNumber()`        | Check whether a C string appears to contain a signed decimal number  |
| `integerPart()`     | Return the absolute integer portion of a float                       |
| `decimalPart()`     | Return the first two decimal digits of the absolute value of a float |

## Basic Use

Include the helper:

```cpp id="ktx6dt"
#include "math_functions.h"
```

Example:

```cpp id="rp2z45"
void setup() {
  Serial.begin(115200);

  long value = hexCharsToLong("1A3F");

  Serial.print("Hex value: ");
  Serial.println(value);

  const char* testValue = "-12.34";

  if (isNumber(testValue)) {
    Serial.println("Looks numeric");
  }
}

void loop() {
}
```

## Weighted Average Example

```cpp id="u8gppf"
int current = 42;
int previousSamples = 4;
int previousAverage = 30;

int newAverage = getWeightedAvg(&current, &previousSamples, &previousAverage);
```

This is equivalent to:

```text id="bqj3bl"
((previousSamples * previousAverage) + current) / (previousSamples + 1)
```

## Suggested Arduino IDE Layout

The Arduino IDE expects the sketch folder and main `.ino` file to share the same name.

Recommended layout:

```text id="qy65y2"
math_functions/
├── math_functions.ino
├── math_functions.h
├── README.md
└── LICENSE
```

## Known Limitations

* Prototype utility code
* Uses Arduino types such as `String`
* Hex conversion currently relies on `strtol()`
* Hex conversion does not currently return a separate success/failure flag
* `decimalPart()` returns only the first two decimal digits
* Floating-point behavior depends on the selected microcontroller platform
* Integer math may overflow if very large sample counts or averages are used

## Possible Future Improvements

Possible future improvements:

* add explicit success/failure return values for hex conversion
* add unsigned conversion helpers
* add configurable decimal digit extraction
* add overflow-safe averaging
* add examples for sensor smoothing
* add unit-style test sketches
* split Arduino-specific helpers from generic C/C++ helpers

## License

This project is released under the MIT License.

You are free to use, modify, and adapt it for your own projects. No warranty is provided, and no ongoing support or maintenance is implied.
