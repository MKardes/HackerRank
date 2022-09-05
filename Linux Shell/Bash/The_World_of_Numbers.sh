# sum=`expr $num1 + $num2`
# sum=$(expr $num1 + $num2)
# sum=$(($num1 + $num2))

read A
read B
echo $(($A + $B))
echo $(($A - $B))
echo $(($A * $B))
echo $(($A / $B))
