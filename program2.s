.section .data
    format_string: .asciz "Czas wykonania: %d cykli procesora\n"  # Format dla printf

.section .text
    .global main
    .extern funkcja
    .extern printf
    .extern clock

main:
    pushl %ebp
    movl %esp, %ebp

    call clock
    movl %eax, %edi
    call funkcja    # Wywołanie funkcji quick_sort
    call clock
    subl %edi, %eax
    pushl %eax
    pushl $format_string
    call printf
    addl $8, %esp

    movl $0, %eax
    leave
    ret

