import sys
from antlr4 import *
from MIPLLexer import MIPLLexer
from MIPLParser import MIPLParser
from MIPLListener import *
from antlr4.error.ErrorListener import ErrorListener

class MyErrorListener( ErrorListener ):

    def __init__(self):
        super(MyErrorListener, self).__init__()

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        print("Line " + str(line) + ": syntax error")
        if '\'\'\'\'' in str(offendingSymbol):
            print("**** Invalid character constant: \'\'")
        elif '\'\'\'' in str(offendingSymbol):
            print("**** Invalid character constant: \'")
        else:
            number = str(offendingSymbol).split('\'')[1]
            if number.isdigit():
                print("**** Invalid integer constant: " + str(number))
        sys.exit(1)


def main(argv):
    input = FileStream(argv[1])
    lexer = MIPLLexer(input)
    stream = CommonTokenStream(lexer)
    parser = MIPLParser(stream)
    parser._listeners = [MyErrorListener()]
    ParseTree = parser.n_start()      

if __name__ == '__main__':
    main(sys.argv)
