flex mipl.l
bison mipl.y -v
g++ mipl.tab.c -o mipl_parser
./mipl_parser $1