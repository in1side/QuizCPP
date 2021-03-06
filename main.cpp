// CPPQuiz.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <random>

using namespace std;

struct Question {

	string question;
	string answers[5];

	int difficulty;
	int score;

};

int main()
{
	Question q;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 10);

	char answer;
	int total_score(0);

	q.question = "What is C++?";

	q.answers[0] = "Language";
	q.answers[1] = "Tool";
	q.answers[2] = "Program";
	q.answers[3] = "Game";
	q.answers[4] = "A";

	q.difficulty = 3;
	q.score = q.difficulty + dist(gen) / 2;

	cout << "Question: " << q.question << endl;
	cout << "Difficulty:" << q.difficulty << endl;
	cout << "Score: " << q.score << "\n\n";
	
	for (size_t i = 0; i < 4; i++) {
		switch (i + 1) {
			case 1:
				cout << "A) " << q.answers[i] << endl;
				break;
			case 2:
				cout << "B) " << q.answers[i] << endl;
				break;
			case 3:
				cout << "C) " << q.answers[i] << endl;
				break;
			case 4:
				cout << "D) " << q.answers[i] << endl;
				break;
		}
	}

	cout << "\n\nYour answer:";
	cin >> answer;

	if (!cin) {

		cout << "\n\nInvalid input\n\nProgram will now exit...\n\n";
		exit(EXIT_FAILURE);

	} else if(toupper(answer) == q.answers[4].at(0)) {

		cout << "\n\nThat is correct! +" << q.score << " points\n";
		total_score += q.score;

		cout << "Your total score so far is " << total_score << " points!\n";
	} else {

		cout << "\n\nNope! Your answer is " << static_cast<char> (toupper(answer)) << ") and the correct one is " << static_cast<char> (toupper(q.answers[4].at(0))) << ").\n";
		cout << "\nNo problem! Next question!\n";
		
	}


    return 0;
}

