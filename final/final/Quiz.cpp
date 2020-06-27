#include"Quiz.h"
#include<string>
int n;

Quiz::Quiz(string name , int duration )
{
	this->name = name;
	this->duration = duration;
}
Quiz::Quiz()
{
	this->name = " ";
	this->duration = 0;
}
Quiz::~Quiz() {};

void Quiz::addQuesion(Question c)
{
	list_Question.push_back(c);
}
void Quiz::removeQuestion(int i)
{
	list_Question.erase(list_Question.begin() + i);
}
void Quiz::updateQuestion(int i, Question c)
{
	list_Question[i] = c;
}
void Quiz::setName(string name)
{
	this->name = name;
}
void Quiz::setDuration(int duration)
{
	this->duration = duration;
}
int Quiz::getDuration()const
{
	return this->duration;
}
string Quiz::getName()const
{
	return this->name;
}
ostream& operator << (ostream& out, const Quiz& q)
{	
	out << " *** Welcome to the Quiz ***" << endl;
	out << " Name : " << q.name << endl;
	out << " Duration: "<<q.duration<<" minutes." << endl;
	for (int i = 0; i < q.list_Question.size(); i++)
	{
		string ans;
		out << q.list_Question[i] << endl;
	}
	return out;
}
void Quiz::printQuiz()
{
    cout << " *** Welcome to the Quiz ***" << endl;
	cout  <<" Name : " << this->name << endl;
	cout  <<" Duration: " << this->duration << " minutes." << endl;
}
istream& operator >>(istream& in, Quiz& q) {
	cout << " Nhap ten Bai quiz : ";
	in >> q.name;
	cout << " Nhap Thoi gian lam bai :";
	in >> q.duration;
	cin.ignore();
	cout << " Nhap so luong cau hoi" << endl;
	int n;
	cin >> n;
	while (n == 0) {
		Question temp;
		cin >> temp;
		q.addQuesion(temp);
		n--;
	}
	return in;
}
//void Quiz::exportToFile(string filename)
//{	
//	fstream file(filename, ios::out | ios::app);
//	file << "Name :" << endl << this->name << endl;
//	file << "Duration:" << endl << this->duration << endl;
//
//	file << "Cau hoi:" << endl;
//
//	for (int i = 0; i < list_Question.size(); i++) {
//		file << "Cau " << i << endl;
//		file << list_Question[i].getContent << endl;
//	}
//
//	file << "END!";
//}

void Quiz::importFromFile(string filename)
{

	ifstream fileInput(filename);
	getline(fileInput, this->name,'-');
	fileInput >> this->duration;
	fileInput >> n;
	for (int i = 0; i < n; i++)
	{
		string questionType, questionContent;
		getline(fileInput,questionType,'-');
		getline(fileInput,questionContent);
		int qT = atoi(questionType.c_str());
		Question q = Question(qT, questionContent);
		for(int i = 0 ;i<4;i++)
		{
		string choiceContent,choiceScore,choiceOrder;
		getline(fileInput, choiceContent,'-');
		getline(fileInput, choiceScore,'-');
		getline(fileInput, choiceOrder);
		double cS = atoi(choiceScore.c_str());
		int cO = atoi(choiceOrder.c_str());
		Choice c = Choice(choiceContent, cS, cO);
		q.choice.push_back(c);
		}
		q.SortChoice();
		q.addCorrectChoice();
		list_Question.push_back(q);
	}
	fileInput.close();
}
