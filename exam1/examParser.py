# Generated from exam.g4 by ANTLR 4.5.1
# encoding: utf-8
from antlr4 import *
from io import StringIO

def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\20")
        buf.write("%\4\2\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\3\2")
        buf.write("\3\2\3\3\3\3\3\3\5\3\24\n\3\3\4\3\4\3\4\3\4\3\5\3\5\3")
        buf.write("\5\3\5\3\5\5\5\37\n\5\3\6\3\6\3\7\3\7\3\7\2\2\b\2\4\6")
        buf.write("\b\n\f\2\4\3\2\f\20\3\2\b\13 \2\16\3\2\2\2\4\23\3\2\2")
        buf.write("\2\6\25\3\2\2\2\b\36\3\2\2\2\n \3\2\2\2\f\"\3\2\2\2\16")
        buf.write("\17\5\4\3\2\17\3\3\2\2\2\20\21\7\4\2\2\21\24\5\6\4\2\22")
        buf.write("\24\5\6\4\2\23\20\3\2\2\2\23\22\3\2\2\2\24\5\3\2\2\2\25")
        buf.write("\26\7\5\2\2\26\27\7\7\2\2\27\30\5\b\5\2\30\7\3\2\2\2\31")
        buf.write("\37\5\f\7\2\32\33\5\n\6\2\33\34\7\6\2\2\34\35\5\f\7\2")
        buf.write("\35\37\3\2\2\2\36\31\3\2\2\2\36\32\3\2\2\2\37\t\3\2\2")
        buf.write("\2 !\t\2\2\2!\13\3\2\2\2\"#\t\3\2\2#\r\3\2\2\2\4\23\36")
        return buf.getvalue()


