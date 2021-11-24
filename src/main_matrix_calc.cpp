/** 
 * \mainpage Ejemplo de Documentación de un programa para un sistema digital básico.
 * \brief Documentación de programa en C++ para encender/apagar pines digitales 
 * de salida y leer el estado de los pines de entrada de un microcontrolador (MCU) ATmega328P
 * en tarjeta Arduino UNO.
 * 
 * \section desc Descripción del programa.
 * Este programa muestra el funcionamiento de un sistema de cuatro (4) entradas (DS_IN_[3:0])
 * cuatro (4) salidas digitales (LED_[3:0]), donde el bit más significativo (MSb), 
 * tanto para el bit de entrada (DS_IN_3) como el de salida (LED_3), representa el
 * modo de funcionamiento del sistema. Por tanto, el sistema tiene 2 modos de funcionamiento:
 *  - modo passthrough (1) \n El estado de las entradas DS_IN_[2:0] se ve reflejado en las salidas LED_[2:0].
 *  - modo encendido (0) \n Las salidas LED_[2:0] siempre están en estado activo sin importar el estado de las entradas DS_IN_[2:0].
 * 
 * \authors Autor Dos, Autor Tres, Autor Uno
 * \date 23 de noviembre de 2021
 * \version 1.1.0
 * \copyright copyright description
 * 
*/
#include "../lib/matrix_calc.h"

/**
 * @brief Se ejecuta el main.
 * 
 */
int main ()
{
    matrix_calcs m1(2,1), m2(2,1), m_r(2,1); /*!< 1 Objetos de la clase derivada usando constructor */

    m1.set_matrix_values();
    m1.print_matrix();

    m2.set_matrix_values();
    m2.print_matrix();

    cout << "resultado de la suma usando apuntador" << endl;
    m1.add_matrix_v1(m2, &m_r);
    m_r.print_matrix();

    cout << "resultado de la suma usando referencia de C++" << endl;
    m1.add_matrix_v2(m2, m_r);
    m_r.print_matrix();

    cout << "Resultado de la suma retornando el objeto" << endl;
    m_r = m1.add_matrix_v3(m2);
    m_r.print_matrix();

    cout << "Resultado de la suma sobrecargando el operador +" << endl;
    m_r = m1 + m2;
    m_r.print_matrix();

    cout << "Resultado de la transpuesta de la matriz 1 usando apuntador" << endl;
    m1.transpose_matrix_v1(&m_r);
    m_r.print_matrix();

//    cout << "\n\nfin del programa\n";
    return 1;
}
