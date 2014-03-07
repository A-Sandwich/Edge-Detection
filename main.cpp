#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#define IMAGE_WIDTH 500
using namespace std;

int** ApplySobel(int** , int** , int , int);
int ** Convolution(int**, int**, int);
int** FindThreshold(int** , int** , int );

int main()
{//define variables
    string line;
    int* image_data;
    int** horizontal_convolution_data_3x3;
    int** vertical_convolution_data_3x3;
    int** convolution_data_3x3;
    int** horizontal_convolution_data_5x5;
    int** vertical_convolution_data_5x5;
    int** convolution_data_5x5;
    int** sobel_vertical_3x3;
    int** sobel_horizontal_3x3;
    int** sobel_vertical_5x5;
    int** sobel_horizontal_5x5;
    int** threshold_data_3x3;
    int** threshold_data_5x5;
    int pixel_count = 250000;
    int counter = 0;
    int row = 0;
    int column = 0;
    horizontal_convolution_data_3x3 = new int*[IMAGE_WIDTH];
    vertical_convolution_data_3x3 = new int*[IMAGE_WIDTH];
    horizontal_convolution_data_5x5 = new int*[IMAGE_WIDTH];
    vertical_convolution_data_5x5 = new int*[IMAGE_WIDTH];
    convolution_data_5x5 = new int*[IMAGE_WIDTH];
    convolution_data_3x3 = new int*[IMAGE_WIDTH];
    threshold_data_3x3 = new int*[IMAGE_WIDTH];
    threshold_data_5x5 = new int*[IMAGE_WIDTH];
    sobel_horizontal_3x3 = new int*[3];
    sobel_vertical_3x3 = new int*[3];
    sobel_vertical_5x5 = new int*[5];
    sobel_horizontal_5x5 = new int*[5];
    for(int i=0;i<3;i++){
        sobel_horizontal_3x3[i] = new int[3];
        sobel_vertical_3x3[i] = new int[3];
    }//end for

    for(int i=0;i<5;i++){
        sobel_vertical_5x5[i] = new int[5];
        sobel_horizontal_5x5[i] = new int[5];
    }//end for

    sobel_horizontal_3x3[0][0] = -1;
    sobel_horizontal_3x3[0][1] = 0;
    sobel_horizontal_3x3[0][2] = 1;
    sobel_horizontal_3x3[1][0] = -2;
    sobel_horizontal_3x3[1][1] = 0;
    sobel_horizontal_3x3[1][2] = 2;
    sobel_horizontal_3x3[2][0] = -1;
    sobel_horizontal_3x3[2][1] = 0;
    sobel_horizontal_3x3[2][2] = 1;

    sobel_vertical_3x3[0][0] = 1;
    sobel_vertical_3x3[0][1] = 2;
    sobel_vertical_3x3[0][2] = 1;
    sobel_vertical_3x3[1][0] = 0;
    sobel_vertical_3x3[1][1] = 0;
    sobel_vertical_3x3[1][2] = 0;
    sobel_vertical_3x3[2][0] = -1;
    sobel_vertical_3x3[2][1] = -2;
    sobel_vertical_3x3[2][2] = -1;

    sobel_horizontal_5x5[0][0] = 1;
    sobel_horizontal_5x5[0][1] = 2;
    sobel_horizontal_5x5[0][2] = 0;
    sobel_horizontal_5x5[0][3] = -2;
    sobel_horizontal_5x5[0][4] = -1;
    sobel_horizontal_5x5[1][0] = 4;
    sobel_horizontal_5x5[1][1] = 8;
    sobel_horizontal_5x5[1][2] = 0;
    sobel_horizontal_5x5[1][3] = -8;
    sobel_horizontal_5x5[1][4] = -4;
    sobel_horizontal_5x5[2][0] = 6;
    sobel_horizontal_5x5[2][1] = 12;
    sobel_horizontal_5x5[2][2] = 0;
    sobel_horizontal_5x5[2][3] = -12;
    sobel_horizontal_5x5[2][4] = -6;
    sobel_horizontal_5x5[3][0] = 4;
    sobel_horizontal_5x5[3][1] = 8;
    sobel_horizontal_5x5[3][2] = 0;
    sobel_horizontal_5x5[3][3] = -8;
    sobel_horizontal_5x5[3][4] = -4;
    sobel_horizontal_5x5[4][0] = 1;
    sobel_horizontal_5x5[4][1] = 2;
    sobel_horizontal_5x5[4][2] = 0;
    sobel_horizontal_5x5[4][3] = -2;
    sobel_horizontal_5x5[4][4] = -1;

    sobel_vertical_5x5[0][0] = -1;
    sobel_vertical_5x5[0][1] = -4;
    sobel_vertical_5x5[0][2] = -6;
    sobel_vertical_5x5[0][3] = -4;
    sobel_vertical_5x5[0][4] = -1;
    sobel_vertical_5x5[1][0] = -2;
    sobel_vertical_5x5[1][1] = -8;
    sobel_vertical_5x5[1][2] = -12;
    sobel_vertical_5x5[1][3] = -8;
    sobel_vertical_5x5[1][4] = -2;
    sobel_vertical_5x5[2][0] = 0;
    sobel_vertical_5x5[2][1] = 0;
    sobel_vertical_5x5[2][2] = 0;
    sobel_vertical_5x5[2][3] = 0;
    sobel_vertical_5x5[2][4] = 0;
    sobel_vertical_5x5[3][0] = 2;
    sobel_vertical_5x5[3][1] = 8;
    sobel_vertical_5x5[3][2] = 12;
    sobel_vertical_5x5[3][3] = 8;
    sobel_vertical_5x5[3][4] = 2;
    sobel_vertical_5x5[4][0] = 1;
    sobel_vertical_5x5[4][1] = 4;
    sobel_vertical_5x5[4][2] = 6;
    sobel_vertical_5x5[4][3] = 4;
    sobel_vertical_5x5[4][4] = 1;

    for(int i=0;i<IMAGE_WIDTH;i++){
        horizontal_convolution_data_3x3[i] = new int[IMAGE_WIDTH];
        vertical_convolution_data_3x3[i] = new int[IMAGE_WIDTH];
        convolution_data_3x3[i] = new int[IMAGE_WIDTH];
        horizontal_convolution_data_5x5[i] = new int[IMAGE_WIDTH];
        vertical_convolution_data_5x5[i] = new int[IMAGE_WIDTH];
        threshold_data_3x3[i] = new int[IMAGE_WIDTH];
        threshold_data_5x5[i] = new int[IMAGE_WIDTH];
    }//end for

    ifstream read_image("gray.raw", ios::in|ios::binary);//image file, opened for reading, read in binary
    fstream horizontal_convolution_3x3("horizontal_3x3.raw", ios::out|fstream::binary);
    fstream vertical_convolution_3x3("vertical_3x3.raw", ios::out|fstream::binary);
    fstream convolution_3x3("convolve_3x3.raw", ios::out|fstream::binary);
    fstream horizontal_convolution_5x5("horizontal_5x5.raw", ios::out|fstream::binary);
    fstream vertical_convolution_5x5("vertical_5x5.raw", ios::out|fstream::binary);
    fstream convolution_5x5("convolve_5x5.raw", ios::out|fstream::binary);
    fstream threshold_3x3("threshold_3x3.raw", ios::out|fstream::binary);
    fstream threshold_5x5("threshold_5x5.raw", ios::out|fstream::binary);

    image_data = new int[pixel_count];//Size of picture data is set.

    read_image.seekg(0, ios::beg);//sets next character to be read in relation to the beggining of the file

    cout << "Created by Kyle Burkholder" <<endl << "CSCI-435" << endl << "Output files consist of: " << endl;

    //load arrays with image data
    while(getline(read_image, line)){
        //cout << "while" << endl;
        for(int i=0; i<line.size(); i++){
            image_data[counter] = (unsigned char)line[i];
            counter++;
        }//end for
        counter ++;
        image_data[counter] = (unsigned char)'\n';
    }//end while

    counter =0;
    for(int i=0; i< 500;i++){
        for(int j=0; j<500; j++){
            horizontal_convolution_data_3x3[i][j] = image_data[counter];
            vertical_convolution_data_3x3[i][j] = image_data[counter];
            horizontal_convolution_data_5x5[i][j] = image_data[counter];
            vertical_convolution_data_5x5[i][j] = image_data[counter];
            counter++;
        }//end for
    }//end for

    horizontal_convolution_data_3x3 = ApplySobel(horizontal_convolution_data_3x3,sobel_horizontal_3x3, IMAGE_WIDTH, 1);
    vertical_convolution_data_3x3 = ApplySobel(vertical_convolution_data_3x3,sobel_vertical_3x3, IMAGE_WIDTH, 1);
    horizontal_convolution_data_5x5 = ApplySobel(horizontal_convolution_data_5x5, sobel_horizontal_5x5, IMAGE_WIDTH, 2);
    vertical_convolution_data_5x5 = ApplySobel(vertical_convolution_data_5x5, sobel_vertical_5x5, IMAGE_WIDTH, 2);

    convolution_data_3x3 = Convolution(horizontal_convolution_data_3x3, vertical_convolution_data_3x3, IMAGE_WIDTH);
    convolution_data_5x5 = Convolution(horizontal_convolution_data_5x5, vertical_convolution_data_5x5, IMAGE_WIDTH);

    threshold_data_3x3 = FindThreshold(horizontal_convolution_data_3x3, vertical_convolution_data_3x3, IMAGE_WIDTH);
    threshold_data_5x5 = FindThreshold(horizontal_convolution_data_5x5, vertical_convolution_data_5x5, IMAGE_WIDTH);

    for(int i=0; i<IMAGE_WIDTH;i++){
        for(int j=0; j<IMAGE_WIDTH; j++){
            horizontal_convolution_3x3 << (unsigned char)horizontal_convolution_data_3x3[i][j];
            vertical_convolution_3x3 << (unsigned char)vertical_convolution_data_3x3[i][j];
            convolution_3x3 << (unsigned char) convolution_data_3x3[i][j];
            horizontal_convolution_5x5 << (unsigned char)horizontal_convolution_data_5x5[i][j];
            vertical_convolution_5x5 << (unsigned char)vertical_convolution_data_5x5[i][j];
            convolution_5x5 << (unsigned char) convolution_data_5x5[i][j];
            threshold_3x3 << (unsigned char) threshold_data_3x3[i][j];
            threshold_5x5 << (unsigned char) threshold_data_5x5[i][j];
        }//end for
    }//end for
    return 0;
}//end main

