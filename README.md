

# Animal Guessing Game

The Animal Guessing Game is a console-based game where the computer tries to guess an animal the player is thinking of by asking a series of yes or no questions. If the computer cannot guess the animal, it prompts the player to enter information about the new animal and uses this information to improve its guessing abilities in future games.

## Table of Contents
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Game Flow](#game-flow)
- [Updating the Animals File](#updating-the-animals-file)
- [Contributing](#contributing)
- [License](#license)

## Installation

To play the Animal Guessing Game, you will need to install the following:
- A C compiler (such as GCC or Clang)
- A console or terminal emulator

To install the Animal Guessing Game:
1. Clone this repository or download the source code as a ZIP file.
2. Compile the code using your preferred C compiler.
   - For example, if you are using GCC, run the following command in your terminal:
   ```
   gcc -o animal-guessing-game main.c structs.h game.h learn_new_information.h play_game.h start_game.h update_animals_and_questions.h
   ```
3. Run the compiled executable file (animal-guessing-game on Unix-like systems or animal-guessing-game.exe on Windows) in your console or terminal emulator.

## How to Play

1. Start the game by running the executable file.
2. Think of an animal and press enter to continue.
3. The computer will ask a series of yes or no questions to try to guess the animal.
4. If the computer correctly guesses the animal, it will prompt the player to play again or quit.
5. If the computer cannot guess the animal, it will prompt the player to enter information about the new animal.
6. After the player enters the information, the computer will update its database and prompt the player to play again or quit.

## Game Flow

The game flow is controlled by the following functions:

- `start_game`: This function initiates the game by calling the `play_game` function.

- `play_game`: This function asks the player yes or no questions to try to guess the animal. If the computer correctly guesses the animal, it will prompt the player to play again or quit. If the computer cannot guess the animal, it will prompt the player to enter information about the new animal.

- `learn_new_information`: This function prompts the player to enter information about the new animal and updates the linked list with the new information.

- `update_animals_and_questions`: This function writes the linked list to the Animals.txt file.

## Updating the Animals File

The Animals.txt file contains the animals and questions used by the game. To update the file, follow these steps:

1. Open the Animals.txt file in a text editor.
2. Add a new line for each animal in the following format: `Question?, Yes Answer, No Answer`
   - Replace "Question?" with a yes or no question that distinguishes the animal from the others.
   - Replace "Yes Answer" and "No Answer" with the name of the animal if the answer is "yes" or "no," respectively.
3. Save the file and exit the text editor.

## Contributing

Contributions to this project are welcome! To contribute, follow these steps:

1. Fork this repository.
2. Create a new branch with your changes: `git checkout -b my-feature-branch`
3. Commit your changes: `git commit -am 'Add new feature'`
4. Push your changes to your fork: `git push origin my-feature-branch`
5. Submit a pull request

## License

This code is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
