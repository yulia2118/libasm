section .text
    global _ft_strcmp

_ft_strcmp:
	mov		r9, 0
	mov		rax, 0
	mov		rbx, 0

loop:
	mov		al, byte[rdi + r9] ;переносим в al(8 bit rax) первый аргумент rdi (s1)
	mov		bl, byte[rsi + r9] ;переносим в bl(8 bit rbx) второй аргумент rsi (s2)
	cmp		byte[rdi + r9], 0 ;сравниваем с 0 пока одна строка не закончится (s1)
	je		_exit
	cmp		byte[rsi + r9], 0 ;сравниваем с 0 пока одна строка не закончится (s2)
	je		_exit
	cmp		rax, rbx ;сравниваем s1 и s2
	jne		_exit ;если они не равны - exit
	inc		r9 ;r9++
	jmp		loop
_exit:
	sub		rax, rbx ;разница (s1 - s2)
	ret
