#include"Choice.h"

Choice::Choice() 
{
	this->content = "";
	this->score = 0;
	this->order = 0;
}

Choice::Choice(string c , int s , int o)
{
	this->content = c;
	this->score = s;
	this->order = o;
}
string Choice::getContent()const
{
	return this->content;
}
int Choice::getScore()const
{
	return this->score;
}
int Choice::getOrder()const
{
	return this->order;
}
void Choice::setContent(string c)
{
	this->content = c;
}
void Choice::setScore(float s)
{
	this->score = s;
}
void Choice::setOrder(int o)
{
	this->order = o;
}
//ostream& operator << (ostream& out, const Choice& c)
//{	
//	out << c.content << endl;
//	return out;
//}
Choice::~Choice(){ }
