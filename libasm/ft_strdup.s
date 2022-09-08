section	.text
		extern	_malloc
		extern	_ft_strlen
		extern	_ft_strcpy
		extern	___error		
		global	_ft_strdup

_ft_strdup:					; s1 - rdi
		push	rdi			; save rdi
		call	_ft_strlen
		inc		rax
		mov		rdi, rax
		call	_malloc
		pop		rsi
		cmp		rax, 0
		je		err_l			; jump if malloc == 0
		mov		rdi, rax
		call	_ft_strcpy
err_l:
		ret

