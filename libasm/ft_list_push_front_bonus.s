section	.text
		extern	_malloc
		global	_ft_list_push_front

_ft_list_push_front:				; rdi - t_list **begin, rsi - void *data
		push	rsp				; save stack pointer
		push	rdi				; save begin
		push	rsi				; save data
		mov		rdi, 16			; sizeof(t_list) = 16 byte
		call	_malloc			
		pop		rsi
		pop		rdi
		pop		rsp
		cmp		rax, 0
		je		ret_func		; jump if malloc == 0
		mov		[rax], rsi		; new.data = data
		mov		r8, [rdi]		; r8 = *begin
		mov		[rax + 8], r8	; new.next = *begin
		mov		[rdi], rax		; *begin = new

ret_func:
		ret

		

