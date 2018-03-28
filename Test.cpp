#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

//1. white space
//2. duplicates
//3. Capital >> Lowercase
//4. Sort

int main() {
    string line;
    while (getline(cin, line)) {

        list<char> charList; // list to hold the characters
        map<char, int> charMap; // Char map to keep track on the occurence

        // To traverse the string and put the characters into the list
        for (int i = 0; i < line.size(); i++) {
            char character = line[i];
            // If character is not space
            if(character != ' ') {


                //If it is a capital letter, change to lower case
                if(character <= 'Z' && character >= 'A') {
                    character = character - ('A' - 'a');
                }

                //If haven't seen the char, add it to the map
                //Else, skip it
                if(charMap.find(character) == charMap.end()) {
                    charMap[character] = 1;
                }
                else {
                    continue;
                }

                //push Characters in to the list
                charList.push_back(character);
            }
        }

        //Sort the list
        charList.sort();

        //Reset the string
        line = "";

        //Push those characters back to the string and commas
        for(list<char>::iterator it = charList.begin(); it != charList.end();
            it++) {
                line += *it;
                line += ',';
        }

        //Erase the last comma
        line.erase(line.size() - 1);

        cout << line << endl;
    }
}