class examParser ( Parser ):

    grammarFileName = "exam.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "<INVALID>", "'var'", "<INVALID>", "'of'", 
                     "':'", "'integer'", "'char'", "'boolean'", "'real'", 
                     "'array'", "'stack'", "'queue'", "'list'", "'tree'" ]

    symbolicNames = [ "<INVALID>", "WSPACE", "T_VAR", "T_IDENT", "T_OF", 
                      "T_COLON", "T_INT", "T_CHAR", "T_BOOLEAN", "T_REAL", 
                      "T_ARRAY", "T_STACK", "T_QUEUE", "T_LIST", "T_TREE" ]

    RULE_n_start = 0
    RULE_n_var = 1
    RULE_n_declair = 2
    RULE_n_type = 3
    RULE_n_collectiontype = 4
    RULE_n_basetype = 5

    ruleNames =  [ "n_start", "n_var", "n_declair", "n_type", "n_collectiontype", 
                   "n_basetype" ]

    EOF = Token.EOF
    WSPACE=1
    T_VAR=2
    T_IDENT=3
    T_OF=4
    T_COLON=5
    T_INT=6
    T_CHAR=7
    T_BOOLEAN=8
    T_REAL=9
    T_ARRAY=10
    T_STACK=11
    T_QUEUE=12
    T_LIST=13
    T_TREE=14

    def __init__(self, input:TokenStream):
        super().__init__(input)
        self.checkVersion("4.5.1")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None



    class N_startContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def n_var(self):
            return self.getTypedRuleContext(examParser.N_varContext,0)


        def getRuleIndex(self):
            return examParser.RULE_n_start

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterN_start" ):
                listener.enterN_start(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitN_start" ):
                listener.exitN_start(self)




    def n_start(self):

        localctx = examParser.N_startContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_n_start)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 12
            self.n_var()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class N_varContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def T_VAR(self):
            return self.getToken(examParser.T_VAR, 0)

        def n_declair(self):
            return self.getTypedRuleContext(examParser.N_declairContext,0)


        def getRuleIndex(self):
            return examParser.RULE_n_var

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterN_var" ):
                listener.enterN_var(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitN_var" ):
                listener.exitN_var(self)




    def n_var(self):

        localctx = examParser.N_varContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_n_var)
        try:
            self.state = 17
            token = self._input.LA(1)
            if token in [examParser.T_VAR]:
                self.enterOuterAlt(localctx, 1)
                self.state = 14
                self.match(examParser.T_VAR)
                self.state = 15
                self.n_declair()

            elif token in [examParser.T_IDENT]:
                self.enterOuterAlt(localctx, 2)
                self.state = 16
                self.n_declair()

            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class N_declairContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def T_IDENT(self):
            return self.getToken(examParser.T_IDENT, 0)

        def T_COLON(self):
            return self.getToken(examParser.T_COLON, 0)

        def n_type(self):
            return self.getTypedRuleContext(examParser.N_typeContext,0)


        def getRuleIndex(self):
            return examParser.RULE_n_declair

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterN_declair" ):
                listener.enterN_declair(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitN_declair" ):
                listener.exitN_declair(self)




    def n_declair(self):

        localctx = examParser.N_declairContext(self, self._ctx, self.state)
        self.enterRule(localctx, 4, self.RULE_n_declair)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 19
            self.match(examParser.T_IDENT)
            self.state = 20
            self.match(examParser.T_COLON)
            self.state = 21
            self.n_type()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class N_typeContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def n_basetype(self):
            return self.getTypedRuleContext(examParser.N_basetypeContext,0)


        def n_collectiontype(self):
            return self.getTypedRuleContext(examParser.N_collectiontypeContext,0)


        def T_OF(self):
            return self.getToken(examParser.T_OF, 0)

        def getRuleIndex(self):
            return examParser.RULE_n_type

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterN_type" ):
                listener.enterN_type(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitN_type" ):
                listener.exitN_type(self)




    def n_type(self):

        localctx = examParser.N_typeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 6, self.RULE_n_type)
        try:
            self.state = 28
            token = self._input.LA(1)
            if token in [examParser.T_INT, examParser.T_CHAR, examParser.T_BOOLEAN, examParser.T_REAL]:
                self.enterOuterAlt(localctx, 1)
                self.state = 23
                self.n_basetype()

            elif token in [examParser.T_ARRAY, examParser.T_STACK, examParser.T_QUEUE, examParser.T_LIST, examParser.T_TREE]:
                self.enterOuterAlt(localctx, 2)
                self.state = 24
                self.n_collectiontype()
                self.state = 25
                self.match(examParser.T_OF)
                self.state = 26
                self.n_basetype()

            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class N_collectiontypeContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def T_STACK(self):
            return self.getToken(examParser.T_STACK, 0)

        def T_QUEUE(self):
            return self.getToken(examParser.T_QUEUE, 0)

        def T_LIST(self):
            return self.getToken(examParser.T_LIST, 0)

        def T_TREE(self):
            return self.getToken(examParser.T_TREE, 0)

        def T_ARRAY(self):
            return self.getToken(examParser.T_ARRAY, 0)

        def getRuleIndex(self):
            return examParser.RULE_n_collectiontype

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterN_collectiontype" ):
                listener.enterN_collectiontype(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitN_collectiontype" ):
                listener.exitN_collectiontype(self)




    def n_collectiontype(self):

        localctx = examParser.N_collectiontypeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 8, self.RULE_n_collectiontype)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 30
            _la = self._input.LA(1)
            if not((((_la) & ~0x3f) == 0 and ((1 << _la) & ((1 << examParser.T_ARRAY) | (1 << examParser.T_STACK) | (1 << examParser.T_QUEUE) | (1 << examParser.T_LIST) | (1 << examParser.T_TREE))) != 0)):
                self._errHandler.recoverInline(self)
            else:
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx

    class N_basetypeContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def T_INT(self):
            return self.getToken(examParser.T_INT, 0)

        def T_CHAR(self):
            return self.getToken(examParser.T_CHAR, 0)

        def T_BOOLEAN(self):
            return self.getToken(examParser.T_BOOLEAN, 0)

        def T_REAL(self):
            return self.getToken(examParser.T_REAL, 0)

        def getRuleIndex(self):
            return examParser.RULE_n_basetype

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterN_basetype" ):
                listener.enterN_basetype(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitN_basetype" ):
                listener.exitN_basetype(self)




    def n_basetype(self):

        localctx = examParser.N_basetypeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 10, self.RULE_n_basetype)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 32
            _la = self._input.LA(1)
            if not((((_la) & ~0x3f) == 0 and ((1 << _la) & ((1 << examParser.T_INT) | (1 << examParser.T_CHAR) | (1 << examParser.T_BOOLEAN) | (1 << examParser.T_REAL))) != 0)):
                self._errHandler.recoverInline(self)
            else:
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx





