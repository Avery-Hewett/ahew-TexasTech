; Avery Hewett
; 4/23/21
; Describe the problem being solved.
; Take user input
; Take key input
; xor them to get a new string
; Print string
; Describe your algorithm/pseudocode/methodology
; Get user input for user and key
; Repeat the string for the size of input
; xor the values and print new string

INCLUDE Irvine32.inc

.data
    stringprompt BYTE "Enter Message: ", 0
    keyprompt BYTE    "Enter Key:     ", 0
    resultprompt BYTE "Result:        ", 0

    bufsize dword ?
    keymax = 20
    stringmax = 500
    keybuffer BYTE 500 DUP(0)
    backup BYTE SIZEOF keybuffer DUP (?)
    buffer BYTE stringmax + 1 DUP(0)
    myName BYTE "Avery Hewett",0
    myId BYTE "R11643886",0
 
.code
main PROC 
    
    mov edx, offset myName
	call writestring
	call Crlf

	mov edx, offset myId
	call writestring
	call Crlf

    call Userinput
    call keyinput
    call strrep
    mov ecx, bufSize
    mov esi, 0
    L1:
        movzx ax, buffer[esi]
        movzx bx, keybuffer[esi]
        xor ax, bx 
        mov buffer[esi], al
        inc esi
        loop L1

    call crlf
    mov edx, offset resultprompt
    call writestring
    mov edx, offset buffer
    call writestring
    call crlf
    exit
main ENDP

userinput proc
    pushad
    mov edx, OFFSET stringprompt 
    call WriteString
    mov ecx, stringMAX
    mov edx, OFFSET buffer
    call ReadString
    mov bufsize, eax 
    popad
    ret
userinput ENDP

keyinput proc
    pushad 
    mov edx, OFFSET keyprompt 
    call WriteString
    mov ecx, keyMAX 
    mov edx, OFFSET keybuffer 
    call ReadString 
    popad
    ret
keyinput ENDP

strrep PROC
    pushad 
    mov esi, OFFSET keybuffer
    mov edi, OFFSET keybuffer

    iNVOKE Str_copy,
        ADDR keybuffer,
        ADDR backup

    push edi
    mov ecx, bufsize
    outloop: 
        push ecx
        call StrLength
        mov ecx, eax
        mov esi, OFFSET backup
        inloop:
            mov al, [esi]
            mov [edi], al
            inc esi
            inc edi
            loop inloop
        pop ecx
        loop outloop
    pop edi
    popad
    ret
strrep endp

END main