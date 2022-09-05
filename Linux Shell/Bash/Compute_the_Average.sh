#https://nick3499.medium.com/bash-echo-scale-bc-numerical-fractions-753fb979792c

read div
sum=0
for i in $(seq 1 1 $div)
do
	read x
	sum=$(( $x + $sum ))
done
printf "%.3f" `echo "scale=10; $sum/$div" | bc -l`
