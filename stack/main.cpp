#include <iostream>
#include <string>

#include "verem.hpp"
#include "CannotPopFromStackException.hpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "hun");
	Verem verem;
	bool exit = false;
	string muvelet;
	string karakter = "";
	do
	{
		cout << "Betenni szeretn�l a verembe, vagy kivenni bel�le? (b/k/kil�p�s az Enter gomb megnyom�s�val)" << endl;
		getline(cin, muvelet);

		if (muvelet == "b")
		{
			cout << "Add meg a karaktert!" << endl;
			getline(cin, karakter);
			verem.push(karakter[0]);
		}
		else if (muvelet == "k") {
			if (verem.getList().empty())
				cout << "A verem �res.\n" << endl;
			else
			{
				cout << "Adjon meg egy sz�t: ";
				string szo;
				getline(cin, szo);
				try {
					verem.pop(szo);
				}
				catch (CannotPopFromStackException e) {
					cout << e.message << endl;
				}
			}
		}
		else if (muvelet == "")
			exit = true;
		else
			cout << "Helytelen karakter." << endl;

		if (verem.getList().empty())
			cout << "(Ell.: A verem m�g/m�r �res.)\n" << endl;
		else {
			cout << "(Ell.: A verem tartalma:\n" << endl;
			verem.printList();
			cout << ")" << endl;
		}
	} while (!exit);

	if (exit)
		cout << "Program v�ge." << endl;
	return 0;
}