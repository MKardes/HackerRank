echo "Enter your name"
read name
if [[ $name == "Neha" || $name == 'Nil' ]]; then
	echo "You have won the prize"
else 
	echo "Try for the next time"
fi
