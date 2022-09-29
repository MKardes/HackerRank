read N
read -a A
x=0
for i in "${A[@]}"
    do
    let " x ^= $i "
done
echo $x
