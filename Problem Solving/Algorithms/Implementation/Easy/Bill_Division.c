void bonAppetit(int bill_count, int* bill, int k, int b)
{
    int i = 0;
    int amount = 0;
    while (i < bill_count)
    {
        if (i != k)
            amount += bill[i];
        i++;
    }
    amount /= 2;
    if (b - amount == 0)
        printf("Bon Appetit");
    else
        printf("%d",b - amount);
}
