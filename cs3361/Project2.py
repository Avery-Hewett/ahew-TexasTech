import sys

def main():
    """ main driver
    Input:
        - argv[1] expected to be string of file location
    Output none
    Side Effect:
        - prints Parse_tree or 'error'
    """
    file_name = sys.argv[1]

    global File_queue
    global Input_token
    global Parse_tree

    File_queue = readFile( file_name )
    #while File_queue != []:
    #    print(scan())
    #'''
    Input_token = scan()
    Parse_tree = ""

    if program():
        print( Parse_tree )
    else:
        print( "error" )
    #'''

def readFile( file_name ):
    """ Converts the input file to a queue
    Input:
        - file_name: (string) name of the file to be parsed
    Output:
        - queue: (list) input file stored by char
    Side Effect: none
    """
    queue = []

    with open( file_name, 'r' ) as input_file:
        for line in input_file:
            for char in line:
                queue.append(char)

    queue.append(" ")
    return queue

def scan():
    """ tokenizes the file queue
    Input: none
    Output:
        - a tuple corresponding to the token type and token string
    Side Effect:
        - dequeues File_queue
    """
    global File_queue

    err_str = ""
    start_state = 1
    keyword_state = 16
    transition_table = [ \
        [[0, 1],[0, 1],[0, 1],[0, 2],[0,10],[0, 6],[0, 7],[0, 8],[0, 9],[0,11],[2, 1],[0,13],[0,14],[0,16]], \
        [[1, 1],[1, 1],[1, 1],[0, 3],[0, 4],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[0, 3],[0, 3],[0, 1],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3],[0, 3]], \
        [[0, 4],[0, 4],[0, 4],[0, 4],[0, 5],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4]], \
        [[0, 4],[0, 4],[0, 4],[0, 1],[0, 5],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4],[0, 4]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[0,12],[2, 1],[2, 1],[2, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1]], \
        [[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[2, 1],[0,15],[2, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[0,15],[0,14],[1, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[0,15],[1, 1]], \
        [[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[1, 1],[0,16],[0,16]]]
    token_table = [ err_str, "div", err_str, err_str, err_str, "lparen", "rparen", "plus", "minus", "times", \
            err_str, "assign", err_str, "number", "number", "id" ]
    keyword_table = [ "read", "write" ]
    char_dict = {" ":0, "\t":1, "\n":2, "/":3, "*":4, "(":5, ")":6, "+":7, "-":8, ":":9, "=":10, ".":11, "0":12, "a":13}
    token_string = ""

    cur_state = start_state

    while File_queue != []:
        cur_char = File_queue[0]
        token_string += cur_char

        if cur_char.isalpha():
            cur_char = "a"
        elif cur_char.isdigit():
            cur_char = "0"
        elif cur_char not in char_dict:
            return ( err_str, err_str )

        cur_char_id = char_dict.get(cur_char)

        transition_table_cell = transition_table[ cur_state -1 ][ cur_char_id ]

        if transition_table_cell[0] == 0:
            cur_state = transition_table_cell[1]
            if cur_state == start_state:
                token_string = ""
            File_queue.pop(0)
        elif transition_table_cell[0] == 1:
            token_string = token_string[:-1]
            if ( cur_state == keyword_state ) and ( token_string in keyword_table ):
                return ( token_string, token_string )
            else:
                return ( token_table[cur_state - 1], token_string )
        elif transition_table_cell[0] == 2:
            return ( err_str, err_str )

    return ( "$$", "$$" )

def tag( name, indent ):
    """ formats tag for parse tree
    Input:
        - name: (string) name of the tag
        - indent: (int) space before tag
    Output:
        - tag: (string)
    Side Effect: none
    """
    tag = "|   " * indent + "<" + name + ">\n"
    return tag

def match( expect_token, depth ):
    """ match tokens with grammar
    Input:
        - expect_token: (string) expected token for grammar
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Input_token
        - modifies Parse_tree
    """
    global Input_token
    global Parse_tree

    Parse_tree += tag( expect_token, depth )
    Parse_tree += tag( "", 1 )[:-3] * ( depth + 1 ) + Input_token[1] + "\n"

    if expect_token == Input_token[0]:
        Input_token = scan()
        result = True
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/" + expect_token, depth )
    return result

def program():
    """ program grammar
    Input: none
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "program", 0 )

    if Input_token[0] in ["id", "read", "write", "$$"]:
        result = stmt_list( 1 )
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/program", 0 )
    return result

def stmt_list( depth ):
    """ stmt_list grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "stmt_list", depth )

    if Input_token[0] in ["id", "read", "write"]:
        subresult1 = stmt( depth + 1 )
        subresult2 = stmt_list( depth + 1 )
        result = subresult1 and subresult2
    elif Input_token[0] == "$$":
        result = True
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/stmt_list", depth )
    return result

def stmt( depth ):
    """ stmt grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "stmt", depth )

    if Input_token[0] == "id":
        subresult1 = match( "id", depth + 1 )
        subresult2 = match( "assign", depth + 1 )
        subresult3 = expr( depth + 1 )
        result = subresult1 and subresult2 and subresult3
    elif Input_token[0] == "read":
        subresult1 = match( "read", depth + 1 )
        subresult2 = match( "id", depth + 1 )
        result = subresult1 and subresult2
    elif Input_token[0] == "write":
        subresult1 = match( "write", depth + 1 )
        subresult2 = expr( depth + 1 )
        result = subresult1 and subresult2
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/stmt", depth )
    return result

def expr( depth ):
    """ expr grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "expr", depth )

    if Input_token[0] in ["lparen", "id", "number"]:
        subresult1 = term( depth + 1 )
        subresult2 = term_tail( depth + 1 )
        result = subresult1 and subresult2
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/expr", depth )
    return result

def term( depth ):
    """ term grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "term", depth )

    if Input_token[0] in ["lparen", "id", "number"]:
        subresult1 = factor( depth + 1 )
        subresult2 = fact_tail( depth + 1 )
        result = subresult1 and subresult2
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/term", depth )
    return result

def term_tail( depth ):
    """ term_tail grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "term_tail", depth )

    if Input_token[0] in ["plus", "minus"]:
        subresult1 = add_op( depth + 1 )
        subresult2 = term( depth + 1 )
        subresult3 = term_tail( depth + 1 )
        result = subresult1 and subresult2 and subresult3
    elif Input_token[0] in ["rparen", "id", "read", "write", "$$"]:
        result = True
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/term_tail", depth )
    return result

