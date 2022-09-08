		global	_ft_strcpy
		section	.text
_ft_strcpy:							; rdi - dst, rsi - src
		mov		rax, rdi
		mov		rcx, 0
		jmp		copy_l

inc_l:
		inc		rcx					; rcx++

copy_l:
		mov		dl, BYTE[rsi + rcx]	;rdx - dl(7..0 bit)
		mov		BYTE[rdi + rcx], dl
		cmp		BYTE[rsi + rcx], 0
		jne		inc_l				; jmp in inc_l if ZF = 0

ret_l:
		ret							; return rax - dst