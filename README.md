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
In Game Commands:<br>
n, s, e, w; movement commands to put the player in a different room. As you might have noticed from playing the sample game, once the player enters a room it doesn’t make any difference where in the room the player is – everything in the room is equally accessible from anywhere in the room.
If there is another room in the direction given by a movement command, the player will be moved to the room and a description of the new room will be printed to the screen. If there is not another room in the direction indicated, print Can’t go that way.<br><br>
i: short for inventory. This command print Inventor: and then lists all of the items in the player’s inventory, with items separated by commas if there is more than one. If there are no items in the inventory, display Inventory: empty.<br>
take <item>: Changes the ownership of the item named <item> from the room or container (e.g., a chest) it was contained in to the inventory of the player. If successful, print Item <item> added to the inventory. Hint: can be written as shortcut for the put command.<br>
open <container>: prints the contents of the container as <container> contains <item1>, ..., <itemn> , where <container> is the name of the container, and <item1>, ..., <itemn> is a comma separated list of the names of the items in the container. As well, the command makes the items available to be picked up using the take command. If the container is empty, the open <container> command will print <container> is empty.<br>
open exit: If a room is of type exit this command prints Game over and gracefully (i.e., no seg fault, etc.) ends the program.<br>
read <item>: If there is writing on an object, this command will print what is written, and otherwise will print Nothing written. The item must be in the players inventory. If it is not, then the command should say <item> not in inventory.<br>
drop <item>: Removes an item from the inventory and makes the room the player is in the owner of the item. The command should print <item> dropped. If the item is not in the inventory, print <item> not in inventory.<br>
put <item> in <container>: Removes <item> from the inventory and puts it in the container. The ownership of the item is given to <container>. <container> must be open, if not, print Cannot add <item> to closed <container>. Note that the inventory is a container, and is always open. If <item> is not in the inventory, print <item> not in inventory.<br>
turn on <item>: Activates <item> if it is in the inventory, otherwise print <item> not in inventory. The item is activated, and any turnon activities associated with <item> are executed.<br>
attack <creature> with <item>: prints You assault the <creature> with the <item>. For the command to be successful the item must match the creature (as specified in the .xml) and any existing conditions, also specified in the .xml, must be met. If successful, any attack elements associated with <creature> are executed.<br>
