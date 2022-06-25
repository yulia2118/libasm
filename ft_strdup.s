section .text
    global _ft_strdup
    extern _ft_strlen
    extern _ft_strcpy
    extern _malloc

_ft_strdup:
	mov		rax, 0
	push	rdi ;кладем в стек s1
	call	_ft_strlen ;считаем символы - значение вернется в rax
	mov		rdi, rax ;значение rax (длина строки ret strlen) кладем в rdi.
	inc		rdi ;увеличиваем rdi на один символ для конца строки
	call	_malloc ;маллок примет нужное кол-во символов rdi
	cmp		rax, 0 ;в rax - ret malloc
	je		_err ;если маллок возвращает 0, выходим
	mov		rdi, rax ;в rdi (s1) для strcpy кладем то, что вернул malloc
	pop		rsi ; в rsi (s2) для strcpy кладем второй аргумент из стека (аргумент s1 strdup)
	call	_ft_strcpy

_err:
	ret
