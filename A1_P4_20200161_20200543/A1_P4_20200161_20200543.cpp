#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void RecPermute(string soFar, string rest)
{   
    static vector<string> answer;

    if (rest == "" && find(answer.begin(), answer.end(), soFar) == answer.end()){// No more characters
        cout << soFar << endl; // Print the word
        answer.push_back(soFar);
    }

    // For each remaining char
    for (unsigned int i = 0; i < rest.length(); i++) {
        string next = soFar + rest[i]; // Glue next char
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        RecPermute(next, remaining);
    }
}

// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}

int main(){

    string x = "Makka";
    ListPermutations(x);
}