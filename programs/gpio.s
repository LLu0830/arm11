@ .section .init

  ldr r0, =0x20200004   @ load the address that contains GPIO pins 10-19
  mov r1, #1            @ move the value 1 into r1
  lsl r1, #18           @ shift 1 to the left 18 times to get a 1 at bit 18 (first bit of pin 16)
  str r1, [r0]          @ store the value in r1 into the address stored at r0
LED_loop:
  ldr r0, =0x20200028   @ load the address that controls clearing GPIO pins
  mov r1, #1            @ move the value 1 into r1
  lsl r1, #16           @ shift 1 to the left 16 times to get a 1 at bit 16
  str r1, [r0]          @ store the value in r1 into the address stored at r0
  ldr r0, =0x2020001C   @ load the address that controls setting the GPIO pins
  str r1, [r0]          @ store the value in r1 into the address stored at r0
  b LED_loop
