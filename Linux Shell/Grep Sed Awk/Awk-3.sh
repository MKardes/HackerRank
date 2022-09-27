awk '{
    if ((($2 + $3 + $4) / 3) >= 80)
        print $0,": A";
    else if ((($2 + $3 + $4) / 3) >= 60)
        print $0,": B";
    else if ((($2 + $3 + $4) / 3) >= 50)
        print $0,": C";
    else
        print $0,": FAIL";
}'
