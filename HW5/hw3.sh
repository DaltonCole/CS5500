# Ben Giles' Super Neato-Easy HW2 Runner

echo "Flex..."
flex coled.l
echo "Bison..."
bison coled.y
echo "Compiling..."
g++ coled.tab.c -o coled_parser
echo "Running Tests..."

for file in `ls inputs`; do
  echo -n "Running your output against $file..."
  ./coled_parser < inputs/$file > temp.txt
  diff temp.txt outputs/$file.out > diff.txt
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

rm coled.tab.c coled_parser lex.yy.c temp.txt diff.txt