import sys
from antlr4 import *
from examLexer import examLexer
from examParser import examParser
from examListener import *
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
    lexer = examLexer(input)
    stream = CommonTokenStream(lexer)
    parser = examParser(stream)
    ParseTree = parser.n_start()      

if __name__ == '__main__':
    main(sys.argv)
