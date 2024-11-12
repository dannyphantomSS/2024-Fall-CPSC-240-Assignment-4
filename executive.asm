;*******************************************************************************
; Program: Random Number Generator
; Author: Danny 
; Contact: 
;
; This program is free software: you can redistribute it and/or modify it under
; the terms of the GNU General Public License version 3 as published by the Free
; Software Foundation.
; This program is distributed in the hope that it will be useful, but WITHOUT ANY
; WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
; PARTICULAR PURPOSE. See the GNU General Public License for more details. A copy
; of the GNU General Public License v3 is available here: <https://www.gnu.org/licenses/>.
;
; Programming language: x86-64 Assembly
; Date development begun: 2024-Nov-3
; Date of last update:    2024-Nov-3
; Status: The program compiles and runs correctly, generating random numbers for the array.
;
; Assemble: nasm -f elf64 -o fill_random_array.o fill_random_array.asm
;
; Operating system: Windows
;
; Purpose:
; This module generates an array of 64-bit random numbers using the RDRAND 
; instruction. The generated values are stored in the array for later normalization
; and display in IEEE754 and scientific decimal formats.
;*******************************************************************************

section .text
global executive
extern fill_random_array, normalize_array  ; Ensure both symbols are visible

executive:
    push rbp
    mov rbp, rsp

    mov rbx, rdi  ; Pointer to array passed from main.c
    mov rcx, rsi  ; Count of numbers

    ; Call fill_random_array to populate the array
    call fill_random_array

    ; Call normalize_array to normalize the values in the array
    call normalize_array

    pop rbp
    ret
