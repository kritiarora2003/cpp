#!/bin/bash
arr=("auto" "double" "int" "struct" "break" "else" "long" "switch" "case" "enum" "register" "typedef" "char" "extern" "return" "union" "continue" "for" "signed" "void" "do" "if" "static" "while" "default" "goto" "sizeof" "volatile" "const" "float" "short" "unsigned")

for i in "${arr[@]}"
do
	a=`grep -o "\b$i\b" $1 | wc -w`
	echo "$i : $a"
done
