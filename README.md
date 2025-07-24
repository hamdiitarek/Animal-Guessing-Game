
# Animal Guessing Game

A simple console-based animal guessing game written in C that learns from the player.

## How to Play

1. **Compile the game:**
   ```bash
   gcc -o animal_game main.c
   ```

2. **Run the game:**
   ```bash
   ./animal_game
   ```

3. **Game Flow:**
   - Start the game by running the executable file
   - Think of an animal and press Enter to continue
   - The computer will ask a series of yes or no questions to try to guess the animal
   - If the computer correctly guesses the animal, it will prompt you to play again or quit
   - If the computer cannot guess the animal, it will prompt you to enter information about the new animal
   - After you enter the information, the computer will update its database and prompt you to play again or quit

## Features

- **Learning System:** The game learns from incorrect guesses and builds a decision tree
- **Persistent Memory:** Animal data is saved to `Animals.txt` file
- **Interactive:** Simple yes/no question format
- **Replay Option:** Can play multiple rounds

## File Structure

- `main.c` - Main program entry point
- `Structs.h` - Data structure definitions
- `Play game.h` - Core game logic
- `Learn new information.h` - Learning system implementation
- `Load animals and questions.h` - File loading functionality
- `Update animals and questions.h` - File saving functionality
- `Start Game.h` - Game initialization
- `Animals.txt` - Database of animals and questions

## Example Session

```
Welcome to the Animal Guessing Game!
Think of an animal and press Enter to continue...

Is it a mammal? (yes/no): yes
Is it a Dog? (yes/no): no
I couldn't guess your animal.
What animal were you thinking of? Cat
What question would distinguish a Cat from a Dog?
(Please phrase as a yes/no question): Does it meow?
What would be the answer for a Cat? (yes/no): yes
Thank you! I've learned about the Cat.

Would you like to play again? (yes/no): no
Thanks for playing!
```

The game starts with basic knowledge and grows smarter as more people play!
