### 01-06-23 to 01-08-23

Jefford, Nakib, David:

- Updated our proposal to approved idea, added in suggestions

### 01-09-23

- Received approval for our proposal

Nakib:

- Copy over base code from project 1
- Remove unnecessary code
- Setup standard in to let user pick a song to play

Jefford:

- Started with main.c
- Added outline of main.c in comments

### 01-10-23

David:

- Updated research roles in readme
- Setup arrow selection to pick the song to play from the menu using ncurses and menus included in ncurses
- Linked ncurses library to allow menu selection of songs
- Implemented ascii art using figlet
- Added some fire kpop songs

Nakib:

- Init music folder
- Start basic functionality for musicPlayer

Jefford:

- Out sick

### 01-11-23

David:

- Return proper type in arrow selection function
- Started fix on stack smashing bug

Nakib:

- Work on signal handling
- When user plays song, store time in txt file or shared memory
- When user ends a song, find current time, subtract the time from the shared memory
- The difference will be the total time elapsed

Jefford:

- Looked into mp3 music players for two hours
- Possible to use execvp() through Rhythmbox command line prompts
- Rhythmbox-client --help, --enqueue, --clear-enqueue, --play, --stop, --play-pause, --next
- Started working on music file player functionality using Rhythmbox

### 01-12-23

Jefford:

- In class decided to use libmpg123 and libao to play music files on terminal
- Updated Readme roles.
- Did further research on libao and libmpg123 functionality and features
- Spent time fixing bug "unknown libao driver" with installation of library on personal computer

Nakib:

- Attempt to fix bug with ncurses installation
- On my mac, for some reason the code doesn't properly compile and returns an error with the file where ncurses.h was used. I've been trying to fix the issue. Still haven't been able to fix it, will most likely attmept to work around this by working on the project via ssh from lab machine
- Work on leaderboard functionality skeleton. Will store the best scores in a shared memory and will sort the score after each update
- Might switch to using other files instead of shared memory to make it easier to associate a user with their respective score

### 01-13-23

David:

- Figured out we can use paplay instead mpg123 to play music

Nakib:

- Switched up design for leaderboard: use a 2D array where the first column stores all of the high scores and the second column stores the machineID of the user
- Attempted to fix ncurses installation again

Jefford:

- Debugged pulseaudio play on windows "permission denied"
- Updated perimssions in 'etc/pulse' and edited default.pa and daemon.conf to link pulseaudio with computer audio
- After two hours realized I had to sudo chmod instead of chmod

### 01-14-23

Nakib:

- Worked on implementation for sorting the leaderboard after a new entry has been added. Initially used bubblesort, then attempted to try to use the inbuild qsort() command, then went back to bubble sort because using qsort() on a 2D array got very messy

### 01-15-23

David:

- Finally fixed stack smashing bug and use new menu implementation to return songs to play
- Customized menu background, foreground, and text color
- Also made array size for choices dynamic so it's not limited to 20 songs
- Linked musicPlayer to main

Nakib:

- Rewrote the music player method using execl and with paplay

Jefford, Nakib:

- Worked in liveshare session together
- Implemented while loop to select another song to play after a song finishes playing in main
- Began implementing signal handler for Ctrl+C while a song is playing

### 01-16-23

Nakib:

- Finished signal handling mechanisms --> enables user to terminate song early. Used shared memory to keep track of the child that is playing the song and used SIGTERM to end the song early
- Fixed issues with the while loop to play next song. Now the UI is better and the user can either exit by pressing x when prompted or by using cntl + c
- Made it so that the program can accurately detect when the song ends.
- Removed unneccesary files and code
- Came up with plan to work out how to retrieve metadata

David:

- Added new wav header in `musicPlayer.h` to properly parse wav files and metadata about the wav file
- Added new function to return total duration of song in `musicPlayer.c`
- Use zero padding to make sure that the song duration is always 6 characters long
- Clean up some files
- Fixed bug that makes terminal screen messed up on rerun of program
- Added new bar to show progress of song playing by using fork and non blocking waitpid to continue to actually play the song while also updating the progress bar
- Added a new block ASCII character to better emulate a progress bar
- Spinning wheel ASCII art to show that the program is running while the song is playing
- Fixed some bugs with segfaults
- I also don't know why my commits just now are showing up as committed three days ago
- Fixed infinite loop if enter key is not pressed on first run of program
- Fixed progress bar still playing after song is done by forking it before waitpid

Jefford:

- Fixed main.c file warning by using parse() and songSearch()
- Fixed getDuration warnings
- Imported trimmed audio files (.wav) to shorten the fileSize from YouTube through Clideo online application

Nakib, Jefford:

- Worked with Jefford on a liveshare to debug segfault that came up with playing music (there was an issue with filenames and using strsep)
- Realized bugs were because of our system after testing on marge
- Fixed some issues with exiting program and playing a new song after current song terminates to make the program run cleaner.
- Carried out final testing on marge

### 01/17/23

Nakib, Jefford:

- Updated INSTRUCTIONS.md