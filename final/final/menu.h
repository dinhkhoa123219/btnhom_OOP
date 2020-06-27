#pragma once
#include"Quiz.h"
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<time.h>
#include<ctime>
using namespace std;
#pragma warning(disable : 4996)
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
int TransAns(string a)
{
	if (a == "A" || a == "a")
		return 1;
	else if (a == "B" || a == "b")
		return 2;
	else if (a == "C" || a == "c")
		return 3;
	else
		return 4;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Menu()
{
BatDau:
	int x = 50, y = 23;
	system("cls");
	char kitu = 92;
	resizeConsole(1200, 600);
	SetConsoleTitleA("QUIZ");
	textcolor(10);
	string name1;
	string filename;
	int dem = 0;
	gotoxy(25, 9);  cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ";
	gotoxy(25, 10); cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
	gotoxy(25, 11); cout << "| |    ___       | || |  ___    ___  | || |     _____    | || |   ________   | || |   ________   | |";
	gotoxy(25, 12); cout << "| |  .'   '.     | || |  | |    | |  | || |    |_   _|   | || |  |  __   _|  | || |  |  __   _|  | |";
	gotoxy(25, 13); cout << "| | /  .-.  " << kitu << "    | || |  | |    | |  | || |      | |     | || |  |_/  / /    | || |  |_/  / /    | |";
	gotoxy(25, 14); cout << "| | | |   | |    | || |  | |    | |  | || |      | |     | || |     .'.' _   | || |     .'.' _   | |";
	gotoxy(25, 15); cout << "| | " << kitu << "  `-'  _    | || |  | |____| |  | || |     _| |_    | || |   _/ /__/ |  | || |   _/ /__/ |  | |";
	gotoxy(25, 16); cout << "| |  `.___." << kitu << "__|  | || |  |_|____|_|  | || |    |_____|   | || |  |________|  | || |  |________|  | |";
	gotoxy(25, 17); cout << "| |              | || |              | || |              | || |              | || |              | |";
	gotoxy(25, 18); cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
	gotoxy(25, 19); cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
	gotoxy(25, 22); cout << endl << endl;
//	int choose;
//ChooseFile:
//	cout << " Menu Test Exams : " << endl;
//	cout << " 1. Test 1 " << endl;
//	cout << " 2. Test 2 " << endl;
//	cout << " Choose file : ";
//	cin >> choose;
//	switch (choose)
//	{
//	case 1:
//		filename = "1.txt";
//		break;
//	case 2:
//		filename = "Test2.txt";
//		break;
//	default:
//		goto ChooseFile;
//	}

Enter_filename:
	cout << " Enter file name : " ;
	cin >> filename;
	ifstream fileInput(filename);
	if (fileInput.fail())
	{
		std::cout << " Failed to open this file, please retpye the filename !!" << endl;
		goto Enter_filename;
	}
	cin.ignore();
	Quiz Q = Quiz();
	Q.importFromFile(filename);
	int score_quizz = 0;
	double time_ans = 0;
	double time_end_quizz = Q.getDuration();
	cout << endl << endl;
	Q.printQuiz();
	cout << setw(14) << " Your full name : ";
	getline(cin, name1);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string time_bg = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	int sec = ltm->tm_sec;

	for (int i = 0; i < Q.list_Question.size(); i++)
	{
		cout << endl << endl;
		cout << "Question " << i + 1 << ": ";

		if (Q.list_Question[i].getType() == 0) //cau hoi 1 dap an
		{
			string get_ans_str;
			clock_t start;
			start = clock();
			clock_t end;
			cout << Q.list_Question[i] << endl;
		Enter_the_answer:
			cout << " Please tpye A or B or C or D to answer the question : ";
			cin >> get_ans_str;
			while (get_ans_str != "A" && get_ans_str != "B" && get_ans_str != "C" && get_ans_str != "D" && get_ans_str != "a" && get_ans_str != "b" && get_ans_str != "c" && get_ans_str != "d")
				goto Enter_the_answer;

			if (get_ans_str[0] >= 97 && get_ans_str[0] <= 100)
				get_ans_str[0] = get_ans_str[0] - 32;
			end = clock();
			time_ans = time_ans + (double)(end - start) / CLOCKS_PER_SEC;
			if (time_ans > Q.getDuration() * 60)
			{
				cout << " Time out." << endl;
				Sleep(1000);
				goto End_quizz;
			}
			if (get_ans_str[0] == Q.list_Question[i].CorrectChoice[0])
				switch (Q.list_Question[i].CorrectChoice[0])
				{
				case 'A': score_quizz += Q.list_Question[i].choice[0].getScore(); break;
				case 'B': score_quizz += Q.list_Question[i].choice[1].getScore(); break;
				case 'C': score_quizz += Q.list_Question[i].choice[2].getScore(); break;
				case 'D': score_quizz += Q.list_Question[i].choice[3].getScore(); break;
				default:
					break;
				}
			dem++;
		}
		else // cau hoi nhieu dap an
		{
			clock_t start1;
			start1 = clock();
			string ans1;
			cout << Q.list_Question[i] << endl;
			vector<char>Answer1;
		Enter_the_answer1:
			cout << " Please tpye A or B or C or D to answer the question : ";
			cin >> ans1;
			for (int j = 0; j < ans1.length(); j++)
			{
				if (ans1[j] >= 97 && ans1[j] <= 100)
					ans1[j] = ans1[j] - 32;
			}
			for (int j = 0; j < 4 && j < ans1.length(); j++)
			{
				for (int k = 0; k < Answer1.size(); k++)
					if (Answer1[k] == ans1[j])
						goto next;
				Answer1.push_back(ans1[j]);
			next: {}
			}
			int d = 0;
			for (int j = 0; j < Answer1.size(); j++)
			{
				for (int k = 0; k < Q.list_Question[i].CorrectChoice.size(); k++)
					if (Q.list_Question[i].CorrectChoice[k] == Answer1[j])
						d++;
			}
			if (d > 0 && Answer1.size() <= Q.list_Question[i].CorrectChoice.size())
			{
				for (int j = 0; j < Answer1.size(); j++)
					switch (Answer1[j])
					{
					case 'A': score_quizz += Q.list_Question[i].choice[0].getScore(); break;
					case 'B': score_quizz += Q.list_Question[i].choice[1].getScore(); break;
					case 'C': score_quizz += Q.list_Question[i].choice[2].getScore(); break;
					case 'D': score_quizz += Q.list_Question[i].choice[3].getScore(); break;
					default:
						break;
					}
			}
			clock_t end1;
			end1 = clock();
			time_ans = time_ans + (double)(end1 - start1) / CLOCKS_PER_SEC;
			if (time_ans > Q.getDuration() * 60)
			{
				cout << " Time out . You didn't complete the test ." << endl;
				Sleep(1000);
				goto End_quizz;
			}
			dem++;
		}

	}
	char key1;
End_quizz:
	time_t now1 = time(0);
	tm *ltm1 = localtime(&now1);
	string time_end = to_string(ltm1->tm_hour) + ":" + to_string(ltm1->tm_min) + ":" + to_string(ltm1->tm_sec);
	cout << endl << endl;
	cout << " *** Quiz result ***" << endl << endl;
	cout << " Quiz name : " + Q.getName() << endl << endl;
	cout << " Duration: " << Q.getDuration() << " (Minutes) " << endl << endl;
	cout << " Name of Student : " << name1 << endl;
	cout << " ---" << endl;
	cout << " Number of questions : " << Q.list_Question.size() << endl;
	cout << " Number of answered question: " << dem << endl;
	cout << " Total score : " << score_quizz << endl;
	cout << " Begin at : " << time_bg << endl;
	cout << " End at : " << time_end << endl;
	if (time_ans < 60)
		cout << " Total time : " << time_ans << " seconds" << endl;
	else
		cout << " Total time : " << time_ans / 60 << "(Minutes)" << endl;
	cout << " ---" << endl;
	cout << " Press ( R ) to retake the test. Press (S) to save your result .Press (E) to quit" << endl;
	cin >> key1;
	if (key1 == 'r' || key1 == 'R')
		goto BatDau;
	else if (key1 == 'e' || key1 == 'E')
		exit(0);
	else if (key1 == 's' || key1 == 'S')
	{
		string filesave = name1 + to_string(ltm1->tm_hour) + "-" + to_string(ltm1->tm_min) +"-"+ to_string(ltm1->tm_sec) +".txt";
		ofstream fileout(filesave);
		fileout << " *** Quiz result ***" << endl << endl;
		fileout << " Quiz name : " + Q.getName() << endl << endl;
		fileout << " Duration: " << Q.getDuration() << " (Minutes) " << endl << endl;
		fileout << " Name of Student : " << name1 << endl;
		fileout << " ---" << endl;
		fileout << " Number of questions : " << Q.list_Question.size() << endl;
		fileout << " Number of answered question: " << dem << endl;
		fileout << " Total score : " << score_quizz << endl;
		fileout << " Begin at : " << time_bg << endl;
		fileout << " End at : " << time_end << endl;
		if (time_ans < 60)
			fileout << " Total time : " << time_ans << " seconds" << endl;
		else
			fileout << " Total time : " << time_ans / 60 << "(Minutes)" << endl;
		fileout.close();
		cout << "Saved file !! . wait 3 seconds to quit program . " << endl;
		Sleep(3000);
		exit(0);
	}
}