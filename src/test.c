#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

#define ROWS 9
#define COLUMNS 9
#define ELEMENTS 9
#define BLOCKS 9

void print_arr(int *arr, int length);

int main () {
  int arr[9][9] = {
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
  int *columns[9];

  int column_0[9];
  int column_1[9];
  int column_2[9];
  int column_3[9];
  int column_4[9];
  int column_5[9];
  int column_6[9];
  int column_7[9];
  int column_8[9];

  create_column(9, 9, arr, column_0, 0);
  create_column(9, 9, arr, column_1, 1);
  create_column(9, 9, arr, column_2, 2);
  create_column(9, 9, arr, column_3, 3);
  create_column(9, 9, arr, column_4, 4);
  create_column(9, 9, arr, column_5, 5);
  create_column(9, 9, arr, column_6, 6);
  create_column(9, 9, arr, column_7, 7);
  create_column(9, 9, arr, column_8, 8);

  columns[0] = column_0;
  columns[1] = column_1;
  columns[2] = column_2;
  columns[3] = column_3;
  columns[4] = column_4;
  columns[5] = column_5;
  columns[6] = column_6;
  columns[7] = column_7;
  columns[8] = column_8;

  // create array of all blocks
  int *blocks[9];

  int block_00[9];
  int block_01[9];
  int block_02[9];
  int block_10[9];
  int block_11[9];
  int block_12[9];
  int block_20[9];
  int block_21[9];
  int block_22[9];

  create_block(9, 9, arr, block_00, 0, 0);
  create_block(9, 9, arr, block_01, 0, 1);
  create_block(9, 9, arr, block_02, 0, 2);
  create_block(9, 9, arr, block_10, 1, 0);
  create_block(9, 9, arr, block_11, 1, 1);
  create_block(9, 9, arr, block_12, 1, 2);
  create_block(9, 9, arr, block_20, 2, 0);
  create_block(9, 9, arr, block_21, 2, 1);
  create_block(9, 9, arr, block_22, 2, 2);

  blocks[0] = block_00;
  blocks[1] = block_01;
  blocks[2] = block_02;
  blocks[3] = block_10;
  blocks[4] = block_11;
  blocks[5] = block_12;
  blocks[6] = block_20;
  blocks[7] = block_21;
  blocks[8] = block_22;

  // 1. check if all numbers are valid
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (!is_valid_number(arr[i][j])) {
        printf("Error: %d is not a valid number (%d,%d)\n", arr[i][j], i, j);
        exit(0);
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    // 2. check if rows are valid
    if (!is_valid_section(arr[i], 9)) {
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

/*
  Print blocks and columns:

  print_arr(block_00, 9);
  print_arr(block_01, 9);
  print_arr(block_02, 9);
  print_arr(block_10, 9);
  print_arr(block_11, 9);
  print_arr(block_12, 9);
  print_arr(block_20, 9);
  print_arr(block_21, 9);
  print_arr(block_22, 9);
  printf("\n");
  print_arr(column_0, 9);
  print_arr(column_1, 9);
  print_arr(column_2, 9);
  print_arr(column_3, 9);
  print_arr(column_4, 9);
  print_arr(column_5, 9);
  print_arr(column_6, 9);
  print_arr(column_7, 9);
  print_arr(column_8, 9);
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
