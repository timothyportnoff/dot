#include <vector>
#include <iostream>
//#include <iomanip>
//#include <cstdlib>
using namespace std;

//Counts the number of pixels that will be kept and averaged
int numO = 0;
double rSum = 0;
double gSum = 0;
double bSum = 0;

//See vec usage down below
const int RED = 0, GREEN = 1, BLUE = 2;

//Calculate maximums of pixels within dot
void rgb_sum(double&rSum, double&gSum, double&bSum, int i, int j, vector<vector<vector<int>>> &vec, vector<string> dot) {
	rSum += vec[i][j][RED];
	gSum += vec[i][j][GREEN];
	bSum += vec[i][j][BLUE];
	numO++;
}

//After reading up to the last char in our dot vector, set all colors of type O to the avg
void paintbucket (size_t i, size_t j, vector<vector<vector<int>>> &vec, vector<string> dot, double tint) {	
	//Paintbucket
	for (size_t k = (i - dot.size()) + 1; k <= i; k++) {
		if (k < 0) k = 0;
		for (size_t l = (j - dot.size()) + 1; l <= j; l++) {
			if (l < 0) l = 0;
			//Erase
			if (dot[k % dot.size()][l % dot.size()] == '0') {
				tint = 0.0;
				vec[k][l][RED]   = 0;
				vec[k][l][GREEN] = 0;
				vec[k][l][BLUE]  = 0;
			}
			else if (dot[k % dot.size()][l % dot.size()] == 'L') {
				tint = 0.8;
				vec[k][l][RED]   = rSum/numO*tint;
				vec[k][l][GREEN] = gSum/numO*tint;
				vec[k][l][BLUE]  = bSum/numO*tint;
			}
			//Paint
			else if (dot[k % dot.size()][l % dot.size()] == 'X') {
				tint = 1.0;
				vec[k][l][RED]   = rSum/numO*tint;
				vec[k][l][GREEN] = gSum/numO*tint;
				vec[k][l][BLUE]  = bSum/numO*tint;
			}
			//??
			else if (dot[k % dot.size()][l % dot.size()] == 'R') {
				tint = 0.0;
				vec[k][l][RED]   = vec[k-1][l-1][RED];
				vec[k][l][GREEN] = vec[k-1][l-1][GREEN];
				vec[k][l][BLUE]  = vec[k-1][l-1][BLUE];
			}
			//Opacity
			else if (dot[k % dot.size()][l % dot.size()] == 'O') {
				tint = 0.5;
				vec[k][l][RED]   = rSum/numO*tint;
				vec[k][l][GREEN] = gSum/numO*tint;
				vec[k][l][BLUE]  = bSum/numO*tint;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '9') {
				tint = 0.9;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '8') {
				tint = 0.8;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '7') {
				tint = 0.7;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '6') {
				tint = 0.6;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '5') {
				tint = 0.5;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '4') {
				tint = 0.4;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '3') {
				tint = 0.3;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '2') {
				tint = 0.2;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '1') {
				tint = 0.1;
			}
			else if (dot[k % dot.size()][l % dot.size()] == '0') {
				tint = 0.0;
			}
			else cout << "mistake in paintbucket function";

			vec[k][l][RED]   = rSum/numO*tint;
			vec[k][l][GREEN] = gSum/numO*tint;
			vec[k][l][BLUE]  = bSum/numO*tint;
		}
	}
	rSum = gSum = bSum = numO = 0;
	return;
}

void dot_image(vector<vector<vector<int>>> &vec, const vector<string>& dot) {
	//Get the number of rows, columns, and colors in this 3D vector
	size_t rows = vec.size();

	if (!rows) exit(1);
	size_t cols = vec[0].size();
	if (!cols) exit(1);
	size_t colors = vec[0][0].size();
	if (!colors) exit(1);

	//Cell shading for Dots and Pixels
	double tint = 1;

	//Do the image filtering on every row and column in this image
	//for (unsigned int i = 0; i < rows; i++) {
		//for (unsigned int j = 0; j < cols; j++) {
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			//Assign rgb for better readability
			int r = vec[i][j][RED];
			int g = vec[i][j][GREEN];
			int b = vec[i][j][BLUE];

			//set_pixel(r, g, b, dot); TODO:

			//Don't do anything is a black pixel 
			if (dot[i % dot.size()][j % dot.size()] == '0') {
				//cout << "heehee" << endl;
				//vec[i][j][RED]   = (r * 0.393 + g * 0.769 + b * 0.189) *0.0; 
				//vec[i][j][GREEN] = (r * 0.349 + g * 0.686 + b * 0.168) *0.0;	//Blends colors in background
				//vec[i][j][BLUE]  = (r * 0.272 + g * 0.534 + b * 0.131) *0.0;
			}

			//Make a dot if we reach the end of our dot vector
			else if (dot[i % dot.size()][j % dot.size()] == 'R') {	
				paintbucket (i, j, vec, dot, tint);
				//vec[i][j][RED]   = (r * 0.393 + g * 0.769 + b * 0.189) *0.1; 
				//vec[i][j][GREEN] = (r * 0.349 + g * 0.686 + b * 0.168) *0.1;	//Gets rid of the dots inbetween the dots. TODO: Need to fix, uncomment for dots
				//vec[i][j][BLUE]  = (r * 0.272 + g * 0.534 + b * 0.131) *0.1;
			}

			else //Update rSum, gSum, and bSum
				rgb_sum(rSum, gSum, bSum,  i,  j, vec, dot);
		}
	}
}
