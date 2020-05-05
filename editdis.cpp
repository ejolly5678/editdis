/*
Elizabeth Jolly 
Spring 2020

Using the transformatin of turning one word into another, detects if a word in a block of text is the same or within a certain number of transformations
to the comparison word
*/
#include <fstream>
#include <iostream>
#include <string>  
#include <sstream>
#include <stdio.h>

using namespace std;

void process_line(string line, int edit_distance, int copy_cost, int del_cost, int insert_cost, int sub_cost, string word);
bool process_word(string inner_word, string word, int edit_distance, int copy_cost, int del_cost, int insert_cost, int sub_cost);
bool compare_char_ignore(char char1, char char2);

int main (int argc, char* argv[]){
    string word; //the word that is being compared 
    int edit_distance; //distance you can edit a word 
    int copy_cost; //price of doing a copy
    int del_cost; //price of doing a deletion
    int insert_cost; //price of doing an insertion 
    int sub_cost; // price of doing a subsitution 

    cin >> word;
    cout << word << endl;
    cin >> edit_distance;
    cout << to_string(edit_distance) << endl;
    cin >> copy_cost;
    cin >> del_cost;
    cin >> insert_cost;
    cin >> sub_cost;
    cout << to_string(copy_cost) + " " + to_string(del_cost) + " " + to_string(insert_cost) + " " + to_string(sub_cost) << endl;
    
    string line; //the current line
    while (getline(cin, line)){
        process_line( line, edit_distance, copy_cost, del_cost, insert_cost,  sub_cost, word);
        cout << endl;
        }
    return 0;
}



//processes each line
void process_line(string line, int edit_distance, int copy_cost, int del_cost, int insert_cost, int sub_cost, string word){
    bool state = false; //true if inside word, false if outside word
    string inner_word;
    bool ran_word = false;
    char current_char;
    stringstream word_ss(line);
    while(word_ss >> inner_word){
        stringstream char_ss(inner_word);
        string actual_word; 
        while(char_ss >> current_char){
            if(state){
                if(isalpha(current_char)){
                    actual_word = actual_word + current_char;
                }
                else{
                    bool editdis = process_word(actual_word, word, edit_distance, copy_cost, del_cost, insert_cost, sub_cost);
                    if(editdis){
                        cout << "(" + actual_word + ")";
                    }
                    else{
                        cout << actual_word + " ";
                    }
                    ran_word = true;
                    state = false;
                    actual_word = "";
                    cout << current_char;
                }
            }
            else{
                if(!isalpha(current_char)){
                    cout << current_char;
                   
                }
                else{
                    state = true;
                    actual_word = current_char;
                }

            }
        }
        
            bool editdis = process_word(actual_word, word, edit_distance, copy_cost, del_cost, insert_cost, sub_cost);
            if(editdis){
                cout << "(" + actual_word + ")";
            }
            else{
                cout << actual_word + " ";
            }
        
        //cout << " ";
        ran_word = false;
    }
      
    }
 

//processes each word
bool process_word(string inner_word, string word, int edit_distance, int copy_cost, int del_cost, int insert_cost, int sub_cost){
    int edits_done = 0; //amount of edits done
    int count = 0; //the length of the longer word
    if(inner_word == word){
            return true;     
        
    }
    else if(inner_word.length() >= word.length()){
        while(count < inner_word.length()){
            if(count > word.length()){
                edits_done = edits_done + insert_cost;
            }
            else if(compare_char_ignore(inner_word[count], word[count])){
                edits_done = edits_done + copy_cost;
            }
            else{
                edits_done = edits_done + sub_cost;
            }
            count ++;
        }
    }
    else if(inner_word.length() < word.length()){
        while(count < word.length()){
            if(count > inner_word.length()){
                edits_done = edits_done + del_cost;
            }
            else if(compare_char_ignore(inner_word[count], word[count])){
                edits_done = edits_done + copy_cost;
            }
            else{
                edits_done = edits_done + sub_cost;
            }
            count ++;
        }
    }
    
    if(edits_done >  edit_distance){
        return false;
    }
    else{
        return true;
    }
    
}
//compares two chars ignoring their case.
bool compare_char_ignore(char char1, char char2){
    if(tolower(char1)== tolower(char2))
        return true;
    else
        return false;
    
}