extern	___error

		section .text
		global _ft_read

_ft_read:						; rdi - fd, rsi - buffer, rdx - len
		mov rax, 0x2000003		; read syscall
		syscall
		jc err_l				; jump if carry (cf=1)
		ret

err_l:
		mov rdx, rax			; save error code to rdx
		push	rdx
		call ___error			; rax - address errno
		pop		rdx
		mov QWORD[rax], rdx		; errno - error code from rdx
		mov rax, -1
		ret