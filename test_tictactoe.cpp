#include <cassert>
#include <iostream>
#include "TicTacToe.h"

// Test 1: Check new game state
void test_initial_state() {
    TicTacToe game;

    // X always starts
    assert(game.getCurrentPlayer() == 'X');

    // No moves made yet
    assert(game.getMoveCount() == 0);

    // Board should be empty
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            assert(game.getCell(r, c) == ' ');
        }
    }

    // Game isn't over
    assert(!game.isGameOver());

    std::cout << "✓ Initial state looks good\n";
}
// Test 2: Make a valid move
void test_valid_move() {
    TicTacToe game;

    bool success = game.makeMove(0, 0);
    assert(success); // Move should work

    // Check cell update
    assert(game.getCell(0, 0) == 'X');

    // Player should switch
    assert(game.getCurrentPlayer() == 'O');

    // Move count should be 1
    assert(game.getMoveCount() == 1);

    std::cout << "✓ Valid move works\n";
}

// Test 3: Invalid moves
void test_invalid_moves() {
    TicTacToe game;

    game.makeMove(0, 0);

    // Same spot
    assert(!game.makeMove(0, 0));

    // Out of bounds
    assert(!game.makeMove(-1, 0));
    assert(!game.makeMove(0, -1));
    assert(!game.makeMove(3, 0));
    assert(!game.makeMove(0, 5));

    // Finish game and try move after game over
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X wins

    assert(game.isGameOver());
    assert(!game.makeMove(2, 2));

    std::cout << "✓ Invalid moves rejected correctly\n";
}

// Test 4: Winner by row
void test_winner_detection_row() {
    TicTacToe game;

    game.makeMove(0, 0); // X
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X wins

    assert(game.getWinner() == 'X');
    assert(game.isGameOver());

    std::cout << "✓ Row winner detected\n";
}

// Test 5: Winner by column
void test_winner_detection_column() {
    TicTacToe game;

    game.makeMove(1, 1); // X
    game.makeMove(0, 0); // O
    game.makeMove(2, 2); // X
    game.makeMove(1, 0); // O
    game.makeMove(0, 2); // X
    game.makeMove(2, 0); // O wins

    assert(game.getWinner() == 'O');
    assert(game.isGameOver());

    std::cout << "✓ Column winner detected\n";
}

// Test 6: Winner by diagonal
void test_winner_detection_diagonal() {
    TicTacToe game;

    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(1, 1); // X
    game.makeMove(0, 2); // O
    game.makeMove(2, 2); // X wins

    assert(game.getWinner() == 'X');
    assert(game.isGameOver());

    std::cout << "✓ Diagonal winner detected\n";
}

// Test 7: Full board, tie game
void test_full_board_no_winner() {
    TicTacToe game;

    // Fill board with no winner
    game.makeMove(0,0); // X
    game.makeMove(0,1); // O
    game.makeMove(0,2); // X
    game.makeMove(1,0); // O
    game.makeMove(1,2); // X
    game.makeMove(1,1); // O
    game.makeMove(2,1); // X
    game.makeMove(2,0); // O
    game.makeMove(2,2); // X

    assert(game.getWinner() == ' ');
    assert(game.isGameOver());
    assert(game.isFull());

    std::cout << "✓ Tie game detected\n";
}

// Run all tests
int main() {
    std::cout << "Running Tic-Tac-Toe tests...\n\n";

    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();

    std::cout << "\nAll tests passed! Great job.\n";
    return 0;
}
