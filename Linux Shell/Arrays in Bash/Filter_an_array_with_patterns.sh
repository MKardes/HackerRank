i=0
while read line
do
    a[$i]=$line
    i=$(( $i + 1 ))
done

temp=( ${a[@]/*a*/} )
echo ${temp[@]/*A*/}
