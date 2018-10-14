# Generated from exam.g4 by ANTLR 4.5.1
from antlr4 import *
from io import StringIO


def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\2\20")
        buf.write("j\b\1\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7")
        buf.write("\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4\f\t\f\4\r\t\r\4\16")
        buf.write("\t\16\4\17\t\17\3\2\6\2!\n\2\r\2\16\2\"\3\2\3\2\3\3\3")
        buf.write("\3\3\3\3\3\3\4\6\4,\n\4\r\4\16\4-\3\5\3\5\3\5\3\6\3\6")
        buf.write("\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3")
        buf.write("\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13")
        buf.write("\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\r")
        buf.write("\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\17\3\17")
        buf.write("\3\17\3\17\3\17\2\2\20\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21")
        buf.write("\n\23\13\25\f\27\r\31\16\33\17\35\20\3\2\4\4\2\13\13\"")
        buf.write("\"\3\2C\\k\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2")
        buf.write("\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2")
        buf.write("\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2")
        buf.write("\2\33\3\2\2\2\2\35\3\2\2\2\3 \3\2\2\2\5&\3\2\2\2\7+\3")
        buf.write("\2\2\2\t/\3\2\2\2\13\62\3\2\2\2\r\64\3\2\2\2\17<\3\2\2")
        buf.write("\2\21A\3\2\2\2\23I\3\2\2\2\25N\3\2\2\2\27T\3\2\2\2\31")
        buf.write("Z\3\2\2\2\33`\3\2\2\2\35e\3\2\2\2\37!\t\2\2\2 \37\3\2")
        buf.write("\2\2!\"\3\2\2\2\" \3\2\2\2\"#\3\2\2\2#$\3\2\2\2$%\b\2")
        buf.write("\2\2%\4\3\2\2\2&\'\7x\2\2\'(\7c\2\2()\7t\2\2)\6\3\2\2")
        buf.write("\2*,\t\3\2\2+*\3\2\2\2,-\3\2\2\2-+\3\2\2\2-.\3\2\2\2.")
        buf.write("\b\3\2\2\2/\60\7q\2\2\60\61\7h\2\2\61\n\3\2\2\2\62\63")
        buf.write("\7<\2\2\63\f\3\2\2\2\64\65\7k\2\2\65\66\7p\2\2\66\67\7")
        buf.write("v\2\2\678\7g\2\289\7i\2\29:\7g\2\2:;\7t\2\2;\16\3\2\2")
        buf.write("\2<=\7e\2\2=>\7j\2\2>?\7c\2\2?@\7t\2\2@\20\3\2\2\2AB\7")
        buf.write("d\2\2BC\7q\2\2CD\7q\2\2DE\7n\2\2EF\7g\2\2FG\7c\2\2GH\7")
        buf.write("p\2\2H\22\3\2\2\2IJ\7t\2\2JK\7g\2\2KL\7c\2\2LM\7n\2\2")
        buf.write("M\24\3\2\2\2NO\7c\2\2OP\7t\2\2PQ\7t\2\2QR\7c\2\2RS\7{")
        buf.write("\2\2S\26\3\2\2\2TU\7u\2\2UV\7v\2\2VW\7c\2\2WX\7e\2\2X")
        buf.write("Y\7m\2\2Y\30\3\2\2\2Z[\7s\2\2[\\\7w\2\2\\]\7g\2\2]^\7")
        buf.write("w\2\2^_\7g\2\2_\32\3\2\2\2`a\7n\2\2ab\7k\2\2bc\7u\2\2")
        buf.write("cd\7v\2\2d\34\3\2\2\2ef\7v\2\2fg\7t\2\2gh\7g\2\2hi\7g")
        buf.write("\2\2i\36\3\2\2\2\5\2\"-\3\b\2\2")
        return buf.getvalue()


class examLexer(Lexer):

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]


    WSPACE = 1
    T_VAR = 2
    T_IDENT = 3
    T_OF = 4
    T_COLON = 5
    T_INT = 6
    T_CHAR = 7
    T_BOOLEAN = 8
    T_REAL = 9
    T_ARRAY = 10
    T_STACK = 11
    T_QUEUE = 12
    T_LIST = 13
    T_TREE = 14

    modeNames = [ "DEFAULT_MODE" ]

    literalNames = [ "<INVALID>",
            "'var'", "'of'", "':'", "'integer'", "'char'", "'boolean'", 
            "'real'", "'array'", "'stack'", "'queue'", "'list'", "'tree'" ]

    symbolicNames = [ "<INVALID>",
            "WSPACE", "T_VAR", "T_IDENT", "T_OF", "T_COLON", "T_INT", "T_CHAR", 
            "T_BOOLEAN", "T_REAL", "T_ARRAY", "T_STACK", "T_QUEUE", "T_LIST", 
            "T_TREE" ]

    ruleNames = [ "WSPACE", "T_VAR", "T_IDENT", "T_OF", "T_COLON", "T_INT", 
                  "T_CHAR", "T_BOOLEAN", "T_REAL", "T_ARRAY", "T_STACK", 
                  "T_QUEUE", "T_LIST", "T_TREE" ]

    grammarFileName = "exam.g4"

    def __init__(self, input=None):
        super().__init__(input)
        self.checkVersion("4.5.1")
        self._interp = LexerATNSimulator(self, self.atn, self.decisionsToDFA, PredictionContextCache())
        self._actions = None
        self._predicates = None


