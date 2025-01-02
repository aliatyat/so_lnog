int ft_strlen_2d(char **map)
{
    int count = 0;

    while (map[count])
        count++;
    return (count);
}

