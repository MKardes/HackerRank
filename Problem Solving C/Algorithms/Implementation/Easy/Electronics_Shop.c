int getMoneySpent(int keyboards_count, int* keyboards, int drives_count, int* drives, int b)
{
    int max = -1;
    int key = 0, usb = 0;
    while (key < keyboards_count)
    {
        usb = 0;
        while (usb < drives_count)
        {
            if (keyboards[key] + drives[usb] > max && b >= keyboards[key] + drives[usb])
                max = keyboards[key] + drives[usb];
            usb++;
        }
        key++;
    }
    return max;
}
