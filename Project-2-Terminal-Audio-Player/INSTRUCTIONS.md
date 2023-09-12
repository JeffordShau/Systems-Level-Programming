# How to Run Project

0) Make sure to have your terminal on full screen (otherwise you might encounter some bugs with the user interface)
1) Install   
`sudo apt-get install libncurses5-dev libncursesw5-dev`
2) Clone our repository:   
`git@github.com:stuyvesant-cs/project-iiits-the-final-project-4-chen-abedin-shau-lesserafim.git`  
3) cd into our repository:  
`cd project-iiits-the-final-project-4-chen-abedin-shau-lesserafim`
4) Type in `make` in the command line to compile and run program
5) To end the song early, press `ctrl + c`. 
6) Otherwise, follow the instructions on the screen as the program is running

# All Make (makefile) Options

- `make`: compiles and runs the program
- `make clear`: removes all compiled files 

# Working Features

- Select songs using arrowkeys on the terminal
- Song plays through pulseaudio or `paplay`
- Signal intercept `ctrl + c` to kill the process playing the song
- The duration of the song file is displayed
- The song duration progress bar is continously updated while the song is being played
- Once a song finishes playing or the user ends the song early, you can choose to play another song or exit the program


# Known Bugs in Final Version

- When selecting a song, we have two columns. This is not really a bug, it is from the demo given by ncurses.
- For the song duration progress bar, the progress bar displays 1 second left when the song is complete
- When the terminal size is too small, the song duration progress bar prints out a new line instead of updating the existing one. To avoid this, try to use a fullscreen terminal.
- Our 'Music Library' on the title screen only works properly on marge. When we try to test it on other lab computers, the ascii art doesn't display properly and a lot of our features become slow and buggy (e.g. you would have to press enter multiple times before a song gets selected). We believe it is something to do with the ncurses library but we couldn't figure out why exactly it didn't work on the other lab machines (even the ones with ncurses installed).



