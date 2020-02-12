#include <iostream>
#include <vector>
#include <map>

#include <dlib/clustering.h>


void load_dataset(const std::string& dataset_file_name){

    //  тип записи - вектор из 2 элементов [[x, y],]
    typedef dlib::matrix<double,7,1> sample_type;
    //    массив записей (датафрейм)
    std::vector<sample_type> samples;
    sample_type m;

    std::string line;
    std::ifstream dataset_file(dataset_file_name);
    std::map<std::string,int> single_line;

    std::string val;

    if (dataset_file.is_open()) {
        while (!dataset_file.eof()) {
            getline(dataset_file, line, '\n');
            if (!line.empty()) {
                std::istringstream iss(line);

                int i = 0;
                while (!iss.eof()) {
                    std::getline(iss, val, ';');
                    if (val.empty()) {
                        val = "0";
                    }
                    m(i) = stod(val);
                    i++;
                };
                samples.push_back(m);
            }
        }
    }
    dataset_file.close();
}

int main() {
    std::string data_file = "../dataset.csv";
    load_dataset(data_file);


    return 0;
}
