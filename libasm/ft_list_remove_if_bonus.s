section	.text
		extern	_free
		global	_ft_list_remove_if

free_cur_el:
		mov		r10, [r9 + 8]			; r10 - cur_el.next
		cmp		r8, 0
		je		first_el_chk			; if (*priv_el == 0)
		mov		[r8 + 8], r10
		jmp		free_cur_el_next

first_el_chk:
		mov		[rdi], r10

free_cur_el_next:
		push	rdi
		push	rsi
		push	rdx
		push	rcx
		push	r8
		push	r10
		push	r9
		mov		rdi, [r9]
		call	rcx
		pop		r9
		push	r9
		push	rsp
		mov		rdi, r9
		call	_free
		pop		rsp
		pop		r9
		pop		r10
		pop		r8
		pop		rcx
		pop		rdx
		pop		rsi
		pop		rdi
		mov		r9, r10
		ret

_ft_list_remove_if:						; rdi - **begin, rsi - *data_ref
										; rdx - *cmp, rcx - *free_fct
		cmp		rdi, 0
		je		ft_list_remove_if_ret
		cmp		rsi, 0
		je		ft_list_remove_if_ret
		cmp		rdx, 0
		je		ft_list_remove_if_ret
		cmp		rcx, 0
		je		ft_list_remove_if_ret
		mov		r9, [rdi]				; r9 - *begin
		mov		r8, 0

ft_list_remove_if_next_el:
		cmp		r9, 0
		je		ft_list_remove_if_ret	; if (cur_el.next == 0)
		push	rdi
		push	rsi
		push	rdx
		push	rcx
		push	r8
		push	r9
		mov		rdi, [r9]				; rdi - cur_el.data, rsi - data_ref
		call	rdx						; run cmp
		pop		r9
		pop		r8
		pop		rcx
		pop		rdx
		pop		rsi
		pop		rdi
		cmp		rax, 0
		jne		jmp_to_next				; if (cmp_res != 0)
		call	free_cur_el				; r8 - prev, r9 - cur
		jmp		ft_list_remove_if_next_el

jmp_to_next:
		mov		r8, r9
		mov		r9, [r9 + 8]
		jmp		ft_list_remove_if_next_el
		
ft_list_remove_if_ret:
		ret