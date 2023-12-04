int jumpingOnClouds(int c_count, int* c, int k)
{
    int i = 0, energy = 100;
    while (i < c_count)
    {
        if (c[i] == 1)
            energy -= 2;
        energy--;
        if (i + k > c_count && i + k != c_count)
            i = i - c_count;
        i += k;
    }
    return energy;
}
