#include "../lib/matrix_calc.h"


matrix_base::matrix_base () : row_size(0), col_size(0)
{
//    cout << "constructor base class\n";
}
matrix_base::matrix_base (int fila, int columna) : row_size(fila), col_size(columna)
{
 //   cout << "constructor base class with arguments\n";
}
matrix_base::matrix_base ( const matrix_base &mat)
{
//   cout << "constructor copy \n";    
    unsigned int count_row, count_col;
    for (count_row = 0; count_row < mat.row_size; count_row++)
        for (count_col = 0; count_col < mat.col_size; count_col++)
            matrix[count_row][count_col] = mat.matrix[count_row][count_col];
}

matrix_base::~matrix_base()
{
 //   cout << "destructor base class\n";
}
void matrix_base::set_matrix_size ()
{
    if ( row_size == 0 && col_size == 0 )
    {
        do{
            cout << "ingrese la cantidad de filas: ";
            cin >> row_size;
            cout << endl << "ingrese la cantidad de columnas: ";
            cin >> col_size;
            if (row_size > MAX_ROWS && col_size > MAX_COLS)
                cout << "el tamaño máximo de filas es " << MAX_ROWS << " y de columnas es " << MAX_COLS
                << endl <<"¡inténtelo nuevamente!"  << endl;
        }while (row_size > MAX_ROWS && col_size > MAX_COLS);
    }
}

void matrix_base::set_matrix_values ()
{
    unsigned int cont_fil, cont_col;

    for (cont_fil = 0 ; cont_fil < row_size ; cont_fil++)
        for (cont_col = 0 ; cont_col < col_size ; cont_col++)
        {
            cout << "Ingrese el valor de la matriz en la posición [ " << cont_fil 
            << " , " << cont_col << " ] :";
            cin >> matrix[cont_fil][cont_col];
        }
}

void matrix_base::print_matrix_size ()
{
    cout << "La cantidad de filas de la matriz es: " << row_size << endl;
    cout << "La cantidad de columnnas de la matriz es: " << col_size << endl;
}

void matrix_base::print_matrix ()
{
    unsigned int cont_fil, cont_col;

    for (cont_fil = 0 ; cont_fil < row_size ; cont_fil++)
    {    
        cout << endl << "|\t";
        for (cont_col = 0 ; cont_col < col_size ; cont_col++)
            cout << matrix[cont_fil][cont_col] << "\t";
        cout << "|";
    }
    cout << endl << "\n";
}

bool matrix_base::get_type ()    //falta usar esto para validar
{
    if (row_size == col_size)
        return 1; //cuadrada
    else
        return 0;
}

/**
 * @brief 
 * 
 * 
 */

matrix_calcs::matrix_calcs()
{
//   cout << "constructor derived class\n";
}

matrix_calcs::matrix_calcs(int fil, int col) : matrix_base ( fil, col)
{
//   cout << "inherited constructor class with arguments\n";
}

matrix_calcs::matrix_calcs (const matrix_calcs &mat_c) : matrix_base (mat_c)
{
//   cout << "inherited copy constructor \n";
}

void matrix_calcs::add_matrix_v1 (matrix_calcs m2, matrix_calcs *m_res) // falta validar que sean de igual tamaño
{
    arr_matrix_adder (matrix, m2.matrix, m_res->matrix, row_size, col_size);
}

void matrix_calcs::add_matrix_v2 (matrix_calcs m2, matrix_calcs &m_res) // falta validar que sean de igual tamaño
{
    arr_matrix_adder (matrix, m2.matrix, m_res.matrix, row_size, col_size);
}
matrix_calcs matrix_calcs::add_matrix_v3 (matrix_calcs m2) // falta validar que sean de igual tamaño
{
    matrix_calcs m_res;
    arr_matrix_adder (matrix, m2.matrix, m_res.matrix, row_size, col_size);
    return m_res;
}
matrix_calcs matrix_calcs::operator+ (matrix_calcs m2) // falta validar que sean de igual tamaño
{
    matrix_calcs m_res;
    arr_matrix_adder (matrix, m2.matrix, m_res.matrix, row_size, col_size);
    return m_res;
}

matrix_calcs matrix_calcs::operator= (matrix_calcs m2)
{
    unsigned int count_row, count_col;
    matrix_calcs m_temp;
    for (count_row = 0; count_row < m2.row_size; count_row++)
        for (count_col = 0; count_col < m2.col_size; count_col++)
            m_temp.matrix[count_row][count_col] = m2.matrix[count_row][count_col];
    return m_temp;
}

void matrix_calcs::transpose_matrix_v1 (matrix_calcs *mat) // solo para mat cuadrada?
{
    arr_matrix_transponser (matrix, mat->matrix, row_size, col_size);
}

void matrix_calcs::transpose_matrix_v2 (matrix_calcs &mat)  // solo para mat cuadrada?
{
    arr_matrix_transponser (matrix, mat.matrix, row_size, col_size);
}

matrix_calcs matrix_calcs::transpose_matrix_v3 () //revisar sobrecarga de =  // solo para mat cuadrada?
{
    matrix_calcs mat_t;
    arr_matrix_transponser (matrix, mat_t.matrix, row_size, col_size);
    return mat_t;
}