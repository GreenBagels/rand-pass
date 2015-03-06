rand-pass
=========

Generates a pseudorandom case-sensitive alphanumeric passkey of a given length using a mersenne-twister engine seeded with an implementation-defined random_device.

Usage
=====
Build the application using a C++11-compliant compiler (if you don't have one handy, it's time to upgrade)
Run it using the -l option and a positive integer value, denoting key length.

Example (if we built the application with name rand-pass):
```
./rand-pass -l 6
```
To generate a key of length 6.

To-do
=====
I'll probably put together a build configuration soon. Maybe.
