//		Step 1: Cutout preset determines what to delete and what to keep
//		Step 2: If kept, cutout preset shows area for average and border around it
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
#include "filter.h"
using namespace cimg_library;
using namespace std;

void filter1(vector<vector<vector<int>>> &vec);

void die (string s) {
	cout << "Program Terminated: " << s << endl;
	exit(1);
}

void warn (string s) {
	cout << "Warning: " << s << endl;
	return;
}

//This code must be run with a command line parameter, so print error and quit if they don't run it right
void usage() {
	cout << "INCORRECT USAGE: Needs to be called with a.out [pepe.jpg] [s,c] [dot diameter] [\"border thickness\"]\n";
	cout << "For example, a.out /public/screenshot.jpg c 20 0\n";
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

//Makes a shape to apply to the image
vector <string> make_dot(string dot_shape, unsigned int dot_diameter, unsigned int border_thickness) {
	vector<string> punch;
	if (dot_shape == "s") { // pixel pattern
		for (size_t i = 0; i < dot_diameter; i++) {
			string s = "";
			for (unsigned int j = 0; j < dot_diameter; j++) {
				//cerr << "i: " << i << " | j: " << j << endl;
				if (i == 0 || i == dot_diameter - 1) s.push_back('X');
				else if (s.size() == 0 || s.size() == dot_diameter-1) s.push_back('X');
				else s.push_back('X');
			}
			punch.push_back(s);
		}
	}
	else if (dot_shape == "c") { //circle pattern
		// dist represents distance to the center
		float dist;
		float radius = (dot_diameter / 2.0);

		// for horizontal movement
		for (size_t i = 0; i < dot_diameter; i++) {
			string s = ""; //String to push back into punch	
			for (size_t j = 0; j < dot_diameter; j++) {
				dist = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius)) + 1;
				// dist should be in the range (radius - 0.5) and (radius + 0.5) to print stars(*)
				if (dist > radius - 0.5 && dist < radius + 0.5) { s.push_back('X'); }
				//if (dist < radius + 0.5) { s.push_back('X'); }
				else { s.push_back('0'); }
			}
			punch.push_back(s);
		}
	}
	else if (dot_shape == "r") { //rings?
		// dist represents distance to the center
		float dist;
		float radius = (dot_diameter / 2.0);

		// for horizontal movement
		for (size_t i = 0; i < dot_diameter; i++) {
			string s = ""; //String to push back into punch	
			for (size_t j = 0; j < dot_diameter; j++) {
				dist = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius)) + 1;
				// dist should be in the range (radius - 0.5) and (radius + 0.5) to print stars(*)
				if (dist > radius - 0.5 && dist < radius + 0.5) { s.push_back('X'); }
				else if (dist > radius - 2.0 && dist < radius + 0.5) { s.push_back('9'); }
				//else if (dist > radius - 1.5 && dist < radius + 0.5) { s.push_back('8'); }
				else if (dist > radius - 3.0 && dist < radius + 0.5) { s.push_back('8'); }
				//else if (dist > radius - 1.5 && dist < radius + 0.5) { s.push_back('6'); }
				else if (dist > radius - 5.0 && dist < radius + 0.5) { s.push_back('7'); }
				//else if (dist > radius - 3.5 && dist < radius + 0.5) { s.push_back('4'); }
				else if (dist > radius - 7.0 && dist < radius + 0.5) { s.push_back('6'); }
				//else if (dist > radius - 4.5 && dist < radius + 0.5) { s.push_back('6'); }
				else if (dist > radius - 9.0 && dist < radius + 0.5) { s.push_back('5'); }
				else if (dist < radius + 1.0) { s.push_back('X'); }

				else { s.push_back('0'); } //Clear
			}
			punch.push_back(s);
		}
	}
	//Sets the last value has to be R
	punch[punch.size() -1][punch.size() -1] = 'R';
	return punch;
}

int main(int argc, char **argv) {

	//Check command line parameters
	if (argc != 5) usage(); 

	//Load the image, make the dot.
	clock_t start_time = clock();
	CImg<unsigned char> image(argv[1]);

	//Take in argument for shape
	string dot_shape = (argv[2]);
	if (dot_shape != "c" and dot_shape != "s" and dot_shape != "r") warn("Invalid dot shape");
	
	//Take in argument for diameter
	unsigned int dot_diameter = stoi(argv[3]);
	if (dot_diameter < 0) die("Diameter must be 0 or above.");

	//Take in arg for border thickness
	unsigned int border_thickness = stoi(argv[4]);
	if (dot_diameter < 0 or dot_diameter > 100) die("Border must be 0 to 100.");
	
	//Create Dot
	vector<string> dot = make_dot(dot_shape, dot_diameter, border_thickness);

	//Set globals
	cols = image.width();
	rows = image.height();
	stride = cols * rows;

	//Create a new 3D vector to pass to the image filter code. even though it is of ints, it is really uint8_t's, any value over 255 will cap at 255
	vector<vector<vector<int>>> vec(cols, vector<vector<int>>(rows, vector<int>(COLORS)));
	image_to_vec(image, vec); //Copy data from image to vec to make it easier on students
	clock_t end_time = clock();
	cerr << "Image load time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//Run filter
	for (string s : dot) cout << s << endl;
	start_time = clock();
	dot_image(vec, dot);
	end_time = clock();
	cerr << "Dot time: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";

	//Save image
	vec_to_image(image, vec); //Copy from the vec to the image object
	image.save_png("png.png"); //Use this for higher quality output
	//image.save_jpeg("dot.jpg", 100); //Output result after filter 1
	end_time = clock();
	cerr << "Time to write dot: " << double (end_time - start_time) / CLOCKS_PER_SEC << " secs\n";
}
