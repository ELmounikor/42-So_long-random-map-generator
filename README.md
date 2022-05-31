# 42-So_long-random-map-generator

As a fellow 1337/42 student, I had to manually write a 2D map to test my [So_long game]([url](https://github.com/ELmounikor/Ninja-Froggy-s-Treasure-Hunt)). 
We have to test it in different sizes and combinations which can be time consuming for all of us. 
This tool builds rectangular random maps that is customizable to everyone's use!

## How to use

After cloning the repo, run "make".

### Mandatory part map

if you just did the mondatory part you will want to run the following command:

    "./map_maker "10CEP" [number_of_rows] [number_of_columns] [file_name]"

    "10CEP" = map characters

    1 means walls 
    
    0 means empty space
    
    C as in collectables
    
    E as in exits
    
    P as in player

### Bonus part map

In case you did the bonus part you may want to run  the following command:

    "./map_maker "10CEMP" [number_of_rows] [number_of_columns] [number_of_monsters] [file_name]"

    "10CEP" = map characters

    1 means walls 
    
    0 means empty space
    
    C as in collectables
    
    E as in exits
    
    M as in monsters
    
    P as in player
    
You can change the map characters if you want to customize it to your project needs. Have fun with it!
PS: This tool does not check if there is a valid path for the player to win. I may build one soon ^^
