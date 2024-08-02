#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <vector>
#include <string>
#include "MyGame/MyGame.h"

// Functions prototype
DWORD WINAPI game_control(LPVOID lpParam);
void print_screen();
void user_operation();

// global variable
MyGame game;
const int game_time = 3; // game day <-> real secounds
int comand_number = -1;

int main()
{
	HANDLE threadHandle;
	DWORD threadId;
	threadHandle = CreateThread(nullptr, 0, game_control, nullptr, 0, &threadId);
	if (threadHandle == nullptr)
	{
		std::cerr << "Error creating thread." << std::endl;
		return 1;
	}

	user_operation();

	WaitForSingleObject(threadHandle, INFINITE);
	CloseHandle(threadHandle);
	return 0;
}

void print_screen()
{
	system("cls");
	game.print_resources_in_screen();
	game.print_day_in_screen();
	game.print_board_in_screen();
	std::cout << "\n:0: exit \n";
	std::cout << ":1: Buy Worker \n";
	std::cout << ":2: Resource Store \n";
	std::cout << ":3: Buy Soldier \n";
	std::cout << ":4: Move Soldier \n";
	std::cout << ":5: Resource Management \n";
}

DWORD WINAPI game_control(LPVOID lpParam)
{
	while (1)
	{
		sleep(game_time);
		game.run_day();
		game.change_day();

		if (comand_number == -1)
		{
			print_screen();
		}
	}
	return 0;
}

void user_operation()
{

	while (1)
	{
		// sleep(1);
		comand_number = -1;
		print_screen();
		std::cin >> comand_number;

		switch (comand_number)
		{
		case 0:
			game.~MyGame();
			exit(0);
			break;
		case 1:
			game.buy_worker();
			break;
		case 2:
			game.resource_store();
			break;
		case 3:
			game.buy_soldier();
			break;
		case 4:
			game.move_soldier();
			break;
		case 5:
			game.resource_management();
			break;
		}
	}
}
