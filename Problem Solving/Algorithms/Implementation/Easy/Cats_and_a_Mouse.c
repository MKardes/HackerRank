char* catAndMouse(int x, int y, int z)
{
    char    *ret;
    int dist_A = x - z, dist_B = y - z;
    if (dist_A < 0)
        dist_A *= -1;
    if (dist_B < 0)
        dist_B *= -1;
    if (dist_A > dist_B)
        ret = strdup("Cat B");
    else if (dist_B > dist_A)
        ret = strdup("Cat A");
    else
        ret = strdup("Mouse C");
    return (ret);
}
