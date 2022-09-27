awk '{
    printf "%s;", $0
    if (getline <= 0)
        print ""
    else
        print $0
}'
