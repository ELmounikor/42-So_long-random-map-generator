# 42-So_long-random-map-generator

As a fellow 1337/42 student, I had to manually write a 2D map to test my [So_long game](https://github.com/ELmounikor/Ninja-Froggy-s-Treasure-Hunt). 
We have to test it in different sizes and combinations which can be time consuming for all of us. 
This tool builds rectangular random valid maps that is customizable to everyone's use!

## How to use

After cloning the repo, run "make".

if you want to use the maze generator run "make maze"

### Mandatory part map

if you just did the mondatory part you will want to run the following command:

    ./map_maker "10CEP" [number_of_rows] [number_of_columns] [file_name]

"10CEP" = map characters

1 means walls 
    
0 means empty spaces
    
C as in collectables
    
E as in exits
    
P as in player

## how to use maze generator

	./maze_maker [length] [width] [nbr of coins] [file name]

you will find the map generated in the maps folder it is guaranteed to have a valid path.

have fun with it :D.


### Bonus part map

In case you did the bonus part you may want to run  the following command:

    ./map_maker "10CEMP" [number_of_rows] [number_of_columns] [number_of_monsters >= 1] [file_name]

"10CEMP" = map characters

1 means walls 
    
0 means empty spaces
    
C as in collectables
    
E as in exits
    
M as in monsters
    
P as in player

## Final word

You can change the map characters in order to customize it to your project needs, it only has to be a set of 5 or 6 characters. Have fun with it!

PS: This tool does not check if there is a valid path for the player to win but it may soon...