def factor( depth ):
    """ factor grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "factor", depth )

    if Input_token[0] == "lparen":
        subresult1 = match( "lparen", depth + 1 )
        subresult2 = expr( depth + 1 )
        subresult3 = match( "rparen", depth + 1 )
        result = subresult1 and subresult2 and subresult3
    elif Input_token[0] == "id":
        result = match( "id", depth + 1 )
    elif Input_token[0] == "number":
        result = match( "number", depth + 1 )
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/factor", depth )
    return result

def fact_tail( depth ):
    """ fact_tail grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "fact_tail", depth )

    if Input_token[0] in ["times", "div"]:
        subresult1 = mult_op( depth + 1 )
        subresult2 = factor( depth + 1 )
        subresult3 = fact_tail( depth + 1 )
        result = subresult1 and subresult2 and subresult3
    elif Input_token[0] in ["plus", "minus", "rparen", "id", "read", "write", "$$"]:
        result = True
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/fact_tail", depth )
    return result

def add_op( depth ):
    """ add_op grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "add_op", depth )

    if Input_token[0] == "plus":
        result = match( "plus", depth + 1 )
    elif Input_token[0] == "minus":
        result = match( "minus", depth + 1 )
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/add_op", depth )
    return result

def mult_op( depth ):
    """ mult_op grammar
    Input:
        - depth: (int) depth of recursion in program()
    Output:
        - result: (bool)
    Side Effect:
        - modifies Parse_tree
    """
    global Parse_tree

    Parse_tree += tag( "mult_op", depth )

    if Input_token[0] == "times":
        result = match( "times", depth + 1 )
    elif Input_token[0] == "div":
        result = match( "div", depth + 1 )
    else:
        #DEBUG
        print('match error', Input_token)
        result = False

    Parse_tree += tag( "/mult_op", depth )
    return result

main()
