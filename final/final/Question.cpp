#include "Question.h"

Question::Question() {
	this->type = 0;
	this->content = " ";
}
Question::Question(int t, string c)
{
	this->type = t;
	this->content = c;
}
void Question::SortChoice()
{
	for (int i = 0; i < choice.size() - 1; i++)
	{
		for (int j = i + 1; j < choice.size(); j++)
		{
			if (choice[i].getOrder() > choice[j].getOrder())
			{
				Choice temp = choice[i];
				choice[i] = choice[j];
				choice[j] = temp;
			}
		}
	}
}
int Question::getType()const
{
	return this->type;
}
string Question::getContent() const
{
	return this->content;
}
void Question::setType(int t)
{
	this->type = t;
}
void Question::setContent(string c)
{
	this->content = c;
}
void Question::addChoice(Choice c)
{
	choice.push_back(c);
}
void Question::removeChoce(int i)
{
	choice.erase(choice.begin() + i);
}
void Question::update(int i, Choice c)
{

	choice[i] = c;
}

ostream& operator << (ostream& out, const Question& c)
{
	if (c.type == 0)
	{
		out << c.content << " (The question has 1 answers)  " << endl;
		for (int i = 0; i < c.choice.size(); i++)
		{
			out << " " << c.choice[i].getContent() << endl;
		}
		return out;
	}
	else
	{
		out << c.content << " (The question has many answers)" << endl;
		for (int i = 0; i < c.choice.size(); i++)
		{
			out << " " << c.choice[i].getContent() << endl;
		}
		return out;
	}
}

istream& operator >> (istream& in, Question& c)
{
	cout << "nhap noi dung cau hoi:";
	in >> c.content;
	cout << "nhap type question:";
	in >> c.type;
	return in;
}
void Question::addCorrectChoice()
{
	for (int i = 0; i < choice.size(); i++)
	{
		if (choice[i].getScore() > 0)
		{
			if (choice[i].getOrder() == 1)
				CorrectChoice.push_back('A');
			else if (choice[i].getOrder() == 2)
				CorrectChoice.push_back('B');
			else if (choice[i].getOrder() == 3)
				CorrectChoice.push_back('C');
			else
				CorrectChoice.push_back('D');
		}
	}
}

