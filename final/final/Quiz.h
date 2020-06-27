#pragma once
#include"Question.h"
#include<fstream>
class Quiz
{
	string name; 
	int duration;
public :
	Quiz();
	Quiz(string name , int duration );
	vector<Question>list_Question;
	~Quiz();
	void addQuesion(Question c);
	void removeQuestion(int i);
	void updateQuestion(int i, Question c);
	void setName(string name);
	void setDuration(int duration);
	string getName() const;
	int getDuration()const;
	void printQuiz();
	//void exportToFile(string filename);
	void importFromFile(string filename);
	void operator+(const Question& q)
	{
		list_Question.push_back(q);
	}
	void operator-(int i )
	{
		list_Question.erase(list_Question.begin() + i);
	}
	friend ostream& operator <<(ostream& out, const Quiz& q);
	friend istream& operator >>(istream& in, Quiz&q);
};
