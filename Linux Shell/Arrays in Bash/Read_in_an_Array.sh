#for i in {1..100}
#do
#    read x
#    printf "$x "
#done

while read line
do
	my_array+=( $line )
done

echo ${my_array[@]}
