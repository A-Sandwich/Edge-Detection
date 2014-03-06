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
    unsigned int counter = 0;

    ifstream read_image("gray.raw", ios::in|ios::binary);//image file, opened for reading, read in binary
    fstream horizontal_convolution_3x3("horizontal_3x3.raw", ios::out|fstream::binary);
    //fstream vertical_convolution_3x3("vertical3x3.raw", ios::out|fstream::binary);
    //fstream horizontal_convolution_5x5("horizontal5x5.raw", ios::out|fstream::binary);
    //fstream vertical_convolution_5x5("vertical5x5.raw", ios::out|fstream::binary);


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
        //cout << "while" << endl;
        for(int i=0; i<line.size(); i++){

            pixel_count++;//count pixels
            //horizontal_convolution_3x3.put(line[i]);
            horizontal_convolution_data_3x3[counter] = (unsigned char)line[i];
            vertical_convolution_data_3x3[counter] = (unsigned char)line[i];
            horizontal_convolution_data_5x5[counter] = (unsigned char)line[i];
            vertical_convolution_data_5x5[counter] = (unsigned char)line[i];
            //cout << (int)line[i] << ", ";
            //cout << i << endl;
            counter++;
        }//end for
        counter ++;
        horizontal_convolution_data_3x3[counter] = (unsigned char)'\n';

    }//end while
    cout << counter << endl;
    //output results of filters
//    cout << horizontal_convolution_data_3x3.size();
    for(int j=0; j<250000; j++){
        horizontal_convolution_3x3 << (unsigned char)horizontal_convolution_data_3x3[j];
        //horizontal_convolution_3x3.put((unsigned char)horizontal_convolution_data_3x3[j]);
        //vertical_convolution_3x3.put(vertical_convolution_data_3x3[j]);
        //horizontal_convolution_5x5.put(horizontal_convolution_data_5x5[j]);
        //vertical_convolution_5x5.put(vertical_convolution_data_5x5[j]);
    }

    return 0;
}
