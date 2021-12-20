# ECE39595-Project-1

Zork Project for ECE 39595, Object-Oriented Programming in C++. 

Zork is a text-based game originating from the 1970's that puts a player into a dungeon with minimal information. The player solves puzzles and explores the dungeon to be able to exit and complete the game.<br>
For our implementation, we wrote it in C++, with the information about a dungeon stored in an XML file. Various objects in the XML file are created using C++ objects. <br>
The C++ XML parser uses TinyXml to parse the XML file. <br>

## Code Overview:
1. The XML parses reads the information from the XML file and creates objects for the physical and non-physical objects. 
2. Assign all physical and non-physical objects to the rooms they should inhabit. Instead of searching through a vector or list of items or containers, these now inhabit inside a room. 
3. Run a while loop that recieves commands from the player through the terminal. If the player exits the game using a command or completes the game naturally, quit the while loop. 
4. Unallocate all resources malloc'd by the initial setup of the game's objects. 

## Object Overview:
### Physical Objects
**Rooms**<br>
Rooms hold all physical objects that the player can directly interact with, and all non-physical triggers and conditions that create other effects. Rooms cannot hold other rooms.<br>

**Items**<br>
Items are things that the player can use to interact with other objects. <br>

**Containers**<br>
Containers hold items. <br>

**Creatures**<br>
Creatures are attackable objects that can hold items. <br>
### Non-Physical Conditions/Triggers
**Triggers**<br>
Triggers control if an action causes other things to happen other than what should happen. For instance, if the player tried walking forward but the room has a trigger that said if the player walked without a torch they would stumble and not be able to move, triggers describe that. <br>

**Conditions**<br>
Conditions control when triggers happen. Could be player-inputted actions, environmental changes or possession of an item, and the variables associated with all these things. <br>
## Commands:

