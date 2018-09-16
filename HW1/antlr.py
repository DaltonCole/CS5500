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
        print(recognizer)
        print(offendingSymbol)
        print(line)
        print(column)
        print(msg)
        print(e)
        sys.exit(1)

def main(argv):
    input = FileStream(argv[1])
    lexer = MIPLLexer(input)
    stream = CommonTokenStream(lexer)
    parser = MIPLParser(stream)
    parser._listeners = [MyErrorListener()]
    ParseTree = parser.n_start()

    """
    printer = MIPLListener()
    walker = ParseTreeWalker()
    walker.walk(printer, tree)
    """

    #output = open("output.html","w")
    
    #output.close()      

if __name__ == '__main__':
    main(sys.argv)

"""
if __name__ == "__main__":
    inputStream = StdinStream( )
    lexer = AlmostEmptyLexer(inputStream)
    # Add your error listener to the lexer if required
    #lexer.removeErrorListeners()
    #lexer._listeners = [ MyErrorListener() ]
    stream = CommonTokenStream(lexer)
    parser = AlmostEmptyParser(stream)
    parser._listeners = [ MyErrorListener() ]
    tree = parser.animals()
"""
'''
def main():
    lexer = HelloLexer(StdinStream())
    stream = CommonTokenStream(lexer)
    parser = HelloParser(stream)
    tree = parser.hi()
    printer = HelloPrintListener()
    walker = ParseTreeWalker()
    walker.walk(printer, tree)
'''

