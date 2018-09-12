import sys
from antlr4 import *
from MIPLLexer import MIPLLexer
from MIPLParser import MIPLParser
from MIPLListener import *

def main(argv):
    input = FileStream(argv[1])
    lexer = MIPLLexer(input)
    stream = CommonTokenStream(lexer)
    parser = MIPLParser(stream)
    tree = parser.n_start()

    printer = MIPLListener()
    walker = ParseTreeWalker()
    walker.walk(printer, tree)

    #output = open("output.html","w")
    
    #output.close()      

if __name__ == '__main__':
    main(sys.argv)

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
