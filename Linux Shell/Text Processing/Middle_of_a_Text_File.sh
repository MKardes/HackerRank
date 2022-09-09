#i=0

#while read line
#do
#    if [[ $i -gt 10 && $i -lt 22 ]]
#    then
#        echo $line
#    fi
#    i=$(( $i + 1 ))
#done

cat >> test
head -n 22 test >> text2
tail -n 11 text2
