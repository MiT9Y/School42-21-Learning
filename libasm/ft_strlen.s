		global	_ft_strlen
		section	.text
		
_ft_strlen:
		mov		rax, 0				; rax init 0, rdi - fst_arg
		jmp		compare_l			; compare character from string

inc_l:
		inc		rax					; rax++

compare_l:
		cmp		BYTE[rdi + rax], 0	; str[i] == 0
		jne		inc_l				; jmp in inc_l if ZF = 0
		ret							; return i