#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "XMLParser.h"
#include "player.h"
#include "commands.h"

bool gameOver = false;

int main(int argc, char** args) {
	// prompt for XML file to parse
	std::string filename;
	bool shouldPause = true;

	// if given a second argument, use that as the XML file
	// means calling "XMLParseDemo studentActivity.xml" will parse the file "studentActivity.xml". The Makefile is set up to supply this argument when using on command line
	if (argc >= 2) {
		filename = args[1];
		shouldPause = false;
	}
	else {
		// if no argument, prompt for filename. This is the form used in running in Visual Studio
		std::cout << "Enter filename: ";
		std::cin >> filename;
		// remove the extra newline character from cin
		std::cin.get();
	}

	// call the parser to parse the XML
	Room* junkyard = new Room();
	std::vector<Room*> rooms = loadXMLFile(filename, junkyard);

	 // room to store all the things that were deleted, except for Rooms

	// print all results
	/*
	std::cout << "Found " << rooms.size() << " rooms: " << std::endl;
	for(Room* room : rooms){
		cout<<'\t'<<room -> getName()<<endl;
		cout<<"\tDescription: "<<room -> getDesc()<<endl;
	}
	*/
	bool exit = false;
	std::string input;
	Player* player = new Player();
	player->setRoom(rooms.front());
	cout << player->getRoom()->getDesc() << endl;
	while (exit != true)
	{
		if (gameOver)
		{
			exit = true;
		}
		getline(cin,input);
		exit = whichCommand(input, player, rooms, junkyard);
		if (gameOver)
		{
			exit = true;
		}
	}
	cout << "Game over" << endl;

	// free memory
	for (Room* room : rooms) {
		delete room;
	}
	delete junkyard;
	rooms.clear(); // not strictly required, I just like to remove references to pointers after deleting them

	// wait for key press to exit, added for the sake of visual studio as the command window closes after the program finishes
	// skipped when a filename is given via command line, that is what the makefile is set up to use
	// worth pointing out that this is not strictly related to XML parsing, it is just done to make testing the program easier
	if (shouldPause) std::cin.get();

	return 0;
}