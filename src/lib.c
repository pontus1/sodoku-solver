#include "lib.h"

#include <stdio.h>

/**
 * Create an array of numbers from block in soduku board
 *
 * @param r             number of rows in soduku board (9)
 * @param c             number of columns in soduku board (9)
 * @param from_arr      2d array to copy from (soduku board)
 * @param to_arr        array to copy to
 * @param b_r           block row (index of block row)
 * @param b_c           block column (index of block column)
 */
void create_block(int r, int c, int from_arr[r][c], int to_arr[r], int b_r, int b_c)
{
  int r_start = b_r * 3,
      r_stop = b_r * 3 + 3,
      c_start = b_c * 3,
      c_stop = b_c * 3 + 3,
      count = 0;

  for (int i = r_start; i < r_stop; i++)
    for (int j = c_start; j < c_stop; j++)
      to_arr[count++] = from_arr[i][j];
}

/**
 * Create an array of numbers from column in soduku board
 *
 * @param r             number of rows in soduku board (9)
 * @param c             number of columns in soduku board (9)
 * @param from_arr      2d array to copy from (soduku board)
 * @param to_arr        array to copy to
 * @param column        column index
 */
void create_column(int r, int c, int from_arr[r][c], int to_arr[c], int column)
{
  int count = 0;

  for (int i = 0; i < c; i++)
    to_arr[count++] = from_arr[i][column];
}

/**
 * Check if number is between 0 - 9
 *
 * @param  number       number to check
 * @return              0 or 1
 */
_Bool is_valid_number(int number)
{
  if (number >= 0 && number <= 9)
    return 1;
  return 0;
}

/**
 * Check if section only has unique values (0 counts as no value)
 *
 * @param  arr          section array to check (row, column or block)
 * @param  length       length of section (9)
 * @return              0 or 1
 */
_Bool is_valid_section(int *arr, int length)  // 81 loops
{
  // _Bool valid = 1;
  for (int i = 0; i < length; i++)
    for (int j = 0; j < length; j++)
      if (i != j && arr[i] != 0)
        if (arr[i] == arr[j])
          return 0;

  return 1;
}
