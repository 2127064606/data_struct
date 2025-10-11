data segment
    msg db 'Hello, world!$'
ends

stack segment
    dw 128 dup(0)
ends

code segment
    start:
        mov ax, data
        mov ds, ax
        mov es, ax
        mov ss, ax
        mov sp, 128
        mov ah, 09h
        lea dx, msg
        int 21h
        mov ah, 4ch
        int 21h
ends
end start
