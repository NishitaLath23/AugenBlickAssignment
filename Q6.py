# changes in grid due to the tilt
def north_tilt(grid):
    grid_list = [list(row) for row in grid]

    for i in range(len(grid_list)):
        for j in range(len(grid_list[i])):
            if grid_list[i][j] == 'O':
                pt = i
                for k in range(i-1, -1, -1):
                    if grid_list[k][j] == 'O' or grid_list[k][j] == '#':
                        break
                    else:
                        pt = k
                if pt != i:
                    grid_list[pt][j] = 'O'
                    grid_list[i][j] = '.'
    
    return [''.join(row) for row in grid_list]

# calculating the total load
def total_load(grid):
    n = len(grid)
    load = 0
    for i, row in enumerate(grid):
        count_O = row.count('O')
        load += count_O * (n - i)
    return load

if __name__ == "__main__":
    grid = [
        "O....#....",
        "O.OO#....#",
        ".....##...",
        "OO.#O....O",
        ".O.....O#.",
        "O.#..O.#.#",
        "..O..#O..O",
        ".......O..",
        "#....###..",
        "#OO..#...."
    ]

    grid = north_tilt(grid)

    load = total_load(grid)
    print("The total load on the north support beams is:", load)
