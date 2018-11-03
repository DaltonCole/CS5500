flex mipl.l
bison mipl.y
g++ mipl.tab.c -o mipl_parser
./mipl_parser $1