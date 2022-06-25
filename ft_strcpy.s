section .text
    global _ft_strcpy

_ft_strcpy:
	mov		r8, 0

loop:
	mov		r9b, byte[rsi + r8] ;rsi - s2(src) переносим байт из второго аргумента
	mov		byte[rdi + r8], r9b ;rdi - s1(dst) в первый
	cmp		byte[rsi + r8], 0 ;сравниваем, что этот байт не '\0'
	je		_exit ;если 0, то выходим
	inc		r8 ;если не 0, r8++
	jmp		loop

_exit:
	mov		rax, rdi ;перемещаем rdi(s1) в rax - возвращаемое значение
	ret
