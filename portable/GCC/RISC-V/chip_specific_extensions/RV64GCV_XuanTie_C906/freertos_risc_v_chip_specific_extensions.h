/*
 * FreeRTOS Kernel V11.0.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/*
 * The FreeRTOS kernel's RISC-V port is split between the the code that is
 * common across all currently supported RISC-V chips (implementations of the
 * RISC-V ISA), and code that tailors the port to a specific RISC-V chip:
 *
 * + FreeRTOS\Source\portable\GCC\RISC-V-RV32\portASM.S contains the code that
 *   is common to all currently supported RISC-V chips.  There is only one
 *   portASM.S file because the same file is built for all RISC-V target chips.
 *
 * + Header files called freertos_risc_v_chip_specific_extensions.h contain the
 *   code that tailors the FreeRTOS kernel's RISC-V port to a specific RISC-V
 *   chip.  There are multiple freertos_risc_v_chip_specific_extensions.h files
 *   as there are multiple RISC-V chip implementations.
 *
 * !!!NOTE!!!
 * TAKE CARE TO INCLUDE THE CORRECT freertos_risc_v_chip_specific_extensions.h
 * HEADER FILE FOR THE CHIP IN USE.  This is done using the assembler's (not the
 * compiler's!) include path.  For example, if the chip in use includes a core
 * local interrupter (CLINT) and does not include any chip specific register
 * extensions then add the path below to the assembler's include path:
 * FreeRTOS\Source\portable\GCC\RISC-V-RV32\chip_specific_extensions\RV32I_CLINT_no_extensions
 *
 */


#ifndef __FREERTOS_RISC_V_EXTENSIONS_H__
#define __FREERTOS_RISC_V_EXTENSIONS_H__

#define portasmHAS_SIFIVE_CLINT           1
#define portasmHAS_MTIME                  0
#define portasmADDITIONAL_CONTEXT_SIZE    32 /* Must be even number on 32-bit cores. */
#define portasmRV64_CLINT_32B             1

.macro portasmSAVE_ADDITIONAL_REGISTERS
addi sp, sp, -( portasmADDITIONAL_CONTEXT_SIZE * portWORD_SIZE )
fsd f31,  1 * portWORD_SIZE( sp )
fsd f30,  2 * portWORD_SIZE( sp )
fsd f29,  3 * portWORD_SIZE( sp )
fsd f28,  4 * portWORD_SIZE( sp )
fsd f27,  5 * portWORD_SIZE( sp )
fsd f26,  6 * portWORD_SIZE( sp )
fsd f25,  7 * portWORD_SIZE( sp )
fsd f24,  8 * portWORD_SIZE( sp )
fsd f23,  9 * portWORD_SIZE( sp )
fsd f22, 10 * portWORD_SIZE( sp )
fsd f21, 11 * portWORD_SIZE( sp )
fsd f20, 12 * portWORD_SIZE( sp )
fsd f19, 13 * portWORD_SIZE( sp )
fsd f18, 14 * portWORD_SIZE( sp )
fsd f17, 15 * portWORD_SIZE( sp )
fsd f16, 16 * portWORD_SIZE( sp )
fsd f15, 17 * portWORD_SIZE( sp )
fsd f14, 18 * portWORD_SIZE( sp )
fsd f13, 19 * portWORD_SIZE( sp )
fsd f12, 20 * portWORD_SIZE( sp )
fsd f11, 21 * portWORD_SIZE( sp )
fsd f10, 22 * portWORD_SIZE( sp )
fsd  f9, 23 * portWORD_SIZE( sp )
fsd  f8, 24 * portWORD_SIZE( sp )
fsd  f7, 25 * portWORD_SIZE( sp )
fsd  f6, 26 * portWORD_SIZE( sp )
fsd  f5, 27 * portWORD_SIZE( sp )
fsd  f4, 28 * portWORD_SIZE( sp )
fsd  f3, 29 * portWORD_SIZE( sp )
fsd  f2, 30 * portWORD_SIZE( sp )
fsd  f1, 31 * portWORD_SIZE( sp )
fsd  f0, 32 * portWORD_SIZE( sp )
   .endm

   .macro portasmRESTORE_ADDITIONAL_REGISTERS
fld f31,  1 * portWORD_SIZE( sp )
fld f30,  2 * portWORD_SIZE( sp )
fld f29,  3 * portWORD_SIZE( sp )
fld f28,  4 * portWORD_SIZE( sp )
fld f27,  5 * portWORD_SIZE( sp )
fld f26,  6 * portWORD_SIZE( sp )
fld f25,  7 * portWORD_SIZE( sp )
fld f24,  8 * portWORD_SIZE( sp )
fld f23,  9 * portWORD_SIZE( sp )
fld f22, 10 * portWORD_SIZE( sp )
fld f21, 11 * portWORD_SIZE( sp )
fld f20, 12 * portWORD_SIZE( sp )
fld f19, 13 * portWORD_SIZE( sp )
fld f18, 14 * portWORD_SIZE( sp )
fld f17, 15 * portWORD_SIZE( sp )
fld f16, 16 * portWORD_SIZE( sp )
fld f15, 17 * portWORD_SIZE( sp )
fld f14, 18 * portWORD_SIZE( sp )
fld f13, 19 * portWORD_SIZE( sp )
fld f12, 20 * portWORD_SIZE( sp )
fld f11, 21 * portWORD_SIZE( sp )
fld f10, 22 * portWORD_SIZE( sp )
fld  f9, 23 * portWORD_SIZE( sp )
fld  f8, 24 * portWORD_SIZE( sp )
fld  f7, 25 * portWORD_SIZE( sp )
fld  f6, 26 * portWORD_SIZE( sp )
fld  f5, 27 * portWORD_SIZE( sp )
fld  f4, 28 * portWORD_SIZE( sp )
fld  f3, 29 * portWORD_SIZE( sp )
fld  f2, 30 * portWORD_SIZE( sp )
fld  f1, 31 * portWORD_SIZE( sp )
fld  f0, 32 * portWORD_SIZE( sp )
addi sp, sp, ( portasmADDITIONAL_CONTEXT_SIZE * portWORD_SIZE )
   .endm

#endif /* __FREERTOS_RISC_V_EXTENSIONS_H__ */
