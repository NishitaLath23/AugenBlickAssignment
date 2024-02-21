#include <bits/stdc++.h>
using namespace std;

vector<string> northTilt(vector<string> grid)
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].length(); j++)
        {
            if(grid[i][j]=='O')
            {
                int pt=i;
                for(int k=i-1; k>=0; k--)
                {
                    if(grid[k][j]=='O' || grid[k][j]=='#')
                        break;
                    else
                        pt=k;
                }
                if(pt!=i)
                {
                    grid[pt][j]='O';
                    grid[i][j]='.';
                }
            }
        }
    }
    return grid;
}

int totalLoad(vector<string> grid)
{
    int n=grid.size();
    int load=0;
    for(int i=0; i<n; i++)
    {
        int ct=0;
        for(int j=0; j<grid[i].length(); j++)
        {
            if(grid[i][j]=='O')
                ct++;
        }
        load+=(ct*(n-i));
    }
    return load;
}
int main()
{
    vector<string> grid={
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
    };
    grid=northTilt(grid);
    int load=totalLoad(grid);
    cout<<"The total load on the north support beams is: "<<load;
    return 0;
}