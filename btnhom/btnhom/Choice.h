#pragma once
#include<iostream>
#include<string>
using namespace std;
class Choice
{
	string content;
	int score;
	int order;
public :
	Choice();
	Choice(string c , int s, int o );
	string getContent()const;
	int getScore()const;
	int getOrder()const;
	void setContent(string c);
	void setScore(float s);
	void setOrder(int o);
	~Choice();
};