int** FindThreshold(int** horizontal, int** vertical, int pixel_count){
    int ** convolution_data;
    int ** threshold_data;
    convolution_data = new int*[pixel_count];
    threshold_data = new int*[pixel_count];

    for(int i=0; i<pixel_count; i++){
        convolution_data[i] = new int[pixel_count];
        threshold_data[i] = new int[pixel_count];
    }//end for

    for(int i=0; i<pixel_count; i++){
        for(int j=0; j<pixel_count;j++){
            convolution_data[i][j] =sqrt((horizontal[i][j]*horizontal[i][j])+(vertical[i][j]*vertical[i][j]));
            threshold_data[i][j] = convolution_data[i][j];
        }//end for
    }//end for

    for(int i=0; i<pixel_count;i++){
        for(int j=0; j<pixel_count; j++){
            if((j-1) > 0 && (j+1) < pixel_count){
                if(convolution_data[i][j-1] < convolution_data[i][j] && convolution_data[i][j] > convolution_data[i][j+1]){
                    threshold_data[i][j] = -1;
                }
            }

        }
    }

    for(int i=0; i<pixel_count;i++){
        for(int j=0; j<pixel_count; j++){
            if(threshold_data[i][j] == -1){
                threshold_data[i][j] = 255;
            }else{
                threshold_data[i][j] = 128;
            }
        }
    }
    return threshold_data;
}//end FindThreshold

