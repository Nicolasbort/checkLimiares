#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>


#define GAUSSIANFILTER 3
#define KERNELSIZE 7

using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{
    Mat mainImg = imread(argv[1]);
    Mat img_C1 = Mat::zeros(mainImg.size(), CV_LOAD_IMAGE_GRAYSCALE);

    if (mainImg.empty())
    {
        cout << "Rodar o código > ./getLimiares \"NomeImagem\"" << endl;
        return -1;
    }

    int MINHUE = 0;
    int MAXHUE = 255;

    int MINSAT = 0;
    int MAXSAT = 255;

    int MINVAL = 0;
    int MAXVAL = 255;


    printf("MAXVALUES:\nH: %d  S: %d  V: %d\n", MAXHUE, MAXSAT, MAXVAL);
    printf("MINVALUES:\nH: %d  S: %d  V: %d\n", MINHUE, MINSAT, MINVAL);


    cvtColor(mainImg, mainImg, COLOR_BGR2HSV);

    while (true)
    {

        inRange(mainImg, Scalar(MINHUE, MINSAT, MINVAL), Scalar(MAXHUE, MAXSAT, MAXVAL), img_C1);
        
        imshow("", img_C1);

        int key = waitKey();


        cout << key;

        switch (key)
        {
        case 113:               // q
            MINHUE += 5;
            break;

        case 97:                // a
            MINHUE -= 5;
            break;
            
        case 119:               // w
            MINSAT += 5;
            break;

        case 115:               // s
            MINSAT -= 5;
            break;

        case 101:               // e
            MINVAL += 5;
            break;

        case 100:               // d
            MINVAL -= 5;
            break;

        ////////// UP VALUES ///////

        case 116:               // t
            MAXHUE += 5;
            break;
            
        case 103:               // g
            MAXHUE -= 5;
            break;
            
        case 121:               // y
            MAXSAT += 5;
            break;
            
        case 104:               // h
            MAXSAT -= 5;
            break;
            
        case 117:               // u
            MAXVAL += 5;
            break;
            
        case 106:               // j
            MAXVAL -= 5;
            break;
        
        default:
            break;
        }

        if (key > 0)
        {
            cout << "\033[2J\033[1;1H";
            printf("\nMAXVALUES:   H: %d  S: %d  V: %d\n\n", MAXHUE, MAXSAT, MAXVAL);
            printf("MINVALUES:   H: %d  S: %d  V: %d\n", MINHUE, MINSAT, MINVAL);
        }
    }
}