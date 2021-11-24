#include "../lib/matrix_calc.h"

/**
 * \brief Definición de función para sumar matrices.
 */
void arr_matrix_adder (long double mat1[MAX_ROWS][MAX_COLS], long double mat2[MAX_ROWS][MAX_COLS], long double mat_res[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols)
{
    unsigned int count_rows, count_cols;

    for (count_rows = 0 ; count_rows < rows ; count_rows++)
        for (count_cols = 0 ; count_cols < cols ; count_cols++)
            mat_res[count_rows][count_cols] = mat1[count_rows][count_cols] + mat2[count_rows][count_cols];
}

/**
 * \brief Definición de función para encontrar la traspuesta de una matriz.
 */
void arr_matrix_transponser (long double mat1[MAX_ROWS][MAX_COLS], long double mat_res[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols)
{
    unsigned int cont_fil, cont_col;
    for (cont_fil = 0 ; cont_fil < rows ; cont_fil++)
        for (cont_col = 0 ; cont_col < cols ; cont_col++)
            mat_res[cont_col][cont_fil] = mat1[cont_fil][cont_col];
}
