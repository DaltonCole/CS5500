# Ben Giles' Super Neato-Easy HW2 Runner

echo "Flex..."
flex mipl.l
echo "Bison..."
bison mipl.y
echo "Compiling..."
g++ mipl.tab.c -o mipl_parser
echo "Running Tests..."

for file in `ls inputs`; do
  echo -n "Running your output against $file..."
  ./mipl_parser inputs/$file > temp.txt
  diff temp.txt outputs/${file::-4}.oal > diff.txt
  if [ $? -eq 0 ]; then
    echo -e " \e[92mPASS\e[39m"
  else
    # If your file failed, uncomment the following lines
    # To get the full diff between your output and the expected output
    echo -e " \e[91mFAIL\e[39m"
    # echo -e "\e[91mFile Diff:\e[39m"
    # cat diff.txt
  fi
done

rm mipl.tab.c mipl_parser lex.yy.c temp.txt diff.txt