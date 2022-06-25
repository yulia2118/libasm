section .text
    global _ft_strlen

_ft_strlen:
    mov     rax, 0 ;i = 0
loop:
    cmp		byte[rdi + rax], 0 ;идем посимвольно пока не встретим '\0'
    je		_exit ;если встретили, то выходим
    inc		rax ;rax++
    jmp		loop

_exit:
    ret
