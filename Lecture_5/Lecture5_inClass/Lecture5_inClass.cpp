#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

const int imageSize = 10;
const int imageCount = 10;
void generate_images(int* imgs_in);
void printImage(const int(&image)[imageCount][imageSize][imageSize]);
double img_avg(int* img_in);
int* brightest_of(int* img_set);
void sort_brightness(int* img_set, int** output);



//this fucntion generated images
//image values randomly generated from 0-255
void generate_images(int* imgs_in) {

    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageSize; j++) {
            imgs_in[(imageSize * i) + j] = rand() % 255;
        }
    }

}

void printImage(const int (&image)[imageCount][imageSize][imageSize]) {
    for (int i = 0; i < imageCount; i++) {
        std::cout << "Image #" << i + 1 <<" Address at: "<< *image[i]<< ":\n";//Label starting from zero to match array indexing.
        for (int v = 0; v < imageSize; v++) {
            for (int h = 0; h < imageSize; h++) {
                std::cout << image[i][v][h] << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }
}
/*
Write a function that calculates and returns the average brightness of a specic image (i.e. the
sum of all of its pixels divided by 100  100). Like the diag function you wrote in class, it should
be given a pointer to the start of an image in order to determine which image to work on:
*/
double img_avg(int* img_in) {
    double sum = 0;
    //std::cout << "current index is: " << img_in << std::endl;
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageSize; j++) {
            sum += img_in[imageSize * i + j];
        }
    }
    return sum / (imageSize * imageSize);
}

/*
Write a function that returns a pointer to the image with the highest average brightness, out of
the entire 10-image "block" whose starting location is passed to it:
*/
int* brightest_of(int* img_set) {
    double maxBright = 0.0;
    double currentBright = 0.0;
    int* brightestIndex = img_set;
    int* currentIndex = img_set;
    int interpretableIndex = 0;
    for (int i = 0; i < imageCount; i++) {
        currentIndex = img_set + imageSize * imageSize * i;
        currentBright = img_avg(currentIndex);
        //std::cout << "Current brightness from brightest for " << i+1<< " calculation is: " << currentBright << std::endl;
        if (currentBright > maxBright) {
            maxBright = currentBright;
            brightestIndex = currentIndex;
        }
    }
    std::cout << std::endl;
    return brightestIndex;
}



/*
Create function which returns an array of pointers to all of the images, sorted from brightest to
darkest:
*/
void sort_brightness(int* img_set, int** output)
{
    int* currentIndex = img_set;   
    double currentBrightness = 0;
    // Ahhhh fuck this, miss python's dictionary....
    std::map<int*, double> correlatedIndexBrightness;

    // Log all
    for (int i = 0; i < imageCount; i++) {
        currentIndex = img_set + imageSize * imageSize * i;
        currentBrightness = img_avg(currentIndex);
        correlatedIndexBrightness.insert({ currentIndex ,currentBrightness });
    }

    // Sort all
    // Define dictionary Comparison
    typedef std::function<bool(std::pair<int*, double>, std::pair<int*, double>)> Comparator;

    Comparator compFunctor = [](std::pair<int*, double> elem1, std::pair<int*, double> elem2) {
        return elem1.second > elem2.second;
    };

    // Declaring a set that will store the pairs using above comparision logic
    std::set<std::pair<int*, double>, Comparator> 
        comparedSet(correlatedIndexBrightness.begin(), correlatedIndexBrightness.end(), compFunctor);

    int index = 0;
    // write index
    for (auto element : comparedSet) {
        output[index++] = element.first;
    }
}

/*
Create another function which sorts the actual images from brightest to darkest in-place (that is,
within the same block of memory they were in originally).
*/
void swap(int* image1, int* image2) {
    int temp;
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageSize; j++) {
            temp = image1[imageSize * i + j];
            image1[imageSize * i + j] = image2[imageSize * i + j];
            image2[imageSize * i + j] = temp;
        }
    }
}

void sort_brightness_internal(int* img_set) {

    // get an image, get the brightness
    // compare it with the next one similar to bubble sort
    int x, y;
    int* image1 = img_set;
    int* image2 = img_set;
    for (x = 0; x < imageCount - 1; x++) {
        for (y = 0; y < imageCount - 1; y++) {
            image1 = img_set + imageSize * imageSize * y;
            image2 = image1 + imageSize * imageSize ;
            if (img_avg(image1) < img_avg(image2))
                swap(image1, image2);
        }
    }

}



int main(const int argc, const char** argv) {
    srand(time(NULL));

    //create empty 5 images each 10x10 (empty)
    int imgs[imageCount][imageSize][imageSize];

    //call generate image function to create images
    for (int i = 0; i < imageCount; i++) {
        generate_images((int*)imgs[i]);
    }
    std::cout << std::endl;

    //Prints all of the images to the screen
    printImage(imgs);
    for (int i = 0; i < imageCount; i++) {
        std::cout << "Image average " << (i+1) << " is: " << img_avg((int*)imgs[i]) << std::endl;
    }
    std::cout << std::endl;

    int* brightest_index = brightest_of((int*)imgs);
    std::cout << "The brightest option: " << brightest_index << std::endl<< std::endl;

    int* brightnessIndex[imageCount];
    sort_brightness((int*)imgs, brightnessIndex);
    int counter = 1;
    for (auto element : brightnessIndex) {
        std::cout << "Sorted rank index is: " << counter++ << "  " << element <<std::endl;
    }

    std::cout << std::endl;
    sort_brightness_internal((int*)imgs);
    printImage(imgs);

}