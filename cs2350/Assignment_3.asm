INCLUDE Irvine32.inc

.data        ; Data segment.  Feel free to add variables before or after this block, but don't add anything in between the following 4 memory operands.
    encodedString BYTE "/vpz!offc!fdop!ebi!idjix!gp!mmb!uvc!fwjmb!offc!sfwf!ebi!idjix!gp!fopo!-utve!djnpub!fojg!gp!eovpn!b!fdvepsq!emvpx!vpz!-fnju!b!ub!npub!fop!-tsf{ffxu!iujx!usbqb!gmftsvpz!ldjq!pu!fsfx!vpz!gj!ubiu!opjupo!hojutfssb!zmuihjmt!b!tj!uJ"
    nullTerm BYTE 0                                        ; Null Terminator for encodedString. 
    decodedString BYTE SIZEOF encodedString DUP('?')    ; Storage location for the final decoded string. You MUST put the final result in this variable!
    nullTerm2 BYTE 0                                    ; Null Terminator for decodedString

    stringLength = ($ - encodedString) - 1 ;Length of the string, minus null terminator
    myName BYTE "Avery Hewett",0
    myId BYTE "R11643886",0

.code
main PROC
    ; Prints myName (My name)
    mov edx, offset myName
    call writestring
    call Crlf
    ; Print myId (R number)
    mov edx, offset myId
    call writestring
    call Crlf

    ; set up the loop to  run on per char
    mov ecx, stringLength
    mov esi, 0

    ; move the string onto the stack, one char at a time
L1: movzx ax, encodedString[esi] ; move 1 byte
    ; Subtract 1 from the ASCII value
    sub ax,1
    push ax
    inc esi
    loop L1

    ; Set up the loop to run one per character
    mov ecx, stringLength
    mov esi,  0
L2: pop ax
    mov encodedString[esi], al
    inc    esi
    loop L2

    ; Print the decodedString variable
    mov edx, OFFSET decodedString
    call Writestring
    exit

main ENDP
END main
