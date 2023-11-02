![Screenshot from 2023-11-02 16-49-38](https://github.com/reomelo/42Porto-so_long/assets/73884501/d2f82cf6-49bb-4e83-b8b8-cb3e635aedee)

### Description of the project:
This project consists on the creation of a simple 2D game using MiniLibx, receiving a map as parameter, parsing it and creating a mini game for the user to play. The game's objective is to grab all the collectibles, unlocking the exit and finishing the game. A map sample called `map.ber` is provided in the repository. Feel free to change the map the way you like it, but keep in mind that a **valid map** (read subject) must be in accordance to the following rules: 

	VALID CHARACTERS
 	'0': Floor;
	'1': Wall;
	'C': Collectible;
	'E': Exit;
	'P': Player's starting position;
 
 	RULES
	- Be in .ber format;  
	- Be closed by walls;  
	- Be retangular;  
	- Contain only one P;  
	- Contain only one E;  
	- Contain at least one C;  
	- All elements must be accessible (not closed by walls);  

 	[NOTE]: If any of the previous rules is not followed, error messages will be shown accordingly;

### Installing and running the project:
1- Clone this repository and enter it:  

	git clone https://github.com/reomelo/42Porto-so_long.git && cd 42Porto-so_long

2- Run `make` and execute `./so_long` with a valid map file:

	make && ./so_long map.ber

### Makefile Available Targets:  
`make` or `make all` - creates so_long.a      
`make clean` - wipes all object files   
`make fclean` - deletes so_long.a and all object files   
`make re` - fclean  + all

___
######  At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/42School/norminette). As a result, parts of the code are not as clean, efficient or straight forward as they could be.
