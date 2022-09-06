#include "FreeRTOSConfig.h"

.macro portSAVE_CONTEXT
    mov.l r0,  @-r15
    mov.l r1,  @-r15
    mov.l r2,  @-r15
    mov.l r3,  @-r15
    mov.l r4,  @-r15
    mov.l r5,  @-r15
    mov.l r6,  @-r15
    mov.l r7,  @-r15
    mov.l r8,  @-r15
    mov.l r9,  @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
    mov.l r14, @-r15

    sts.l pr,   @-r15
    sts.l macl, @-r15
    sts.l mach, @-r15
    stc.l gbr,  @-r15

    mov.l _pxCurrentTCB_k, r0
    mov.l @r0, r0
    mov.l r15, @r0
.endm

.macro portRESTORE_CONTEXT
    mov.l _pxCurrentTCB_k, r0 /* Address of the _pxCurrentTCB */
    mov.l @r0, r0             /* Value of _pxCurrentTCB, a.k.a. address of the current TCB */
    mov.l @r0, r15            /* currentTCB[0], pxTopOfStack */

    ldc.l @r15+,  gbr
    lds.l @r15+,  mach
    lds.l @r15+,  macl
    lds.l @r15+,  pr

    mov.l @r15+, r14
    mov.l @r15+, r13
    mov.l @r15+, r12
    mov.l @r15+, r11
    mov.l @r15+, r10
    mov.l @r15+,  r9
    mov.l @r15+,  r8
    mov.l @r15+,  r7
    mov.l @r15+,  r6
    mov.l @r15+,  r5
    mov.l @r15+,  r4
    mov.l @r15+,  r3
    mov.l @r15+,  r2
    mov.l @r15+,  r1
    mov.l @r15+,  r0

    rte
    nop
.endm

_vPortYieldHandler:
    portSAVE_CONTEXT

	mov.l	_vTaskSwitchContext_k, r0
	jsr		@r0
	nop

    portRESTORE_CONTEXT



/* Local data */
.align 4
_pxCurrentTCB_k:
    .long _pxCurrentTCB
_vTaskSwitchContext_k:
    .long _vTaskSwitchContext
_xTaskIncrementTick_k:
    .long _xTaskIncrementTick