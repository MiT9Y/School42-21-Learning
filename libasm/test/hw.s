;/opt/local/bin/nasm -f macho64 hw.s
;ld -e start -macosx_version_min 10.7.0 -lSystem  hw.o -o hw
;/opt/local/bin/nasm -f macho64 hw.s && ld -e start -macosx_version_min 10.7.0 -lSystem  hw.o -o hw && ./hw

global start

section .text
start:
  mov rax, 0x2000004 ; write
  mov rdi, 1 ; stdout
  mov rsi, msg
  mov rdx, msg.len
  syscall
  mov rax, 0x2000001 ; exit
  mov rdi, rdi ;
  syscall

section .data
msg:    db      "Hello, world!!!", 10
.len:   equ     $ - msg