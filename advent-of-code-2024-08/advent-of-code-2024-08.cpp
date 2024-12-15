// advent-of-code-2024-08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
struct cordonnéesDuPoint
{
    int row;
    int column;
};
int distinct(std::vector<char> t, char c) {
    for (int i = 0;i<t.size();i++) {
        if (t[i]==c)
        {
            return false;
        }
    }
    return true;
}
int main() {
    int maxRows=0;
    int maxColumns = 0;
    std::ifstream file("input.txt");
    std::vector<std::vector<char>> fileMatrix;
    std::string line;
    std::unordered_map<char, std::vector<cordonnéesDuPoint>> myMap;
    //declaring a table to hold the distinct letters of the test file so I can loop through myMap
    std::vector<char> TabOfdistinctCharecters;
    int i = 0;
    int j=0;
    int count = 0;
    while (std::getline(file, line)) {
        fileMatrix.push_back(std::vector<char>());
        for (j = 0; j < line.size(); j++) {

            fileMatrix[i].push_back(line[j]);
            if (line[j]!='.')
            {
                myMap[line[j]].push_back({ i, j });
                if (distinct(TabOfdistinctCharecters,line[j]))
                {
                    TabOfdistinctCharecters.push_back(line[j]);
                    count++;
                }
            }
        }
        i++;
    }
    maxRows = i;
    maxColumns = j;
    int s = 0;
    int testRow;
    int testColumn;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < myMap[TabOfdistinctCharecters[i]].size(); j++) {
            for (int k = 0; k < myMap[TabOfdistinctCharecters[i]].size(); k++) {
                if (j!=k)
                {
                    int rowOfChar1 = myMap[TabOfdistinctCharecters[i]][j].row;
                    int columnOfChar1 = myMap[TabOfdistinctCharecters[i]][j].column;
                    int rowOfChar2 = myMap[TabOfdistinctCharecters[i]][k].row;
                    int columnOfChar2 = myMap[TabOfdistinctCharecters[i]][k].column;
                    int rowDiff = rowOfChar2 - rowOfChar1;
                    int columnDiff = columnOfChar2 - columnOfChar1;
                    if (rowOfChar2 + rowDiff < maxRows && rowOfChar2 + rowDiff >= 0 &&
                        columnOfChar2 + columnDiff < maxColumns && columnOfChar2 + columnDiff >= 0 &&
                        fileMatrix[rowOfChar2 + rowDiff][columnOfChar2 + columnDiff] != '#')
                    {
                        s++;
                        fileMatrix[rowOfChar2 + rowDiff][columnOfChar2 + columnDiff] = '#';
                    }
                } 
            }
        }
    }
    
    std::cout << s;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
