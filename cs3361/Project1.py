def main():
    global output
    global outputrun
    while True:
        output = '('
        outputrun = 0
        filename = input('Enter the file name (Enter "stop" to close the program): ')
        if filename == 'stop':
            return 0
        try:
            docu = open(filename).read().replace('\n', ' ')
            if docu == '':
                print('error: end of file\n')
            docu=docu.rstrip()
            parse(docu)
    
            output += ')\n'
            print(output)
        except IOError:
            print('error: file does not exist\n')
            

def parse(line):
    passed = -1
    for char in range(len(line)):
        if char < passed:
            pass
        elif char == len(line):
            pass
        elif line[char] == ' ':
            pass
        elif line[char].isalpha():
            passed = token(line, char, 's')
        elif line[char].isdigit() == True or line[char] == '.':
            passed = token(line, char, 'd')
        elif line[char] == '(':
            finaloutput('lparen', 'x')
        elif line[char] == ')':
            finaloutput('rparen', 'x')
        elif line[char] == '+':
            finaloutput('plus', 'x')
        elif line[char] == '-':
            finaloutput('minus', 'x')
        elif line[char] == '*':
            finaloutput('times', 'x')
        elif line[char] == '/':
            passed = token(line, char, 'c')
        elif line[char] == ':' and line[char+1] == '=':
            finaloutput('assign', 'x')
            
        
def token(line, pos, ty):
    word = ''
    if ty == 's':
        for char in range(len(line)):
            if char >= pos:
                if line[char].isalpha() == True or line[char].isdigit() == True:
                    word += line[char]
                elif line[char].isalpha() == False:
                    break
        finaloutput(word, 's')
        return char
    elif ty == 'd':
        for char in range(len(line)):
            if char >= pos:
                if line[char].isdigit() == True or line[char] == '.':
                    word += line[char]
                elif line[char].isdigit() == False:
                    break
        finaloutput(word, 'd')
        return char
    elif ty == 'c':
        for char in range(len(line)):
            if char >= pos:
                if line[char] == '/' and char+1 == len(line):
                    pass
                elif line[char] == '/' and line[char+1] == '/':
                    return len(line)
                elif line[char] == '/' and line[char+1] == '*':
                    for char in range(len(line)):
                        if char >= pos:
                            if line[char] == '*' and line[char+1] == '/':
                                break
                elif line[char] == '/':
                    finaloutput('div', 'x')
                break
        return char+1
    
def finaloutput(data, ty):
    global output
    global outputrun
    if outputrun != 0:
        output += ', '
    if ty == 's':
        if data.lower() == 'read':
            output += 'read'
        elif data.lower() == 'write': 
            output += 'write'
        else:
            output += 'id'
    elif ty == 'd':
        output += 'number'
    elif ty == 'x':
        output += data
    outputrun += 1


main()
