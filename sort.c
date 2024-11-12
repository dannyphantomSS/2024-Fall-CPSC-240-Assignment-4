/*******************************************************************************
 * Program: Random Number Array Processor
 * Author: Danny 
 * Contact: 
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 3 as published by the Free
 * Software Foundation.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU General Public License for more details. A copy
 * of the GNU General Public License v3 is available here: <https://www.gnu.org/licenses/>.
 *
 * Programming language: C
 * Date development begun: 2024-Nov-2
 * Date of last update:    2024-Nov-2
 * Status: The program compiles and runs correctly, invoking assembly language code
 *         to generate, normalize, display, and sort a random number array.
 *
 * Compile: gcc -Wall -m64 -no-pie -c -o main.o main.c
 * Link:    gcc -Wall -m64 -no-pie -o random_number_generator main.o fill_random_array.o normalize_array.o show_array.o executive.o sort.o
 *
 * Operating system: Windows
 *
 * Purpose:
 * This program generates a 64-bit random number array, normalizes the values to
 * fall within the range [1.0, 2.0], displays the array in both IEEE754 and
 * scientific decimal formats, sorts the array, and displays the sorted output.
 *
 * Testing:
 * Tested on Windows Subsystem for Linux (WSL) Ubuntu 20.04 LTS, GCC 9.3.0
 * Results: Program executed successfully with sample inputs and produced
 *          correct outputs matching the expected format and structure.
 ******************************************************************************/

#include <stdio.h>

void sort_array(double* array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (array[i] > array[j]) {
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
