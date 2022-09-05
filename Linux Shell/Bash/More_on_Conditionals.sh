read x
read y
read z
if [ "$x" = "$y" -a "$y" = "$z" ]
then
	    echo "EQUILATERAL"
    elif [ "$x" = "$y" -o "$x" = "$z" -o "$y" = "$z" ]
    then
	        echo "ISOSCELES"
	else
		    echo "SCALENE"
fi
