/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // Prints out the state of the game:
  cout << *this << endl;
  // @TODO -- Finish solving the game!

  // Attempt 2
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  Cube yellow(1, uiuc::HSLAPixel::YELLOW);

  int remove_order[] = {0, 0, 1, 0, 2, 2, 0, 0, 1, 1, 2, 1, 0, 0, 1};
  int push_back_stack[] = {1, 2, 2, 1, 0, 1, 1, 2, 2, 0, 0, 2, 1, 2, 2};
  char* push_back_target[15] = {"y", "p", "y", "o", "y", "p", "y", "b", "y", "p", "y", "o", "y", "p", "y"};

  for (int i = 0; i < remove_order.size(); i++) {
    Cube target;
    if (push_back_target[i] == "y") {
        target = yellow;
    } else if (push_back_target[i] == "p") {
        target = purple;
    } else if (push_back_target[i] == "o") {
        target = orange;
    } else if (push_back_target[i] == "b") {
        target = blue;
    }

    stacks_[remove_order[i]].removeTop();
    stacks_[push_back_stack[i]].push_back(push_back_target[i]);
    cout << *this << endl;
  }

//  // Attempt #1 - Manual
//  // ORDER
//  // Move the yellow to stack 1
//
//  stacks_[0].removeTop();
//  stacks_[1].push_back(yellow);
//
//  // Move the purple to stack 2
//  stacks_[0].removeTop();
//  stacks_[2].push_back(purple);
//
//  // Move the yellow to stack 2
//  stacks_[1].removeTop();
//  stacks_[2].push_back(yellow);
//
//  // Move the orange to stack 1
//  stacks_[0].removeTop();
//  stacks_[1].push_back(orange);
//
//  // Move the yellow from stack 2 to stack 0
//  stacks_[2].removeTop();
//  stacks_[0].push_back(yellow);
//
//  // Move the purple to from 2 to 1
//  stacks_[2].removeTop();
//  stacks_[1].push_back(purple);
//
//  // Move yellow from 0 to 1
//  stacks_[0].removeTop();
//  stacks_[1].push_back(yellow);
//
//  // Move blue to stack 2
//  stacks_[0].removeTop();
//  stacks_[2].push_back(blue);
//
//  // === Biggest one at stack 2
//
//  // move yellow from 1 to 2
//  stacks_[1].removeTop();
//  stacks_[2].push_back(yellow);
//
//  // move purple from 1 to 0
//  stacks_[1].removeTop();
//  stacks_[0].push_back(purple);
//
//  // move yellow from 2 to 0
//  stacks_[2].removeTop();
//  stacks_[0].push_back(yellow);
//
//  // move orange from 1 to 2
//  stacks_[1].removeTop();
//  stacks_[2].push_back(orange);
//
//  // === Bottom two complete
//
//  // move yellow from 0 to 1
//  stacks_[0].removeTop();
//  stacks_[1].push_back(yellow);
//
//  // move purple from 0 to 2
//  stacks_[0].removeTop();
//  stacks_[2].push_back(purple);
//
//  // move yellow from 1 to 2
//  stacks_[1].removeTop();
//  stacks_[2].push_back(yellow);
}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
