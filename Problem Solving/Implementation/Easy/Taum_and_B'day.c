long taumBday(int b_1, int w_1, int bc_1, int wc_1, int z)
{
    long b = b_1;
    long w = w_1;
    long bc = bc_1;
    long wc = wc_1;
    long sum = 0;
    long big_cost , small_cost, big_cnt, small_cnt;
    
    if (wc >= bc)
    {
        big_cost = wc;
        big_cnt = w;
        small_cost = bc;
        small_cnt = b;
    }
    else
    {
        big_cost = bc;
        big_cnt = b;
        small_cost = wc;
        small_cnt = w;
    }
    if (small_cost + z >= big_cost)
    {
        sum = (b * bc) + (w * wc);
    }
    else
        sum = ((small_cost + z) * big_cnt) + (small_cost * small_cnt);
    printf("\n");
    return sum;
}
