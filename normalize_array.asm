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

global normalize_array

section .data
scale_factor dq 4096.0  ; Large divisor to normalize values

section .text
normalize_array:
    mov rcx, rsi          ; count in rcx
    mov rdi, rbx          ; pointer to array in rdi

normalize_loop:
    test rcx, rcx
    jz end_normalize      ; Exit if count is zero

    fild qword [rdi]      ; Load integer onto FPU as a floating-point value
    fld qword [scale_factor]  ; Load scale factor (4096.0)
    fdiv                  ; Divide to get a fraction
    fld1                  ; Load 1.0
    fadd                  ; Shift to [1.0, 2.0] range
    fstp qword [rdi]      ; Store result back

    add rdi, 8            ; Move to next array element
    loop normalize_loop

end_normalize:
    ret
