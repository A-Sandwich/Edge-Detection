#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;

int main()
{//define variables
    string line;
    int* horizontal_convolution_data_3x3;
    int* vertical_convolution_data_3x3;
    int* horizontal_convolution_data_5x5;
    int* vertical_convolution_data_5x5;//holds data read from image
    int pixel_count = 250000;

    ifstream read_image("500.raw", ios::in|ios::binary);//image file, opened for reading, read in binary
    fstream horizontal_convolution_3x3("average3x3.raw", ios::out|fstream::binary);
    fstream vertical_convolution_3x3("gausian3x3.raw", ios::out|fstream::binary);
    fstream horizontal_convolution_5x5("average5x5.raw", ios::out|fstream::binary);
    fstream vertical_convolution_5x5("gausian5x5.raw", ios::out|fstream::binary);


    horizontal_convolution_data_3x3 = new int[pixel_count];//Size of picture data is set.
    vertical_convolution_data_3x3 = new int[pixel_count];//Size of picture data is set.
    horizontal_convolution_data_5x5 = new int[pixel_count];//Size of picture data is set.
    vertical_convolution_data_5x5 = new int[pixel_count];//Size of picture data is set.


    read_image.seekg(0, ios::beg);//sets next character to be read in relation to the beggining of the file

    cout << "Created by Kyle Burkholder" <<endl;
    cout << "CSCI-435" << endl;
    cout << "Output files consist of: " << endl;



    //load arrays with image data
    while(getline(read_image, line)){
        for(int i=0; i<line.size(); i++){
            pixel_count++;//count pixels
            horizontal_convolution_data_3x3[i] = (unsigned char)line[i];
            vertical_convolution_data_3x3[i] = (unsigned char)line[i];
            horizontal_convolution_data_5x5[i] = (unsigned char)line[i];
            vertical_convolution_data_5x5[i] = (unsigned char)line[i];
        }//end for
    }//end while

    //output results of filters
    for(int j=0; j<250000; j++){

        horizontal_convolution_3x3.put(horizontal_convolution_data_3x3[j]);
        vertical_convolution_3x3.put(vertical_convolution_data_3x3[j]);
        horizontal_convolution_5x5.put(horizontal_convolution_data_5x5[j]);
        vertical_convolution_5x5.put(vertical_convolution_data_5x5[j]);
    }
    cout << "exit";
    return 0;
}
