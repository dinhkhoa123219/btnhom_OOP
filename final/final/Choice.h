#pragma once
#include<Windows.h>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
class Choice
{
	string content;
	double score;
	int order;
public :
	Choice();
	Choice(string c , double s, int o );
	string getContent()const;
	double getScore()const;
	int getOrder()const;
	void setContent(string c);
	void setScore(double s);
	void setOrder(int o);
	~Choice();
};