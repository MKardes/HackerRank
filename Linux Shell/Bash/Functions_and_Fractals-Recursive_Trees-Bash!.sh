read N

print () {
    for i in $(seq "$1")
    do
        echo -ne $2
    done
}

print_row () {
    for j in $(seq $1)
    do
        print 100 "_"
        printf "\n"
    done
}

print_last () {
    for w in {1..16}
    do
        print 49 "_"
        print 1 "1"
        print 50 "_"
        printf "\n"
    done
}

#$1 oncesindeki "_" sayisi
#$2 kac satir
print_corner () {
    for a in $(seq "$2")
    do
        print $(($1 + $a - 1)) "_"
        print 1 "1"
        print $(($1 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 + $a)) "_"
        printf "\n"
    done
}

print_cor2 () {
    for a in $(seq "$2")
    do
        print $(($1 + $a - 1)) "_"
        print 1 "1"
        print $(($1 - 8 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 12 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 8 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 + $a)) "_"
        printf "\n"
    done
    for a in $(seq "$2")
    do
        print 33 "_"
        print 1 "1"
        print 31 "_"
        print 1 "1"
        print 34 "_"
        printf "\n"
    done
}

print_cor3 () {
    for a in $(seq "$2")
    do
        print $(($1 + $a - 1)) "_"
        print 1 "1"
        print $(($1 - 12 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 16 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 12 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 16 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 12 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 16 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 12 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 + $a)) "_"
        printf "\n"
    done
    for a in $(seq "$2")
    do
        print 25 "_"
        print 1 "1"
        print 15 "_"
        print 1 "1"
        print 15 "_"
        print 1 "1"
        print 15 "_"
        print 1 "1"
        print 26 "_"
        printf "\n"
    done
    print_cor2 25 8
}

print_cor4 () {
    for a in $(seq "$2")
    do
        print $(($1 + $a - 1)) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 18 + $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 - 14 - $((2 * $a)))) "_"
        print 1 "1"
        print $(($1 + $a)) "_"
        printf "\n"
    done
    for a in $(seq "$2")
    do
        print 21 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 7 "_"
        print 1 "1"
        print 22 "_"
        printf "\n"
    done
    print_cor3 21 4
}

print_cor5 () {
    print $1 "_"
    for a in {1..31}
    do
        printf "1"
        printf "_"
    done
    printf "1"
    print 19 "_"
    printf "\n"
    for a in $(seq "$2")
    do
        print 19 "_"
        for s in {1..15}
        do
            printf "1"
            print 3 "_"
        done
        printf "1"
        print 20 "_"
        printf "\n"
    done
    print_cor4 19 2
}

print_row 1

if [ $N -eq 5 ]
then
    print_cor5 18 1
else
    print_row 2
fi

if [ $N -eq 4 ]
then
    print_cor4 19 2
elif [ $N -lt 4 ]
then
    print_row 4
fi

if [ $N -eq 3 ]
then
    print_cor3 21 4
elif [ $N -lt 3 ]
then
    print_row 8
fi

if [ $N -eq 2 ]
then
    print_cor2 25 8
elif [ $N -lt 2 ]
then
    print_row 16
fi

print_corner 33 16
print_last
