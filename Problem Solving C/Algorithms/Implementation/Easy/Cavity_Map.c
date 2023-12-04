char** cavityMap(int grid_count, char** grid, int* result_count)
{
    int x = 1, y = 1;
    while (y < grid_count - 1)
    {
        x = 1;
        while(x < grid_count - 1)
        {
            if ((grid[y][x] > grid[y][x + 1]) && (grid[y][x] > grid[y][x - 1])
                && (grid[y][x] > grid[y + 1][x]) && (grid[y][x] > grid[y - 1][x]))
                grid[y][x] = 'X';
            x++;
        }
        y++;
    }
    *result_count = grid_count;
    return grid;
}
