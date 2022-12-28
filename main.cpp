#include <windows.h>
#include <winbase.h>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int getScreenWidth() {
	return GetSystemMetrics(SM_CXSCREEN);
}

int getScreenHeight() {
	return GetSystemMetrics(SM_CYSCREEN);
}

void runUntilStop(int screenWidth, int screenHeight) {
	char key;
	int asciiValue;
	int ms = 1000;
	int run = 1;

	cout << "Enter an interval, in which period the cursor should move (a value between 5000 and 10 is recommended): " << "\n";
	cin >> ms;

	cout << "\n" << "HOLD ESC to stop" << "\n"; 

	while (run == 1) {
		int randomX = rand() % screenWidth + 1;
		int randomY = rand() % screenHeight + 1;
		
		SetCursorPos(randomX, randomY);
		Sleep(ms);

		if (GetKeyState(VK_ESCAPE) & 0x8000) {
   	 		break;
		}
		
	}
}

void intro() {
	cout << R"(
		 _             _                       
		| | ___   __ _(_)  ___  ___ _ ____   __
		| |/ _ \ / _` | | / __|/ _ \ '__\ \ / /
		| | (_) | (_| | | \__ \  __/ |   \ V / 
		|_|\___/ \__, |_| |___/\___|_|    \_/  
				|___/                         

	)";

	// logi Serv

	cout << "\n\n\n" << "This program is an experiment. The developer is not responsible for any unintended use by the user." << "\n";
	cout << "\n" << "Copyright version 0.0.1";
	cout << "\n\n" << "The programs intention is NOT to fake the cursor on the screen while 'working'" << "\n\n\n";
	cout << "\n" << "How it works: Screen Timeout gets blocked by default. Additionally you can move the cursor." << "\n\n\n";
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
}

void runningProgram(int screenWidth, int screenHeight) {
	int screenSizeCorrect;
	int commandChoice = 1;

	cout << "First, we need to check your screen size. Is this your screens resolution?" << "\n" << "width: " << screenWidth << "\n" << "height: " << screenHeight << "\n"; 
	cout << "yes: 1" << ", no: 0" << "\n";

	cin >> screenSizeCorrect;

	if (screenSizeCorrect == 0) {
		cout << "\n" << "width: ";
		cin >> screenWidth;
		cout << "height: ";
		cin >> screenHeight;
		cout << "\n" << "new Screen resolution: " << screenWidth << " x " << screenHeight << "\n";
	}

	cout << "\n" << "note: letting the program move the cursor is NOT REQUIRED to keep the pc awake. You can simply run the program in the background." << "\n\n";

	cout << "command: " << "\n";
	cout << "1: set the cursor position until you stop it" << "\n";
	cin >> commandChoice;

	switch (commandChoice) {
		case 1:
			runUntilStop(screenWidth, screenHeight);
			break;
		case 2:
			// keepAwake();
			break;
		default:
			cout << "\n" << "Thank you for using cursorMoveR";
			break;
	}

}

int main() {
	SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED);

	intro();

	int screenWidth = getScreenWidth();
	int screenHeight = getScreenHeight();

	runningProgram(screenWidth, screenHeight);

	SetThreadExecutionState(ES_CONTINUOUS);

	return 0;
}