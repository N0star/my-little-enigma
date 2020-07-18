# My Little Enigma

Simple encryption program, that uses four gears to switch letters.

## Functions

- encode a message and save it into a file
- decode a message and show the results
- decode a message and save it into a file
- it does not however encode files.

## Usage

1. **E - creates a new encoded file:**
  - the first prompt asks for the new file's name
    - in case it's already taken, the program asks if continue anyway
    - the old file will be overwritten if proceed (by typing **t**)
  - then it asks to set four coding gears
    - each has a different size indicated by the number in brackets
    - user is supposed to give a number from 0 to *n*
    - however, it works even with greater numbers, by taking a mod from them
  - after that, the program asks if the setting is correct
    - in case of any mistakes, (**t** for yes, **n** for no)
  - the next prompt is a field to write a message to encode
    - it's 500 signs max, but after each *Enter* the limit resets
    - it's an infinite loop, to break it "ZAK" needs to be typed
    - it only works however at the beginning of the input
  - finally, the program puts encoded message in a file and ends
2. **W - reads an already existing encrypted file:**
  - the first prompt asks for the encrypted file's name
    - if the file doesn't exist, the program will quit
  - then it asks to set four coding gears
    - each has a different size indicated by the number in brackets
    - user is supposed to give a number from 0 to *n*
    - however, it works even with greater numbers, by taking a mod from them
  - after that, the program asks if the setting is correct
    - in case of any mistakes, (**t** for yes, **n** for no)
  - then the program asks if save the results or just show them on a screen
    - the results can be saved later regardless
    - it cannot be however showed after choosing to save
    - **s** is for save, and **d** for a just show (and maybe save later)
  - if a showing is chosen, the decoded message should be seen on a screen
  - then the program asks again if save the showed results
    - **t** for yes, **n** for no, and if yes the new file's name needs to be provided
    - and if the name is already taken, the program will warn about it
    - **WARNING:** do not use the same name as the encrypted file or it'll make it blank!
  
3. **Q - terminates the program, instantly.**

## Examples

In the folder *exe*, beside an executable file, there are examples of encoded messages.
- to decode them gears need to be set according to corresponding files' names.
