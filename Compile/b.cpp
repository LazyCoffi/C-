// #inculde<stdio>
#include <iostream>
#include <map>
#include<stdio.h>
#include <algorithm>
#include <vector>
#include<iomanip>
#include<cstring>
#include<stack>
using namespace std;
map<char, vector<string>> grammar;
map<char, vector<char>> First;
map<char, vector<char>> Follow;
map<char, bool> visitedFirst;
map<char, bool> visitedFollow;
// vector<char> search_First(char s);
// 暂时用:代替空字
string terminal[10] = { "i", "+", "-", "*", "/", ":", "(", ")" };
string notTerminal[5] = { "E", "G", "T", "S", "F" };

char terminal_temp[] = "i+-*/:()#";
char notTerminal_temp[] = "EGTSF";
int terminal_num = 8;
int not_terminal_num = 5;
string predict_table[5][9];

int size_each_Follow[5] = { Follow['E'].size(),Follow['G'].size(),Follow['T'].size(),Follow['S'].size(),Follow['F'].size() };
// 用stringstream更方便
int find_blank(string s, int begin) {
    string sub = s.substr(begin, s.length());
    // cout<<sub<<" ";
    if (sub.find(' ') != sub.npos) {
        // cout<<sub.find(' ')<<endl;
        return sub.find(' ') + begin;
    }
    else
        return -1;
}
void grammar_create() {
    string g[10];
    // 后续自己更改
    int g_length = 5;
    g[0] = "E->TG"; g[1] = "G->+TG -TG nothing";
    g[2] = "T->FS"; g[3] = "S->*FS /FS nothing";
    g[4] = "F->(E) i";
    for (int i = 0; i < g_length; i++) {
        vector<char> vec_char;
        visitedFirst[g[i][0]] = false;
        // 没什么用
        visitedFollow[g[i][0]] = false;
        First[g[i][0]] = vec_char;
        Follow[g[i][0]] = vec_char;
    }
    for (int i = 0; i < g_length; i++) {
        int index = g[i].find_first_of('-');
        char sb = g[i][0];
        vector<string> child;
        for (int j = index + 2; j < g[i].length(); j++) {
            int temp_index = find_blank(g[i], j);
            if (temp_index != -1) {
                if (g[i].substr(j, temp_index - j) == "nothing") {
                    child.push_back(":");
                }
                else
                    child.push_back(g[i].substr(j, temp_index - j));
                j = temp_index;
            }
            else {
                if (g[i].substr(j, g[i].length() - j) == "nothing") {
                    child.push_back(":");
                }
                else
                    child.push_back(g[i].substr(j, g[i].length() - j));
                break;
            }
        }
        grammar[sb] = child;
    }
}

// "E->TG";
// "G->+TG -TG nothing";
// "T->FS";
// "S->*FS /FS nothing";
// "F->(E) i";
// E->T->F->(
bool is_terminal(char s) {
    for (int i = 0; i < terminal_num; i++) {
        if (s == terminal_temp[i])
            return true;
    }
    return false;
}
bool not_terminal(char s) {
    for (int i = 0; i < not_terminal_num; i++) {
        if (s == notTerminal_temp[i])
            return true;
    }
    return false;
}
vector<char> search_First(char s) {
    if (visitedFirst[s])
        return First[s];
    visitedFirst[s] = true;
    char tempS;
    vector<char> vec;
    for (int i = 0; i < grammar[s].size(); i++) {
        tempS = grammar[s][i][0];
        bool flag = false;
        for (int j = 0; j < terminal_num; j++) {
            if (terminal[j][0] == tempS) {
                flag = true;
                vec.push_back(terminal[j][0]);
                break;
            }
        }
        if (!flag) {
            vector<char> temp = search_First(tempS);
            vec.insert(vec.end(), temp.begin(), temp.end());
            sort(vec.begin(), vec.end());
            vec.erase(unique(vec.begin(), vec.end()), vec.end());
        }
    }
    First[s] = vec;
    return vec;
}
void create_First() {
    for (map<char, vector<string>>::iterator it = grammar.begin(); it != grammar.end(); it++) {
        if (!visitedFirst[it->first])
            search_First(it->first);
    }
}

void if_create_follow_stop(bool &flag) {
    bool flagTemp = false;
    for (int i = 0; i < not_terminal_num; i++) {
        if (size_each_Follow[i] != Follow[notTerminal_temp[i]].size()) {
            size_each_Follow[i] = Follow[notTerminal_temp[i]].size();
            flagTemp = true;
        }
    }
    flag = flagTemp;
    return;
}
void create_Follow() {
    Follow['E'].push_back('#');
    bool flag = true;
    while (flag) {
        // i 是 follow的size
        for (map<char, vector<string>>::iterator it = grammar.begin(); it != grammar.end(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                // 产生式后半部分
                string tempS = it->second[i];
                for (int j = 0; j < tempS.length() - 1; j++) {
                    // 1. 若A→B是一个产生式，则把FIRST()\{}加至FOLLOW(B)中；
                    char current = tempS[j];
                    char next = tempS[j + 1];
                    if (not_terminal(current)) {
                        // 是终结符的情况
                        if (is_terminal(next)) {
                            Follow[current].push_back(next); 
                            sort(Follow[current].begin(), Follow[current].end());
                            Follow[current].erase(unique(Follow[current].begin(), Follow[current].end()), Follow[current].end());
                        }
                        // 不是终结符的情况
                        else {
                            Follow[current].insert(Follow[current].begin(), First[next].begin(), First[next].end());
                            // 如果First中存在空集的情况。
                            for (vector<char>::iterator it2 = Follow[current].begin(); it2 != Follow[current].end(); it2++) {
                                if (*it2 == ':') {
                                    Follow[current].erase(it2);
                                    Follow[current].insert(Follow[current].begin(), Follow[it->first].begin(), Follow[it->first].end());
                                    sort(Follow[current].begin(), Follow[current].end());
                                    Follow[current].erase(unique(Follow[current].begin(), Follow[current].end()), Follow[current].end());
                                    break;
                                }
                            }
                        }
                    }
                }
                if (not_terminal(tempS[tempS.length() - 1])) {
                    char current = tempS[tempS.length() - 1];
                    Follow[current].insert(Follow[current].begin(), Follow[it->first].begin(), Follow[it->first].end());
                    sort(Follow[current].begin(), Follow[current].end());
                    Follow[current].erase(unique(Follow[current].begin(), Follow[current].end()), Follow[current].end());
                }
            }
        }
        if_create_follow_stop(flag);
    }
}

