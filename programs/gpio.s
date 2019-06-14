  ldr r0, =0x20200004   @ load the address that contains GPIO pins 10-19
  mov r1, #1            @ move the value 1 into r1
  lsl r1, #18           @ shift 1 to the left 18 times to get a 1 at bit 18 (first bit of pin 16)
  str r1, [r0]          @ store the value in r1 into the address stored at r0
  ldr r0, =0x20200028   @ load the address that controls clearing GPIO pins
  mov r1, #1            @ move the value 1 into r1
  lsl r1, #16           @ shift 1 to the left 16 times to get a 1 at bit 16
  str r1, [r0]          @ store the value in r1 into the address stored at r0
LED_loop:
  mov r2, #1            @ move 1 into r2 (needed for delay1_loop)
  lsl r2, #22           @ shift 1 to the left 22 times to get a very large number for the loop
  ldr r0, =0x2020001C   @ load the address that controls setting the GPIO pins
  str r1, [r0]          @ store the value in r1 into the address stored at r0
  b delay1_loop         @ delay to keep the LED on
end1_loop:
  mov r2, #1            @ move 1 into r2 (needed for delay2_loop)
  lsl r2, #22           @ shift 1 to the left 22 times to get a very large number for the loop
  ldr r0, =0x20200028   @ load the address that controls clearing GPIO pins
  str r1, [r0]          @ store the value in r1 into the address stored at r0
  b delay2_loop         @ delay to keep the LED off
end2_loop:
  b LED_loop            @ loop through LED switching on and off forever

delay1_loop:
  sub r2, r2, #1        @ decrement r2 by 1
  cmp r2, #0            @ compare value in r2 and 0
  ble end1_loop         @ if r2 <= 0, branch to end1_loop
  b delay1_loop         @ otherwise loop through delay1_loop again

delay2_loop:
  sub r2, r2, #1        @ decrement r2 by 1
  cmp r2, #0            @ compare value in r2 and 0
  ble end2_loop         @ if r2 <= 0, branch to end2_loop
  b delay2_loop         @ otherwise loop through delay2_loop again
