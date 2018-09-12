import sys
from antlr4 import *
from ChatLexer import ChatLexer
from ChatParser import ChatParser
from ChatListener import *

def main(argv):
    input = FileStream(argv[1])
    lexer = ChatLexer(input)
    stream = CommonTokenStream(lexer)
    parser = ChatParser(stream)
    tree = parser.chat()

    printer = ChatListener()
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
