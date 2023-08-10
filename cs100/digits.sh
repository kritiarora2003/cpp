t=0
for ((i=1000;i<=2000;i++)) 
do
	if [[ $i == *"3"* ]]
	then
		((t++))
	fi
done
echo "$t"
