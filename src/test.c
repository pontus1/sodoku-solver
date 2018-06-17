#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

#define ROWS 9
#define COLUMNS 9
#define ELEMENTS 9
#define BLOCKS 9

void print_arr(int *arr, int length);

int main () {

  /* CREATE */

  int sodoku_board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
  };

  // create array of all columns
  int columns[9][9];
  create_columns(9, 9, sodoku_board, columns);

  // create array of all blocks
  int blocks[9][9];
  create_blocks(9, 9, sodoku_board, blocks);

  printf("Rows: \n");
  for (int i = 0; i < 9; i++)
    print_arr(sodoku_board[i], 9);

  printf("Columns: \n");
  for (int i = 0; i < 9; i++)
    print_arr(columns[i], 9);

  printf("Blocks: \n");
  for (int i = 0; i < 9; i++)
    print_arr(blocks[i], 9);

  /* VALIDATE */

  // 1. check if all numbers are valid
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (!is_valid_number(sodoku_board[i][j])) {
        printf("Error: %d is not a valid number (%d,%d)\n", sodoku_board[i][j], i, j);
        exit(0);
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    // 2. check if rows are valid
    if (!is_valid_section(sodoku_board[i], 9)) {
      printf("Error: a number is used two times in row %d\n", i);
      exit(0);
    }
    // 3. check if columns are valid
    if (!is_valid_section(columns[i], 9)) {
      printf("Error: a number is used two times in column %d\n", i);
      exit(0);
    }
    // 4. check if blocks are valid
    if (!is_valid_section(blocks[i], 9)) {
      printf("Error: a number is used two times in block %d\n", i);
      exit(0);
    }
  }

  printf("Sodoku board is valid\n");

  return 0;
}

void print_arr(int *arr, int length) {
  for (int i = 0; i < length; i++)
    printf("[%d]", arr[i]);
  printf("\n");
}

/*
{5, 3, 0, 0, 7, 0, 0, 0, 0},
{6, 0, 0, 1, 9, 5, 0, 0, 0},
{0, 9, 8, 0, 0, 0, 0, 6, 0},
{8, 0, 0, 0, 6, 0, 0, 0, 3},
{4, 0, 0, 8, 0, 3, 0, 0, 1},
{7, 0, 0, 0, 2, 0, 0, 0, 6},
{0, 6, 0, 0, 0, 0, 2, 8, 0},
{0, 0, 0, 4, 1, 9, 0, 0, 5},
{0, 0, 0, 0, 8, 0, 0, 7, 9}
 */


// section = block || row || column;

// block_00 =   [0][0], [0][1], [0][2],
//              [1][0], [1][1], [1][2],
//              [2][0], [2][1], [2][2],
//
// block_01 =   [0][3], [0][4], [0][5],
//              [1][3], [1][4], [1][5],
//              [2][3], [2][4], [2][5],
//
// block_02 =   [0][6], [0][7], [0][8],
//              [1][6], [1][7], [1][8],
//              [2][6], [2][7], [2][8],
//
//
//
// block_10 =   [3][0], [3][1], [3][2],
//              [4][0], [4][1], [4][2],
//              [5][0], [5][1], [4][2],
//
// block_11 =   [3][3], [3][4], [3][5],
//              [4][3], [4][4], [4][5],
//              [5][3], [5][4], [5][5],
//
// block_12 =   [3][6], [3][7], [3][8],
//              [4][6], [4][7], [4][8],
//              [5][6], [5][7], [5][8],
//
//
//
// block_20 =   [6][0], [6][1], [6][2],
//              [7][0], [7][1], [7][2],
//              [8][0], [8][1], [8][2],
//
// block_21 =   [6][3], [6][4], [6][5],
//              [7][3], [7][4], [7][5],
//              [8][3], [8][4], [8][5],
//
// block_22 =   [6][6], [6][7], [6][8],
//              [7][6], [7][7], [7][8],
//              [8][6], [8][7], [8][8],
