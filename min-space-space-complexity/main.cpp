#include <iostream>
#include <cstdint>
#include <vector>

/**
 * 	          bool[]	bool*   std::vector	    bool* / std::vector		std::vector / bool*	
    Elementos	        Bytes			              %		                    %	
         1	         1	   8	  24	            33,33%		            300,00%	
        10	        10	  80	  24	            333,33%		            30,00%	
        11	        11	  88	  48	            183,33%		            54,55%	
        20	        20	 160	  48	            333,33%		            30,00%	
        21	        21	 168	  96	            175,00%		            57,14%	
        40	        40	 320	  96	            333,33%		            30,00%	
        41	        41	 328	 192	            170,83%		            58,54%	
        80	        80	 640	 192	            333,33%		            30,00%	
        81	        81	 648	 384	            168,75%		            59,26%	
       160	       160	1280	 384	            333,33%		            30,00%	
       161	       161	1288	 768	            167,71%		            59,63%	
       320	       320	2560	 768	            333,33%		            30,00%	
       321	       321	2568	1536	            167,19%		            59,81%	
       640	       640	5120	1536	            333,33%		            30,00%	
       641	       641	5128	3072	            166,93%		            59,91%	

 * 
 * 
 * It is worth mentioning that in the std::vector there will not be all the students, only 
 * those who meet the condition, while in the bool* there would be all the students, regardless 
 * of whether they meet it or not, since this is precisely the work of each 
 * element in the arrangement.
 * 
 * 
 * * > uint16_t = short unsigned int
 * 
 * short: Only ocupies 2 Bytes = 16 Bits
 * unsigned: can only store positive values [0, 65.535]
 * 
 * * > float = float :P
 * 
 * There's no other way (in terms of space) to store decimal numbers efficiently
 * 
 * * > std::string
 * 
 * 32 Bytes regardless of the size :P (tested)
 * 
 * BUT, need to invest some more in order to read the data from the std::string
 * 
*/

void logSize() {
    std::cout << "sizeof(uint8_t): " << sizeof(uint8_t) << " Bytes" << std::endl;
    std::cout << "sizeof(uint16_t): " << sizeof(uint16_t) << " Bytes" << std::endl;
    std::cout << "sizeof(float): " << sizeof(float) << " Bytes" << std::endl;
    std::cout << "sizeof(bool): " << sizeof(bool) << " Bytes" << std::endl;
    std::cout << "sizeof(bool*): " << sizeof(bool*) << " Bytes" << std::endl;
    std::cout << "sizeof(std::vector<uint8_t>): " << sizeof(std::vector<uint8_t>) << " Bytes" << std::endl;
}

template <typename T>
int validateGrade(T grade) {
    return grade >= 0 && grade <= 5.0;
}

template <typename T>
T takeInput(const std::string &message) {
    T temp;

    do {
        std::cout << message;
        std::cin >> temp;
    } while (!validateGrade(temp));

    return temp;
}

template <typename T>
float processStudents(T& totalStudents, T& aprovedStudents, T& perfectGradeStudentsCount) {
    float accumulative = 0.0f;

    for (T i = 0; i < totalStudents; i++) {
        std::cout << std::endl << "ESTUDIANTE " << i + 1 << std::endl;

        float finalGrade = 
            takeInput<float>("Ingrese la nota del parcial: ") * 0.5f + 
            takeInput<float>("Ingrese la nota de los quices: ") * 0.3f +
            takeInput<float>("Ingrese la nota de los talleres: ") * 0.2f;
        
        accumulative += finalGrade;

        if (finalGrade == 5.0f) {
            std::cout << "{ ESTUDIANTE " << i + 1 << " | Calificacion Perfecta }" << std::endl;
            perfectGradeStudentsCount++;
        }   
        
        if (finalGrade >= 3.0f) {
            aprovedStudents++;
            std::cout << "[ APROBADO ] [ " << finalGrade << " ]" << std::endl; 
            continue;
        }

        std::cout << "[ DESAPROBADO ] [ " << finalGrade << " ]" << std::endl; 
    }

    return accumulative;
}

template <typename T>
void calculateGeneralAverage(float sumatory, T &totalStudents) {
    std::cout << std::endl << "Promedio General: " << sumatory / totalStudents << std::endl;
}

int main() {
    std::cout << std::endl;

    logSize();

    std::cout << std::endl << "Numero de estudiantes" << std::endl;

    uint8_t aprovedStudents = 0, totalStudents, perfectGradeStudentsCount = 0;

    do {
        uint16_t temp;
        std::cout << "-> ";
        std::cin >> temp;

        if (temp >= 0 && temp <= 255)
            totalStudents = static_cast<uint8_t>(temp);
    } while (totalStudents <= 0);

    calculateGeneralAverage(processStudents(totalStudents, aprovedStudents, perfectGradeStudentsCount), totalStudents);
    std::cout << "Aprobados: " << static_cast<int>(aprovedStudents) << std::endl;
    std::cout << "Desaprobados: " << static_cast<int>(totalStudents - aprovedStudents) << std::endl;
    std::cout << "Estudiantes con calificacion perfecta: " << static_cast<int>(perfectGradeStudentsCount) << std::endl;

    system("PAUSE");

    return EXIT_SUCCESS;
}
