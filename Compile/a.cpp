#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string buf = "";
int row = 1, col = 1;

vector<string> k = {"do", "for", "end", "if", "printf", "scanf", "then", "while"};
vector<string> s = {",", ";", "(", ")", "[", "]"};
vector<string> r = {"+", "-", "*", "/"};
vector<string> p = {"<", "<=", "=", ">", ">=", "<>"};

void print(int type) {
	cout << buf << " " << "(" << type << "," << buf << ")" << " ";
	cout << "(" << row << "," << col << ")" << endl;
	buf = "";
}

void print_err() {
	cout << buf << " " << "ERROR" << " " << "ERROR" << " ";
	cout << "(" << row << "," << col << ")" << endl;
	buf = "";
}

bool in(vector<string> v) {
	for (string ss : v) {
		if (ss == buf) return true;
	}
	return false;
}

int check() {
	if (buf.size() == 0) return 0;
	if (isalpha(buf[0])) {
		if (in(k)) return 1;
		else return 0;
	}
	if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/') return 4;
	if (in(r)) return 4;
	if (in(s)) return 2;
	if (!isdigit(buf[0]) && buf[0] != '<' && buf[0] != '>' && buf[0] != '=') return 7;
	return 0;
}

int check_end() {
	if (isdigit(buf[0])) {
		int len = buf.size();
		for (int i = 0; i < len; i ++) {
			if (!isdigit(buf[i])) return 0;
		}
		return 5;
	}
	if (isalpha(buf[0])) return 6;
	if (in(p)) return 3;
	return 0;
}

int main() {
	freopen("i.in", "r", stdin);
	char ch;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\n' || ch == '\r') {
			if (buf.size() == 0) continue;
			int type = check_end();
			if (type) print(check_end());
			else print_err();
		} 
		else {
			buf += ch;
			int type = check();
			if (type == 7) print_err();
			else if (type != 0) print(check());
		}
		if (ch == '\r' || ch == '\n') col = 1, row ++;
		else col ++;
	}
}

