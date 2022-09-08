section	.text
		global	_ft_list_size

_ft_list_size:							; rdi - *begin
		mov		rax, 0
		mov		r8, rdi
		jmp		ft_list_size_start

ft_list_size_inc_rax:
		inc		rax

ft_list_size_start:
		cmp		r8, 0
		je		ft_list_size_ret
		mov		r8, [r8 + 8]			; r8 = el.next
		jmp		ft_list_size_inc_rax

ft_list_size_ret:
		ret