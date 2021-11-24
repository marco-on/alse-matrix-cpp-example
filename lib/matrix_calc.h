#ifndef MATRIX_CALC_H
#define MATRIX_CALC_H

    #include <iostream>
    using namespace std;    /**< Pin de entrada para el dipswitch 1.*/

    #define MAX_ROWS 100    /*!< Macro con máximo de filas */
    #define MAX_COLS 100    //!< Pin de salida para el led 1.

    /**
    * \brief Declaración de función para sumar matrices.
    */
    void arr_matrix_adder (long double mat1[MAX_ROWS][MAX_COLS], long double mat2[MAX_ROWS][MAX_COLS], long double mat_res[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);

    /**
    * \brief Declaración de función la traspuesta de una matriz.
    */
    void arr_matrix_transponser (long double mat1[MAX_ROWS][MAX_COLS], long double mat_res[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);

    class matrix_base  
    {
        protected:
            long double matrix[MAX_ROWS][MAX_COLS];
            unsigned int row_size, col_size;
        
        public:
        /**
         * Lee las 4 entradas digitales del dipswitch usando la función digitalRead(),
         * declarada en la librería Arduino.h y crea el valor entero que las representa.
         * \param void
         * @return Entero positivo de 8 bits
         */
            matrix_base ();
            matrix_base (int fila, int columna);
            matrix_base ( const matrix_base &mat);
            ~matrix_base();;
            void set_matrix_size ();;
            void set_matrix_values ();
            void print_matrix_size ();
            void print_matrix ();
            bool get_type ();    //falta usar esto para validar

    };

    class matrix_calcs : public matrix_base
    {
        public:
            matrix_calcs();
            matrix_calcs(int fil, int col); 
            matrix_calcs (const matrix_calcs &mat_c); 
            /** 
             * Asigna el estado de los pines digitales del sistema según su modo de operación.
             * Utiliza la función digitalWrite(), declarada en la librería Arduino.h.
             * \param numero unsigned char con un valor decimal que representa el estado de las salidas
             * de acuerdo con su valor en binario. Su uso en la función depende del modo de operación.
             * \param modo unsigned char que representa el modo de operación. Si recibe el valor 
             * 0b00000000, representa el modo Encendido; con el valor 0b00000001, el modo Passthrough.
             * \return void
             * */
            void add_matrix_v1 (matrix_calcs m2, matrix_calcs *m_res); // falta validar que sean de igual tamaño
            void add_matrix_v2 (matrix_calcs m2, matrix_calcs &m_res); // falta validar que sean de igual tamaño
            matrix_calcs add_matrix_v3 (matrix_calcs m2); // falta validar que sean de igual tamaño
            matrix_calcs operator+ (matrix_calcs m2); // falta validar que sean de igual tamaño
            matrix_calcs operator= (matrix_calcs m2);      
            void transpose_matrix_v1 (matrix_calcs *mat); // solo para mat cuadrada?
            void transpose_matrix_v2 (matrix_calcs &mat);  // solo para mat cuadrada?
            matrix_calcs transpose_matrix_v3 (); //revisar sobrecarga de =  // solo para mat cuadrada?
    };

#endif