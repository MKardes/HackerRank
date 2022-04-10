int designerPdfViewer(int h_count, int* h, char* word)
{
    int i = 0, max = 0;
    while (word[i])
    {
        if (h[word[i] - 97] > max)
            max = h[word[i] - 97];
        i++;
    }
    max *= i;
    return (max);
}
