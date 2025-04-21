
#include <iostream>
#include <fstream> 
#include <string>
#include <iterator>
#include <vector>
#include <List>
using namespace std;


/*
RULES:
BUNDLE n - (can put any number onto the stack)
MINE - (Accepts an integer input from the user and pushes it onto the stack)
FARM - (Accepts an character input from the user and pushes it onto the stack)
PLACE - (pops the top value of the stack and prints it as an ascii character)
DROP - (pops the top value off of the stack and prints it as an int)
DUPE - (duplicates the top value of the stack)
SMELT - (pops A and B off the stack and then puts B - A onto the stack)
CRAFT - (pops A and B off the stack and then puts B + A onto the stack)
THENETHER - (pops the top of the stack and pushes it to the bottom)
THEOVERWORLD - (pops the bottom value of the stack and pushes it to the top)
ENDERPEARL - (pops the top of the stack, if its not 0 then jump to the nth line)
DIE - (ends program)
*/



int main() {
    string filename;
    string codeInput;
    list<int> stack = {};
    vector<string> lines = {};
    int pc = 0;

    cout << "enter file name: " << endl;
    cin >> filename;
    ifstream codeInputFile("./"+filename);

    if(codeInputFile.is_open()){
        
        while(getline(codeInputFile, codeInput)){
            lines.push_back(codeInput);
        }
        
    }
    codeInputFile.close();

    while(pc >= 0 && pc < lines.size()){
        int position = lines.at(pc).find(" ");
            string instruction = lines.at(pc).substr(0,position);
            int parameter;

            if(position != -1){
                parameter = stoi(lines.at(pc).substr(position+1, lines.at(pc).length()));
            }
            

        //BUNDLE n - (can put any number onto the stack)
        if(instruction == "BUNDLE"){
            
            stack.push_front(parameter);
        }
        else if(instruction == "MINE"){
            int input;
            cin >> input;
            stack.push_front(input);
        }
        //FARM - (Accepts an character input from the user and pushes it onto the stack)
        else if(instruction == "FARM"){
            char input;
            cin >> input;
            if(input == '0'){
                stack.push_front(0);
            }else{
                stack.push_front(int(input));
            }
            
            
        }
        //PLACE - (pops the top value of the stack and prints it as an ascii character)
        else if(instruction == "PLACE") {
            int output = stack.front();
            stack.pop_front();
            cout << char(output) << endl;
        }
        //DROP - (pops the top value off of the stack and prints it as an int)
        else if(instruction == "DROP") {
            int output = stack.front();
            stack.pop_front();
            cout << int(output) << endl;
        }
        //DUPE - (duplicates the top value of the stack)
        else if(instruction == "DUPE") {
            int output = stack.front();
            stack.push_front(output);
        }
        //CRAFT - (pops A and B off the stack and then puts B - A onto the stack)
        else if(instruction == "CRAFT") {
            int a = stack.front();
            stack.pop_front();
            int b = stack.front();
            stack.pop_front();
            stack.push_front((b+a));
        }
        //SMELT - (pops A and B off the stack and then puts B - A onto the stack)
        else if(instruction == "SMELT") {
            int a = stack.front();
            stack.pop_front();
            int b = stack.front();
            stack.pop_front();
            stack.push_front((b-a));
        }
        //THENETHER - (pops the top of the stack and pushes it to the bottom)
        else if(instruction == "THENETHER") {
            int output = stack.front();
            stack.pop_front();
            stack.push_back(output);
        }
        //THEOVERWORLD - (pops the bottom value of the stack and pushes it to the top)
        else if(instruction == "THEOVERWORLD") {
            int output = stack.back();
            stack.pop_back();
            stack.push_front(output);
        }
        //ENDERPEARL - (pops the top of the stack, if its not 0 then jump to the nth line)
        else if(instruction == "ENDERPEARL") {
            int output = stack.front();
            stack.pop_front();
            if(output != 0){
                pc = parameter-2;
            }

        }
        //DIE - (ends program)
        else if(instruction == "DIE"){
            break;
        }

        pc += 1;
    }
    
    /*
    codeInputFile.open(filename);
    while(getline(codeInputFile, codeInput)){
        cin >> codeInput;
        if(codeInput == "hello"){
            cout << codeInput;
        }
    }
    */

    return 0;
}