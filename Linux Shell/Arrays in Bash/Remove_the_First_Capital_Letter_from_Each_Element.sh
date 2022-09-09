i=0
while read line
do
    a[$i]=$line
    i=$(( $i + 1 ))
done
a[$i]=$line

echo ${a[@]/[A-Z]/.}
