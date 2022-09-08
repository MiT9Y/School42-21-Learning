		global	_ft_strcmp
		section	.text

_ft_strcmp:								; rdi - s1, rsi - s2
		mov		rax, 0
		mov		rdx, 0
		mov		rcx, 0
		jmp		cmp_l

inc_l:
		cmp		BYTE[rdi + rcx], 0
		je		ret_l
		inc		rcx

cmp_l:
		mov		al, BYTE[rdi + rcx]
		mov		dl, BYTE[rsi + rcx]
		sub		rax, rdx
		cmp		rax, 0					; if (s1[rcx] - s2[rcx]) == 0 inc rcx
		je		inc_l

ret_l:					
		ret