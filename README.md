# Radix

Radix conversion library for non-negative integers. Works for radices 1-36 (ergo all alphanumeric radices)

## Usage

Converting from decimal to another radix returns a __string__:
```cpp
convert(1000, 16) // returns "3E8"
```

Reverting back to decimal from another radix returns an __unsigned long long integer__:
```cpp
revert("3E8", 16) // returns 1000
```

You may also want to transvert from a certain radix to another (returning a __string__):
```cpp
transvert("3E8", 16, 18) // returns "31A"
```

Keep in mind that even when calling `transvert()` with a third parameter of 10 or less, a string is still returned.

Copyright © 2014 LastWhisper (https://github.com/LastWhisper/)