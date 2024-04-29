#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<char,vector<string>> productions;

    for(int i=0; i<n; i++){
        cout << "Enter LHS of production " << i+1 << endl;
        char c;
        cin >> c;
        string s;
        cout << "Enter RHS of production " << i+1 << endl;
        cin >> s;
        productions[c].push_back(s);
    }


    for(auto pair : productions){
        char c = pair.first;
        vector<string> rules = pair.second;
        vector<string> lr,nlr;

        for(string rule : rules){
            if(rule[0] == c) lr.push_back(rule);
            else nlr.push_back(rule);
        }

        cout << c << "->";
        for(string rule : nlr){
            cout << rule << c << "' | ";
        }
        cout << endl;
        cout << c << "'->";
        for(string rule : lr){
            cout << rule.substr(1) << c << "' | ";
        }
        cout << "eps\n";
    }
}