global _start

section .text
_start:
    ; syscall de escrita (sys_write)
    mov rax, 1                  ; ID da syscall para sys_write
    mov rdi, 1                  ; Descritor de arquivo: 1 é stdout (saída padrão)
    mov rsi, message            ; Endereço de memória da string
    mov rdx, 13                 ; Comprimento da string em bytes
    syscall                     ; Invoca o sistema operacional

    ; syscall de saída (sys_exit)
    mov rax, 60                 ; ID da syscall para sys_exit
    xor rdi, rdi                ; Código de retorno 0 (sucesso)
    syscall                     ; Invoca o sistema operacional

section .data
    message: db "Hello, World!", 10  ; 10 é o caractere de nova linha (\n)