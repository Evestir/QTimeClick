#define _ALLOW_KEYWORD_MACROS
#define nullptr __nullptr
#include "QuickTime.h"
#include <thread>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <conio.h>
#undef nullptr


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

std::time_t cTimeT;
std::tm* cuTime;

void convertTimeFormats() {
	if (QTimeClick::TargetH_n == 24) {
		QTimeClick::TargetH_n = 0;
	}
	else if (QTimeClick::TargetH_n == -1) {
		QTimeClick::TargetH_n = 23;
	}
	if (QTimeClick::TargetM_n == 60) {
		QTimeClick::TargetM_n = 0;
	}
	else if (QTimeClick::TargetM_n == -1) {
		QTimeClick::TargetM_n = 59;
	}
	if (QTimeClick::TargetS_n == 60) {
		QTimeClick::TargetS_n = 0;
	}
	else if (QTimeClick::TargetS_n == -1) {
		QTimeClick::TargetS_n = 59;
	}
}

void waitForTime() {
	/*AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "Starting Debugging." << std::endl;*/
	while (true) {
		if (QTimeClick::starto) {
			convertTimeFormats();

			cTimeT = std::time(0);   // get time now
			cuTime = std::localtime(&cTimeT);

			/*std::cout << "Current Time: " << cuTime->tm_hour << " ";
			std::cout << cuTime->tm_min << " ";
			std::cout << cuTime->tm_sec << " ";

			std::cout << " Set Time: " << QTimeClick::TargetH_n << " ";
			std::cout << QTimeClick::TargetM_n << " ";
			std::cout << QTimeClick::TargetS_n << " ";*/

			auto timeMillis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
			float b = 10000;

			float a = timeMillis / b;

			int currentMili = timeMillis - ((int)a) * 10000;
			while (!(currentMili < 1000)) {
				currentMili -= 1000;
			}
			/*std::cout << currentMili << std::endl;*/

			if ((cuTime->tm_hour == QTimeClick::TargetH_n) && (cuTime->tm_min == QTimeClick::TargetM_n) && (cuTime->tm_sec == QTimeClick::TargetS_n - 1) && (currentMili >= 1001 - QTimeClick::pTtG)) {
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				QTimeClick::starto = false;
				QTimeClick::QuickTime::TheInstance->Notification->Text = "Successfully simulated left mouse click at " + (QTimeClick::TargetH).ToString() + ":" + (QTimeClick::TargetM).ToString() + ":" + (QTimeClick::TargetS).ToString() + ":" + (currentMili).ToString();
			}
		}
		else {
			Sleep(2000);
		}
	}
}

void main(array<String^>^ args) {
	std::thread FuckedUpBro(waitForTime);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	QTimeClick::QuickTime form;
	Application::Run(% form);
}