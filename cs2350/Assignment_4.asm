; NAME Avery Hewett
; DATE 4/16/21
; Assignment #4

; Describe the problem being solved.
; Change Strings with various procedures 
; Combine two strings 
; Repeat a string x times 
; Change string to lowercase
; Change string to uppercase

; Describe your algorithm/pseudocode/methodology
; For combination, I looped through both input and hardcode to add it to newString
; For repetition, I loop through eax for times and nest a loop that places the string into itself over and over using the size of a copied string
; For lower, I used the irvine library and modified it to allow lower case
; For upper, I copied the irvine library and made minor edits to it 

INCLUDE Irvine32.inc


.data
	textString BYTE "You entered the string: "
	inputString BYTE 50 DUP(0)
	hardcodeString BYTE " for CS2350. ", 0
	newString BYTE 500 DUP(0)
	
	prompt BYTE "Enter a string to manipulate: ",0
	msg1 BYTE "Post Concatenation: ",0
	msg2 BYTE "Post Repetition:    ",0
	msg3 BYTE "Post Lowercase:     ",0
	msg4 BYTE "Post Uppercase:     ",0
	
	; Place your additional memory operands below (if any)
	myName BYTE "Avery Hewett",0
    myId BYTE "R11643886",0
	backup BYTE SIZEOF newString DUP (?)

.code
main PROC																; DO NOT CHANGE THE CODE WITHIN THE MAIN PROCEDURE.
	; Prompt the user for string input (50 character maximum)
	mov edx, OFFSET prompt
	call WriteString

	; Read in the user's response
	mov edx, OFFSET inputString
	mov ecx, SIZEOF inputString
	call ReadString

	; Print the user's response to the screen.
	mov edx, OFFSET textString
	call WriteString
	call Crlf			; Print end line character.
	
	; -------------------------------------------------------------
	; Code block for calling strcat and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET inputString
	mov edx, OFFSET hardcodeString
	call strcat
	mov edx, OFFSET msg1
	call WriteString	; Print msg1
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	; -------------------------------------------------------------
	; Code block for calling strrep and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET newString
	mov eax, 3
	call strrep
	mov edx, OFFSET msg2
	call WriteString	; Print msg2
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	; -------------------------------------------------------------
	; Code block for calling strlower and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET newString
	call strlower
	mov edx, OFFSET msg3
	call WriteString	; Print msg3
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	; -------------------------------------------------------------
	; Code block for calling strlower and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET newString
	call strupper
	mov edx, OFFSET msg4
	call WriteString	; Print msg4
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------

	exit
main ENDP

strcat PROC
	push edx
	mov edx, offset myName
	call writestring
	call Crlf

	mov edx, offset myId
	call writestring
	call Crlf

	pop edx
	push edi
    mov ecx, eax
    L1: 
		mov al, [esi]
        mov [edi], al
        inc esi
        inc edi
        loop L1
    mov ecx, SIZEOF hardcodeString
    L2: 
		mov al, [edx]
        mov [edi], al
        inc edx
        inc edi
        loop L2
    pop edi
    ret
strcat ENDP

strrep PROC
	INVOKE Str_copy,
		ADDR newString,
		ADDR backup

    push edi
    mov ecx, eax
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
    ret
strrep ENDP

strlower PROC
	L1: 
		mov al,[esi]
		cmp al,0
		je L3
		cmp al,'A'
		jb L2
		cmp al,'Z'
		ja L2 
		or BYTE PTR [esi],00100000b
	L2:
		inc esi
		jmp L1
	L3: 
		ret
strlower ENDP

strupper PROC
	L1: 
		mov al,[esi]
		cmp al,0
		je L3
		cmp al,'a'
		jb L2
		cmp al,'z'
		ja L2 
		and BYTE PTR [esi],11011111b
	L2:
		inc esi
		jmp L1
	L3: 
		ret

strupper ENDP

END main