int search_terminal_position(char c) {
    for (int i = 0; i < terminal_num+1; i++) {
        if (c == terminal_temp[i])
            return i;
    }
}
int search_not_terminal_position(char c) {
    for (int i = 0; i < not_terminal_num; i++) {
        if (c == notTerminal_temp[i])
            return i;
    }
}

void add_follow_to_predict(int pos, char c, string s) {
    for (int k = 0; k < Follow[c].size(); k++) {
        predict_table[pos][search_terminal_position(Follow[c][k])] = s;
    }
}

void create_predict_table() {
    for (int i = 0; i < not_terminal_num; i++) {
        char tempChar = notTerminal_temp[i];
        for (int j = 0; j < grammar[tempChar].size(); j++) {
            char currentChar = grammar[tempChar][j][0];
            if (currentChar == ':') {
                add_follow_to_predict(i, tempChar, grammar[tempChar][j]);
            }
            else if (is_terminal(currentChar)&&currentChar!=':') {
                predict_table[i][search_terminal_position(currentChar)] = grammar[tempChar][j];
            }
            else {
                for (int k = 0; k < First[currentChar].size(); k++) {
                    if (First[currentChar][k] == ':') {
                        add_follow_to_predict(i, tempChar, grammar[tempChar][j]);
                    }
                    else {
                        predict_table[i][search_terminal_position(First[currentChar][k])] = grammar[tempChar][j];
                    }
               
                }
            }
        }
    }
}

void anaysis(string s) {
    s += "#";
    stack<char> st;
    st.push('#');
    st.push('E');
    int current_in = 0;
    int current_step = 0;
    string s_stack = "#E";
    string produce = "";
    string action = "初始化";
    cout << left;
    while (true) {
        if (s[current_in] == st.top() && s[current_in] == '#') {
            break;
        }
        cout << setw(8) << current_step++;
        cout << setw(8) << s_stack;
        cout << setw(8) << s.substr(current_in, s.length() - current_in);
        cout << setw(16) << produce;
        cout << action<<endl;
        produce = "";
        action = "";
        if (s[current_in] == st.top()) {
            action = "GETNEXT(";
            action += st.top();
            action += ")";
            st.pop();
            s_stack.erase(s_stack.length() - 1);
            current_in++;
            
        }
        else {
            if (not_terminal(st.top())){
                int X_index = search_not_terminal_position(st.top());
                int a_index = search_terminal_position(s[current_in]);
                st.pop();
                s_stack.erase(s_stack.length() - 1);
                if (predict_table[X_index][a_index] != "") {
                    if (predict_table[X_index][a_index] != ":") {
                        //  + 
                        produce = notTerminal_temp[X_index];
                        produce.insert(produce.length(), "->");
                        produce.insert(produce.length(), predict_table[X_index][a_index]);
                        action = "POP,PUSH(";
                        action += predict_table[X_index][a_index];
                        action += ")";
                        for (int i = predict_table[X_index][a_index].length() -1; i >= 0; i--) {
                            st.push(predict_table[X_index][a_index][i]);
                            s_stack += predict_table[X_index][a_index][i];
                        }
                        
                    }
                    else{
                        
                        produce = notTerminal_temp[X_index] ;
                        produce.insert(produce.length(),"->ε");
                        action = "POP";
                    }
                }
                else{
                    cout << "error";
                    break;
                }
            }
            else{
                cout << "error";
                break;
            }
        }
        

    }
}

int main() {
   
    grammar_create();
    cout  << "CREATE:" << endl<<endl;
    for (map<char, vector<string>>::iterator it = grammar.begin(); it != grammar.end(); it++) {
        cout << it->first << "->";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
   
    create_First();
    cout <<endl<< "FIRST:" << endl<<endl;
    for (map<char, vector<char>>::iterator it = First.begin(); it != First.end(); it++) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }

    create_Follow();
    cout << endl << "FOLLOW:" << endl << endl;
    for (map<char, vector<char>>::iterator it = Follow.begin(); it != Follow.end(); it++) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }

    create_predict_table();
    cout << endl << "M[A,a]:"<<endl;
    cout << left<<setw(6)<<" ";
    for (int i = 0; i < terminal_num + 1; i++) {
        cout << setw(6) << terminal_temp[i];
    }
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < not_terminal_num; i++) {
        cout <<setw(6)<< notTerminal_temp[i];
        for (int j = 0; j < terminal_num+1; j++) {
            if (predict_table[i][j] == ":")
                cout << setw(6) << "ε";
            else
                cout << setw(6) << predict_table[i][j];
        }
        cout << endl;
    }
    cout << endl;
    anaysis("i+i*i");
}
