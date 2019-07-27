#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

using WordRep = map<char, int>;

// Forward declarations
bool areAnagrams(const string& word1, const string& word2);
WordRep getRep(const string& word);
ostream& operator<<(ostream& lhs, const WordRep& rhs);

bool areAnagrams(const string& word1, const string& word2)
{
    auto rep1 = getRep(word1);
    auto rep2 = getRep(word2);
    return rep1 == rep2;
}

WordRep getRep(const string& word)
{
    WordRep retVal;
    for (auto letter : word)
    {
        if (retVal.find(letter) == retVal.end())
            retVal[letter] = 1;
        else
            ++retVal[letter];
    }

    return retVal;
}

ostream& operator<<(ostream& lhs, const WordRep& rhs)
{
    for (auto myPair : rhs)
        lhs << myPair.first << " = " << myPair.second << endl;

    return lhs;
}

int main()
{
    bool isAnagram = areAnagrams("doggy", "goddard");

    stringstream output;
    output << (isAnagram ? "Are anagrams" : "Are NOT anagrams")
           << " of each other" << endl;
    cout << output.str();
    return 0;
}
