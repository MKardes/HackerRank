i=0
while read line
do
    a[$i]=$line
    i=$(( $i + 1 ))
done
a[$i]=$line

for x in {1..3}
do
    printf "${a[0]} "
    for j in $(seq "$i")
    do
        printf "${a[$j]}"
        printf " "
    done
done
