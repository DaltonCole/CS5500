declare -i x=0

for i in ./input/* ; do
	python3 antlr.py $i > ./my_output/$x
	x=$((x+1))
done