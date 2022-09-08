section .text
		global _ft_atoi_base

; --- chk_space_symbol begin ---
chk_space_symbol:
		mov		r13b, 0
		cmp		BYTE [rsi + r8], 32	; base[base_length] == ' '
		je		err_ret_func
		cmp		BYTE [rsi + r8], 9	; base[base_length] == '\t'
		je		err_ret_func
		cmp		BYTE [rsi + r8], 10	; base[base_length] == '\n'
		je		err_ret_func
		cmp		BYTE [rsi + r8], 13	; base[base_length] == '\r'
		je		err_ret_func
		cmp		BYTE [rsi + r8], 11	; base[base_length] == '\v'
		je		err_ret_func
		cmp		BYTE [rsi + r8], 12	; base[base_length] == '\f'
		je		err_ret_func
		jmp		ret_func
; --- chk_space_symbol end ---

; --- chk_sign_symbol begin ---
chk_sign_symbol:
		mov		r13b, 0
		cmp		BYTE [rsi + r8], 43	; base[base_length] == '+'
		je		err_ret_func
		cmp		BYTE [rsi + r8], 45	; base[base_length] == '-'
		je		err_ret_func
		jmp		ret_func		
; --- chk_sign_symbol end ---

; --- chk_err_symbol begin ---
chk_err_symbol:
		mov		r13b, 0
		call	chk_space_symbol
		cmp		r13b, 1
		je		err_ret_func
		call	chk_sign_symbol
		cmp		r13b, 1
		je		err_ret_func
		jmp		ret_func
; --- chk_err_symbol end ---

; --- chk_double_symbol begin ---
chk_double_symbol:
		mov		r9, r8
		mov		r13b, 0

chk_double_symbol_r9_inc:
		inc		r9

		mov		r10b, BYTE[rsi + r9]
		cmp		r10b, 0
		je		ret_func
		cmp		BYTE[rsi + r8], r10b
		je		err_ret_func
		jmp		chk_double_symbol_r9_inc
; --- chk_double_symbol end ---

; --- chk_base begin ---
chk_base:
		mov		r8, 0
		mov		r13b, 0
		jmp		chk_base_start

chk_base_r8_inc:
		inc		r8

chk_base_start:
		cmp		BYTE[rsi + r8], 0
		je		ret_func
		call	chk_err_symbol
		cmp		r13b, 1
		je		err_ret_func
		call	chk_double_symbol
		cmp		r13b, 1
		je		err_ret_func
		jmp		chk_base_r8_inc
; --- chk_base end ---

; --- skip_space begin ---
skip_space_r8_inc:
		inc		r8

skip_space:
		mov		r13b, 0
		call	chk_space_symbol;
		cmp		r13b, 1
		je		skip_space_r8_inc
		jmp		ret_func
; --- skip_space end ---

; --- set_sign begin ---
set_sign_r8_inc:
		inc		r8
		jmp		set_sign_plus

set_sign:
		mov		r15b, 0
		cmp		BYTE[rsi + r8], 45
		jne		set_sign_plus
		mov		r15b, 1

set_sign_plus:
		mov		r13b, 0
		call	chk_sign_symbol;
		cmp		r13b, 1
		je		set_sign_r8_inc
		jmp		ret_func
; --- set_sign end ---

; --- ALL FUNC RETURN ---
err_ret_func:
		mov		r13b, 1

ret_func:		
		ret
; --- ALL FUNC RETURN ---

; --- get_pos begin ---
get_pos:
		mov		r10, 0

get_pos_cycle:		
		mov		r11b, BYTE[rsi + r10]
		cmp		BYTE[rdi + r8], r11b
		je		ret_func
		cmp		r9, r10
		je		ret_func
		inc		r10
		jmp		get_pos_cycle
; --- get_pos begin ---

; --- convertion begin ---
convertion_r8_inc:
		inc		r8

convertion:
		call	get_pos				; r10 - index in base
		cmp		r10, r9
		je		ret_func
		mul		r9
		add		rax, r10
		jmp		convertion_r8_inc
; --- convertion end ---

_ft_atoi_base:						; rdi - *str, rsi - *base
		mov		rax, 0
		call	chk_base
		cmp		r13b, 1
		je		_ft_atoi_base_ret
		mov		r9, r8
		mov		r8, 0
		push	rsi
		mov		rsi, rdi
		call	skip_space
		call	set_sign			; sign - r15b (0: '+', 1: '-')
		pop		rsi
		cmp		r9, 1				; len base <= 1
		jle		_ft_atoi_base_ret
		call	convertion
		cmp		r15b, 0
		je		_ft_atoi_base_ret
		neg		rax

_ft_atoi_base_ret:
		ret