global _start

section .text
_start:
  xor rax, rax  ; zero out rax - the accumulator
  xor rcx, rcx  ; zero out rcx - the counter

loop:
  inc rcx       ; increment the counter
  add rax, rcx  ; add the counter to the accumulator
  cmp rcx, [n]    ; rcx == n?
  jne loop      ; if no, jump to loop

  mov rdi, rax  ; the result can be the exit status, quicker than converting the result to string and then printing it
  mov rax, 60
  syscall       ; exit syscall

section .data
  n dw 20       ; define n = 20
