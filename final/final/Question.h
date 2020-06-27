#pragma once
#include"Choice.h"
#include<vector>
class Question
{
	int type;
	string content;
public:
	vector<Choice>choice;
	vector<char>CorrectChoice;
	Question();
	Question(int t , string c);
	int getType()const;
	string getContent()const;
	void setType(int t);
	void setContent(string c);
	void addChoice(Choice c);
	void removeChoce(int i);
	void addCorrectChoice();
	void SortChoice() ;
	void update(int i, Choice c);
	friend ostream& operator << (ostream& out, const Question& c);
	friend istream& operator >> (istream& in, Question& c);
};
