#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


// Funzione per mappare i numeri nell'intervallo [-1,2]
double map(double N){

    int a = 1;
    int b = 5;
    double R =((3*(N-a))/(b-a))-1;
    return R;
}


int main()
{
    // Apertura del file data.csv
    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }


    // Apro il file di output su cui andrò a scrivere gli output
    std::string fileOutputName = "result.csv" ;
    std::ofstream ofs(fileOutputName);

    // verifichiamo che non ci siano errori nell'apertura del file
    if(ofs.fail())
    {
        std::cerr << "Impossible to open the file" << std::endl;
        return 1;
    }


    int count=1; // questo serve per tenere il conto dei numeri mappati e letti dal file

    double number = 0;
    double cumulativeSum = 0; // somma cumulativa dei numeri mappati per calcolare la media

    ofs << "# N Mean" <<std::endl; // Prima riga del fiile di output


    while (ifstr>>number){
        double numberMapped = map(number);
        // std:: cout << numberMapped<< endl;
        cumulativeSum += numberMapped;
        //std:: cout << cumulativeSum<<std::endl;
        double mean = cumulativeSum / count;
        //std::cout<<mean<<std::endl;

        ofs << count << " " <<  std::scientific << std::setprecision(16) << mean << std::endl;

        count++;

    }
    ofs.close();




    return 0;
}
