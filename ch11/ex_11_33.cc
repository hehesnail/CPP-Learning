#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;

    while(map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        } else {
            cout << "error" << endl;
        }
    }

    return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m) {
    auto map_it = m.find(s);
    if (map_it != m.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);
    string txt;
    while(getline(input, txt)) {
        istringstream stream(txt);
        string word;
        bool first_word = true;
        while (stream >> word) {
            if (first_word) {
                first_word = false;
            } else {
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}


int main() {
    ifstream map_file("./1.txt");
    ifstream input("./2.txt");

    word_transform(map_file, input);

    return 0;
}