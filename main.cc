//==================================================================================
//Student 1 Name: Timothy Portnoff
//	Student 1's Filter Description:
//		Step 1: Cutout preset determines what to delete and what to keep
//		Step 2: If kept, cutout preset shows area for average and border around it
//		Step 3: Help me
//Student 2 Name: Timothy Portnoff
//	Student 2's Filter Description:
//		Step 1: A filter that Puts quadrouples the image
//FIXME: Need to expand image because of quality loss
//TODO: Bring up shadows and highlights to  sharpen the pixel
//TODO Remove filter
//==================================================================================
#include <CImg.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "filter1.cc"
using namespace cimg_library;
using namespace std;

void filter1(vector<vector<vector<int>>> &vec);

void filter2(vector<vector<vector<int>>> &vec);

void filter3(vector<vector<vector<int>>> &vec);

//This code must be run with a command line parameter, so print error and quit if they don't run it right
void usage() {
	cout << "Error: this program needs to be called with a command line parameter indicating what file to open.\n";
	cout << "For example, a.out /public/kyoto.jpg\n";
	exit(1);
}

//Copy values from image into a 3D vector
const int COLORS = 3;
int cols, rows, stride;
void image_to_vec(const CImg<unsigned char> &image, vector<vector<vector<int>>> &vec) {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < COLORS; k++) {
				vec.at(i).at(j).at(k) = image[k * stride + j * cols + i];
			}
		}
	}
}
//Clamp the values in vec to [0..255] then copy to image
void vec_to_image(CImg<unsigned char> &image, vector<vector<vector<int>>> &vec) {
	const int MAX_COLOR = 255;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < COLORS; k++) {
				//Saturate the values, meaning values above 255 just become white, below 0 become black
				int temp = vec.at(i).at(j).at(k);
				if (temp > MAX_COLOR) temp = MAX_COLOR;
				if (temp < 0) temp = 0;
				vec[i][j][k] = temp;
				image[k * stride + j * cols + i] = temp;
			}
		}
	}
}

int main(int argc, char **argv) {
	if (argc != 2) usage(); //Check command line parameters

	//PHASE 1 - Load the image
	clock_t start_time = clock(); 
	CImg<unsigned char> image(argv[1]);

	//Set globals
	cols = image.width();
	rows = image.height();
	stride = cols * rows;

	//Create a new 3D vector to pass to the students' image filter code. even though it is of ints, it is really uint8_t's, any value over 255 will cap at 255
	vector<vector<vector<int>>> vec(cols, vector<vector<int>>(rows, vector<int>(COLORS)));
	image_to_vec(image, vec); //Copy data from image to vec to make it easier on students
	clock_t end_time = clock();
	cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//PHASE 2 - Run Student 1's Code
	start_time = clock();
	filter1(vec);
	end_time = clock();
	cerr << "Filter 1 time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
	start_time = clock();
	vec_to_image(image, vec); //Copy from the vec to the image object
	//image.save_png("filter1.png"); //Use this for higher quality output
	image.save_jpeg("filter1.jpg", 100); //Output result after filter 1
	end_time = clock();
	cerr << "Time to write filter1.jpg: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	/*
	//PHASE 3 - Run Student 2's Code
	start_time = clock();
	filter2(vec);
	end_time = clock();
	cerr << "Filter 2 time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
	start_time = clock();
	vec_to_image(image, vec); //Copy from the vec to the image object
	//image.save_png("filter2.png"); //Uncomment this for higher quality output
	image.save_jpeg("filter2.jpg", 100); //Output result after filter 2
	end_time = clock();
	cerr << "Time to write filter2.jpg: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
*/
}

