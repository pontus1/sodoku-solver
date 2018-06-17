#include "lib.h"

/**
 * Fill 2d array with numbers from columns in soduku board
 *
 * @param r             number of rows in soduku board (9)
 * @param c             number of columns in soduku board (9)
 * @param from_arr      2d array to copy from (soduku board)
 * @param to_arr        array to copy to
 */
void create_columns(int r, int c, int from_arr[r][c], int to_arr[r][c])
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      to_arr[i][j] = from_arr[j][i];
}

/**
 * Fill 2d array with numbers from blocks in soduku board
 *
 * @param r             number of rows in soduku board (9)
 * @param c             number of columns in soduku board (9)
 * @param from_arr      2d array to copy from (soduku board)
 * @param to_arr        array to copy to
 */
void create_blocks(int r, int c, int from_arr[r][c], int to_arr[r][c])
{
  int a = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      int r_start = i * 3,
          r_stop = i * 3 + 3,
          c_start = j * 3,
          c_stop = j * 3 + 3,
          b = 0;
      for (int k = r_start; k < r_stop; k++)
        for (int l = c_start; l < c_stop; l++) {
          to_arr[a][b++] = from_arr[k][l];
        }
        a++;
    }
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