int** ApplySobel(int** data, int** sobel, int pixel_size, int dxdy){
    int** output;
    int sobel_sum;
    int position = 0;

    output = new int*[pixel_size];
    for(int i=0; i<pixel_size; i++){
        output[i] = new int[pixel_size];
    }//end for

    for(int i = 0; i < pixel_size; i++){
        for(int j = 0; j < pixel_size; j++){
            sobel_sum = 0;
            for(int k=(dxdy*-1); k<=dxdy; k++){
               for(int l=(dxdy*-1); l<=dxdy;l++){
                    if(i+k > 0 && i+k < 500 && j+l > 0 && j+l <500)
                        sobel_sum += sobel[k+dxdy][l+dxdy]*data[i+k][j+l];
               }//end for
            }//end for
            output[i][j] = sobel_sum;
        }//end for
    }//end for
    return output;
}//end ApplySobel

int** Convolution(int** horizontal, int** vertical, int pixel_size){
    int ** convolution_data;
    convolution_data = new int*[pixel_size];
    for(int i=0; i<pixel_size; i++){
        convolution_data[i] = new int[pixel_size];
    }//end for
    for(int i=0; i<pixel_size; i++){
        for(int j=0; j<pixel_size;j++){
            convolution_data[i][j] =sqrt((horizontal[i][j]*horizontal[i][j])+(vertical[i][j]*vertical[i][j]));
            convolution_data[i][j] += 128;
            if(convolution_data[i][j] < 0)
                convolution_data[i][j] = 0;
            else if(convolution_data[i][j] > 255)
                convolution_data[i][j] = 255;
        }//end for
    }//end for
    return convolution_data;
}//end convolution
