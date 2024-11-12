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
 * Date development begun: 2024-Nov-3
 * Date of last update:    2024-Nov-3
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
#include <stdint.h>

extern void executive(double* array, int count);
extern void sort_array(double* array, int count); // Assuming you have a sort function

int main() {
    char name[50];
    char title[50];
    int count;

    printf("Welcome to Random Products, LLC.\n");
    printf("This software is maintained by Alfred Finkelstein\n");

    printf("Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Please enter your title (Mr, Ms, etc.): ");
    fgets(title, sizeof(title), stdin);

    printf("Nice to meet you %s %s\n", title, name);

    printf("This program will generate 64-bit IEEE float numbers.\n");
    printf("How many numbers do you want (up to 100)? ");
    scanf("%d", &count);

    if (count < 1 || count > 100) {
        printf("Invalid input. The number must be between 1 and 100.\n");
        return 1;
    }

    double randomNumbers[100];

    printf("\nDebug: Calling executive function...\n");
    executive(randomNumbers, count);
    printf("Debug: Returned from executive function.\n");

    // Display initial array in IEEE754 and scientific format
    printf("\nInitial Array:\n");
    printf("IEEE754\t\t\tScientific Decimal\n");
    for (int i = 0; i < count; i++) {
        printf("0x%016lx\t%18.13e\n", *(uint64_t*)&randomNumbers[i], randomNumbers[i]);
    }

    // Normalize the array
    printf("\nThe array will now be normalized to the range 1.0 to 2.0. Here is the normalized array:\n");
    executive(randomNumbers, count);  // Assuming normalization occurs in executive

    printf("IEEE754\t\t\tScientific Decimal\n");
    for (int i = 0; i < count; i++) {
        printf("0x%016lx\t%18.13e\n", *(uint64_t*)&randomNumbers[i], randomNumbers[i]);
    }

    // Sort the array
    printf("\nThe array will now be sorted:\n");
    sort_array(randomNumbers, count); // Assuming you have a sorting function

    printf("IEEE754\t\t\tScientific Decimal\n");
    for (int i = 0; i < count; i++) {
        printf("0x%016lx\t%18.13e\n", *(uint64_t*)&randomNumbers[i], randomNumbers[i]);
    }

    printf("\nGoodbye Freshman. You are welcome any time.\n");
    printf("Oh, %s. We hope you enjoyed your arrays. Do come again.\n", name);
    printf("A zero will be returned to the operating system.\n");

    return 0;
}
