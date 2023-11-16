section .data
    hello db 'Hello, Holberton', 0xA ; The string to print, 0xA is the newline character

section .text
    global main
    extern printf

main:
    ; Prepare the arguments for printf
    mov rdi, hello ; The format string
    xor rax, rax   ; The number of vector registers used for arguments - in this case, zero

    ; Call the printf function
    call printf

    ; Return 0 to the operating system
    mov eax, 0x60 ; The syscall number for exit
    xor edi, edi ; The exit status code
    syscall
