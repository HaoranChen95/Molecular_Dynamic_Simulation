#include "str_split.hpp"
using namespace std;

vector<string> str_split(const string& s, const char del){

	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while(getline(tokenStream, token, del)){
		tokens.push_back(token);
	}
	return tokens;
}

