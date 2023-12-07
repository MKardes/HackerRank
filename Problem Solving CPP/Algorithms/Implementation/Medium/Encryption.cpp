#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

string encryption(string s) {
    string withNoSpace, result;

    for (char c : s) {
        if (!std::isspace(c)) {
            withNoSpace += c;
        }
    }
    int length = withNoSpace.length();
    double sqrtLength = sqrt(static_cast<double>(length));
    int ceil = std::ceil(sqrtLength);
    int floor = std::floor(sqrtLength);
    int column = ceil;
    if (ceil != floor && (ceil * ceil < length) && (ceil * floor < length))
    {
        column = floor;
    }
    int i = 1;
    for(char c : withNoSpace) {
        result += c;
        if (i % column == 0) {
            result += " ";
        }
        i++;
    }
    istringstream iss(result);
    vector<string> words;

    // Split the string by spaces
    do {
        string word;
        iss >> word;
        words.push_back(word);
    } while (iss);
    result.clear();
    for (i = 0; i < words[0].length(); i++)
    {
        for(int j = 0; j < words.size(); j++)
        {
            if(words[j].length() > i)
                result += words[j][i];
        }
        result += " ";
    }
    return result;
    // 7 8
    //  7 7 || 8 8 || 7 8
    // 8 8
    //  8 8
    // 7 7
    //  7 7
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
