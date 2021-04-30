; Avery Hewett
; 4/29/2021
; Describe the problem being solved.
; 
; Describe your algorithm/pseudocode/methodology
; 

INCLUDE Irvine32.inc

.data
    prompt BYTE         "Enter a positive Arabic Numeral (0 to quit): ", 0
    resultprompt BYTE   "Your Arabic Numeral in Roman Numeral form is: ", 0
    errorprompt BYTE    "Values below 0 are not permitted, please try again.", 0

    Roman_m BYTE "M", 0 
    Roman_cm BYTE "CM", 0
    Roman_d BYTE "D", 0
    Roman_cd BYTE "CD", 0
    Roman_c BYTE "C", 0
    Roman_xc BYTE "XC", 0
    Roman_l BYTE "L", 0
    Roman_xl BYTE "XL", 0
    Roman_x BYTE "X", 0
    Roman_ix BYTE "IX", 0
    Roman_v BYTE "V", 0
    Roman_iv BYTE "IV", 0
    Roman_i BYTE "I", 0

    intNum DWORD ?

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

    read:
        mov edx, OFFSET prompt
        call WriteString

        call ReadInt
        jge goodInput

        mov edx, OFFSET errorprompt
        call WriteString
        call Crlf
        call Crlf

        jmp read

    goodInput:
        mov intNum, eax

        cmp intNum, 00
        je exitCode

        mov edx, OFFSET resultprompt
        call WriteString

    m: 
        cmp intNum, 1000
        jl cm

        mov edx, OFFSET Roman_m
        call WriteString
        
        sub intNum, 1000
        jmp m

    cm: 
        cmp intNum, 900
        jl d

        mov edx, OFFSET Roman_cm
        call WriteString
        
        sub intNum, 900
        jmp cm

    d: 
        cmp intNum, 500
        jl cd

        mov edx, OFFSET Roman_d
        call WriteString
        
        sub intNum, 500
        jmp d


    cd: 
        cmp intNum, 400
        jl cc

        mov edx, OFFSET Roman_cd
        call WriteString
        
        sub intNum, 400
        jmp cd

    cc: 
        cmp intNum, 100
        jl xc

        mov edx, OFFSET Roman_c
        call WriteString
        
        sub intNum, 100
        jmp cc

    xc: 
        cmp intNum, 90
        jl l

        mov edx, OFFSET Roman_xc
        call WriteString
        
        sub intNum, 90
        jmp xc

    l: 
        cmp intNum, 50
        jl xl

        mov edx, OFFSET Roman_l
        call WriteString
        
        sub intNum, 50
        jmp l

    xl: 
        cmp intNum, 40
        jl x

        mov edx, OFFSET Roman_xl
        call WriteString
        
        sub intNum, 40
        jmp xl

    x: 
        cmp intNum, 10
        jl ix

        mov edx, OFFSET Roman_x
        call WriteString
        
        sub intNum, 10
        jmp x

    ix: 
        cmp intNum, 9
        jl v

        mov edx, OFFSET Roman_ix
        call WriteString
        
        sub intNum, 9
        jmp ix

    v: 
        cmp intNum, 5
        jl iv

        mov edx, OFFSET Roman_v
        call WriteString
        
        sub intNum, 5
        jmp xc

    iv: 
        cmp intNum, 4
        jl i

        mov edx, OFFSET Roman_iv
        call WriteString
        
        sub intNum, 4
        jmp xc

    i: 
        cmp intNum, 00
        je done

        mov edx, OFFSET Roman_i
        call WriteString
        
        sub intNum, 1
        jmp xc

    done: 
        call Crlf
        call Crlf
        call read 

    exitCode:
        call Crlf

    exit
main ENDP

END main
