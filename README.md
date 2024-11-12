# 2024-Fall-CPSC-240-Assignment-4
Non-deterministic Random Numbers
Goals
Make an assembly program that provides real experience in the following:
How to obtain 64-bit random numbers without a “seed”.
How to input string data that may contain while space. [You already know this.]
How to scale random numbers to stay within a fixed range

Purpose
This program will generate up to 100 random number using the non-deterministic random
number generator found inside of modern X86 microprocessors. Initially random numbers are
generated that extend throughout the entire space of all 64-bit IEEE754 numbers.
Later the random numbers are restricted to the interval 1.0 <= Number < 2.0 or even intervals
such as 1.0 <= number < M, where M is a predetermined fixed upper limit..
