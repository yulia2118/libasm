section .text
    global _ft_write
    extern ___error

_ft_write:
	mov		rax, 0x02000004 ;в rax кладем системный вызов
	syscall ;исполняем
	jc      _err ;если ошибка, переходим в _err
	ret

_err:
	push	rax ;запоминаем значение rax - errno (result of syscall)
	call	___error ;вызываем функцию ___error, которая вернет в rax адрес errno
	pop		r9 ;в r9 кладем переменную из стека
	mov		[rax], r9 ;разыменовываем адрес переменной errno и записываем значение из r9
	mov		rax, -1 ;в errno положили нужное значение, аккумулятор возвращает -1 (ошибка)
	ret
