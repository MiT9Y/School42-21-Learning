section	.text
		global	_ft_list_sort

found_and_swap:							; r11 - current element
		mov		r11, r9

found_and_swap_next_el:
		mov		r11, [r11 + 8]
		cmp		r11, 0
		je		found_and_swap_ret		; if (cur_el.next == 0)

		push	rdi
		push	rsi
		push	r9
		push	r11
		mov		rax, rsi				; rax - *cmp
		mov		rdi, [r9]				; rdi - cur_main_el.data
		mov		rsi, [r11]				; rsi - cur_el.data
		call	rax
		pop		r11
		pop		r9
		pop		rsi
		pop		rdi
		cmp		rax, 0
		jng		found_and_swap_next_el	; if (cmp_return <= 0)
		mov		r12, [r9]
		mov		r13, [r11]
		mov		[r9], r13
		mov		[r11], r12
		jmp		found_and_swap_next_el

found_and_swap_ret:
		ret

_ft_list_sort:							; rdi - **begin, rsi - int(*cmp)(void*, void*)
		push	rsp				; save stack pointer
		push	rdi				; save begin
		push	rsi				; save data
		cmp		rdi, 0							
		je		ft_list_sort_ret
		cmp		rsi, 0
		je		ft_list_sort_ret
		mov		r9, [rdi]				; r9 - *begin
		cmp		r9, 0
		je		ft_list_sort_ret
		call	found_and_swap			; r8 - previous element, r9 - current element

ft_list_sort_next_el:
		cmp		QWORD[r9 + 8], 0
		je		ft_list_sort_ret		; if (cur_el.next == 0)
		mov		r9, [r9 + 8]
		call	found_and_swap			; r9
		jmp		ft_list_sort_next_el

ft_list_sort_ret:
		pop		rsi
		pop		rdi
		pop		rsp
		ret