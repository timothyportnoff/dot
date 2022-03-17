//Student 1 Name: Timothy Portnoff
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//Tried using a pattern I stole from Cmatrix. Doesn't work because of special characters??
/*
cont vector<string> matrix {
	"1 '         K K     F   0   = Q l   b   "   0 0   0         A 0           t           Z *   . > p     7   ' P Y l S   8 ; _     o @   _   c             0       $ K   A           H     h c   -       8 o   O   A",
	"e X     e   y P     #   v   5 ^ s   M   5   5 T   l         U A           D           ; 2 d 0 0 b     W   b _ 9 p r   d , 0 G   l r   C   7             0       g 1   e           *     9 S   C       ? 4   j   t",
	"& ;     ^   f @     c   '   K , O       q   b Z   i         6 U   Z       v           / 1 / ; G 1     `   f ? : J *   4 b 0 K   N e   _   A             P       O =   p         A E     Y j   X       " z   1   a",
	"! U     E   4 h     U   >   W F X /     @   0 Z   z   &     4 0   v       8           [ m J   O ^         5 & < d +   * : G ;   1 6   W   +             o       0 C   c         0 7     f '   W       , B   <   H",
	"x 9     D   n i     6   O   j S k B     5   c &   P   W     F T   [   ;   I           ] ; '   X -         J L - V `   # s , (   - b   W % 8             h       m 2   Y         g '     E     h       2 y   #    ",
	"0 u     +   * t     J   x   h f c s     N   Z I   9   y     V 4   #   '   )           ; r 2   - F   (     0 , 1 " K   2 9   (   ! H   ` X ,       I     R       4 %             o b     &     Y       9 i   0    ",
	"> ;     A   s U     u   5 H ; D 2 /     t   7 e   =   P     z q   I   0   @           s j N   A     \     P 8 # . h   4 T   (   I m   < * [       , P   ?   7   ! m             - k     u     / 0   : $ Q   I    ",
	"0 c     B   v *     V   k T   * X 0     `   l %   ^   >     Z C   M   0   M           A m c   t     V     y 7 C x T   w Z   o o   D   [ b _       V F   x   ?   j j   I         F 8     E     T W   J = X   8    ",
	"c ^     e   2 w     8     0   e ? 3     o   C .   t   s     & 4   5   `   0 W         / g 0   t     ]     w : ? k y   U p   0 a   "   ( y *       h 0   P   3   b B   r         E 0     i     @ K   o - >   '    ",
	"m [     :   v N   Q 3     <     J #     Y   8 5 f 7   V     * >   E   n   z I         u $ @   7     0       y 4 c N   : m   V P   c   S R z       9 e   "   0   J d   ,     k   f D     D     b b   h [ c   n    ",
	"V Z     8   G Y   i M     Z     F M     G   A s l     :     r Z   <   *   N 6         Z 0 Z   l     g         5 A b   = ^   D (   r   P - F       0 V   H   )   Y d   F     t   j R     Y     u R   7 3 O   (    ",
	"i /     j   4 M   " g     s     x k     %     R U     p     w .       k   ( Y         T K o   I     z         a I     f i   G `   _   Z m o       - o   &   ,   0 E   I     y   ; j L   9     _ 1   + 6 J   p    ",
	"f C     6   E W   R =     F     < z     .     D j     !     l J       a   t D         B   n   j     U         G x     5     i N   d   m ( T       @ $   s   c   Q B   m   J G   ( J `   E     Z -   d 4 ]   *    ",
	"U g     +   , ^   x 8     `     ? H     A     H r     b     h r       ?   E m         N       w     P         @ >     u     @ <   ?   P - '       ` 6   '   .   ) =   F   v 1   t 0 0   .     ! 0   h e r   @    ",
	"! :   6 5   * ;   t       .     b K     P     . V     0     0         /   e R         a       ?     !         y 4     Z     * *   >   N 7 T       D T       0   I h   x   - #   ? Q %   0     ( 3   f - D   _    ",
	"0 S   m R   = E   -       $     Q $     k     m .     &     @         x   ) L         v       Q     N         > l     2     @ v   C   ' F ]   G   7 X       H   p !   J   M -   ) U 5         ^ (   T > Q   c    ",
	"0 B   n )   N P   u *     t       B     o     = >     L     Q         b   G +         /       O     k         # c     (     K E   E   S @ w   *   2 K       G   Z S   k   B ]   _ 3 %         r     L . H   0    ",
	"$ ,   M     < ?   , @     X       *     %     Q )     p     V         B   K i         p       x     !         ' 5     3     X "   u   T 4 ]   O   " P     n `   j %   ?   f R   " 3 l         %     d 2 ?   C P  ",
	"  8   q     L D   5 =     /       r     J     & w     a     Q         ^   V N     .   =       /     B         R w     l     5 e       k " E   a   e -     6 d     o   H   0 &   5 r l         4     s z K   & 8  ",
	"  p   m       4   Y +     ?       7     P   < F )     y     @         9   I ,     A                 g         p N     0     j "       # b x   r   U G A   ' C     G   3 l i W   J 6 )         w     g P A   = N  ",
	"U t   t       5   > 7     1             p   N u b     L     w         >   f #     7                 V         - I     (     K 6       6 ' O   c   P K l   I l     i S C s ) 5   v x f         =     v ? M   g W  ",
	"S \   ]       *   e D     [             6 _ 8 $ p     Q     E         T   Z H     1                 #         W `     #   f Y %       * , j   -   V Z O   O &     . V 5 0 \ O   y 2 /         S     K F c   S `  ",
	"K R   n       F   3 /     o             f ' M L r     [     e         /   , B   c Y                 j         F L     p   m ' 0       h G n   V   o N #   0 k     X h @ / D     j K z         %     w 0 c   O v  ",
	"% N   s       =   y y     0           @ 0 Z x ` Q k   X     %         e   h m   6 k                           w R     x   * A w       K ( @   \   r O =   [ x     r 3 = T 5     0 b &         =     4 k :   e 0  ",
	"] =   y       ]   E d     (           Y 7 Y 9 G f M   Y     K         <   4 g   s C                           ( E     (   ( ! X       i a 0   3 _ x Y D   < 5     5 N o - Z     Y P J               O 8 _   @ @  ",
	"] p   j       r   * t     q           < [ ( \ 0 G o   > z   Z         G   V A   4 = ]                         6 t     "   P   Y   "   < q D   D a c _ Q   d ]     A t   g i     @ t [               R T r   Y 0  ",
	"W \   >       a   z 0     !         f @ K G ,   X `   9 ^   #         0   % z   # O Z                         0       f   "   A   :   7 J K   3 & E # Q   , 7     0 5   k I     R R +               ' u F   Z A !",
	"W .   .       W   : T     ,   d     ` . d = *   ! M   % V   ?       w '   G c   * 1 2                         V       6   7   @   T   j ` Q   / [ n k K   ( E       u   a N     @ 0 )               e e [   I V h",
	"L `   M       n   ' q     *   _     v y ` c .   V c   _ N   )       ( 3   * V   g Q L                         t       8   E   7   `   r 1 C   6 ) 1 - z   e (       B Q = "       P F               q I _   w \ '",
	"& 8   ]       2   u R     p   '     ! - w T i   U ;   u V   g       q R M X D   J d w                         K       q   e   Z   "   i % h   @ v R j /     k       ? ? C /       " K               9 a p   + > p",
	"3 G   8       `   1 a     &   -     s $ q $ K   ` 1   F 0   J       S 0 ( t >   Q A >                         M       !   6   U   &   b L `   R [ S I \     S       d 0 6 <       <                 n O d   % S 6",
	"J .   ^       U   x ^     Z   w     O a y t >   c '   [ F   \       m D U / Y   u A f                         &       D   H   E Z #   6 p ^   D A < & D     "       $ I c ;       P                 i E k   8 X G"
};
*/

//TODO: Put these "cutouts" in a header file
const vector<string> cutout1 { //20x20 Dots	
	"0000000LLLLLL0000000",
	"00000LLLXXXXLLL00000",
	"000LLLXXXXXXXXLLL000",
	"00LLXXXXXXXXXXXXLL00",
	"00LXXXXXXXXXXXXXXL00",
	"0LLXXXXXXXXXXXXXXLL0",
	"0LXXXXXXXXXXXXXXXXL0",
	"LLXXXXXXXXXXXXXXXXLL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LLXXXXXXXXXXXXXXXXLL",
	"0LXXXXXXXXXXXXXXXXL0",
	"0LLXXXXXXXXXXXXXXLL0",
	"00LXXXXXXXXXXXXXXL00",
	"00LLXXXXXXXXXXXXLL00",
	"000LLLXXXXXXXXLLLL00",
	"00000LLLXXXXLLL00000",
	"0000000LLLLLL000000R",
};

const vector<string> cutout2 { //10x10 Dots
	"000LLLL000",
	"0LLLXXLLL0",
	"0LXXXXXXL0",
	"LLXXXXXXLL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LLXXXXXXLL",
	"0LXXXXXXL0",
	"0LLLXXLLL0",
	"000LLLL00R",
};

const vector<string> cutout3 { //20x20 Pixels
	"LLLLLLLLLLLLLLLLLLLL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LXXXXXXXXXXXXXXXXXXL",
	"LLLLLLLLLLLLLLLLLLLR",
	//20x20
	//Pixels! 
};

const vector<string> cutout4 { //10x10 Pixels
	"LLLLLLLLLL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LXXXXXXXXL",
	"LLLLLLLLLR",
};

const vector<string> message { //Secret message
	"______    BBBBBBB   ______      _   _    ___   ______    BBB   BBB  BBB BBBBBB  BBBBBBB",
	"| ___ B   BB   BB   | ___ B    | | | |  / _ B  | ___ B  B   B  B  BB  B B     B B  BBBB",
	"| |_/ B     B B     | |_/ /    | |_| | / /_B B | |_/ B B  B  B B      B B BB  B B B    ",
	"|    B      B B     |  __/     |  _  | |  _  | |    /  B     B B BBBB B B     B B BBB  ",
	"| |B B  _  BB BB  B | |     _  | | | | | | | | | |B B  B BBB B B B  B B B BB  B B B    ",
	"B_| BBB(_) BBBBB BBBBB|    (_) BBB BBB BBB BBB BBB BBB BBB BBB BBB  BBB BBBBBB  BBBBBBB",
};


	

//Easy way to swap the pattern:
const vector<string> cutout = cutout4;

//Global values so I don't have to call by reference??? FIXME?
double rSum = 0;
double gSum = 0;
double bSum = 0;

//Counts the number of pixels that will be kept and averaged
int numO = 0;

//Cell shading for Dots and Pixels
double tint = 1;

//Kerney Magic
const int RED = 0, GREEN = 1, BLUE = 2;

//After reading up to the last char in a cutout vec, sets all colors of type O to the avg
int setColor (int i, int j, vector<vector<vector<int>>> &vec, double tint) {	
	int k = 0;
	int l = 0;
	//if (i - cutout.size() < 0) return 0;
	//if (j - cutout.size() < 0) return 0;
	
	for (int k = i - cutout.size(); k < i; k++) {
		if (k < 0) k = 0;
		for (int l = j - cutout.size(); l < j; l++) {
			if (l < 0) l = 0;
			if (cutout[k % cutout.size()][l % cutout.size()] == 'X' || cutout[k % cutout.size()][l % cutout.size()] == 'L') {
				rSum += vec[i][j][RED];
				gSum += vec[i][j][GREEN];
				bSum += vec[i][j][BLUE];
				numO++;
			}
		}
	}
	for (int k = i - cutout.size(); k < i; k++) {
		if (k < 0) k = 0;
		for (int l = j - cutout.size(); l < j; l++) {
			if (l < 0) l = 0;
			if (cutout[k % cutout.size()][l % cutout.size()] == 'X') {
				tint = 1;
				vec[k][l][RED]   = rSum/numO*tint;
				vec[k][l][GREEN] = gSum/numO*tint;
				vec[k][l][BLUE]  = bSum/numO*tint;
			}	
			else if (cutout[k % cutout.size()][l % cutout.size()] == 'L' || cutout[k % cutout.size()][l % cutout.size()] == 'R') {
				tint = 0.8;
				vec[k][l][RED]   = rSum/numO*tint;
				vec[k][l][GREEN] = gSum/numO*tint;
				vec[k][l][BLUE]  = bSum/numO*tint;
			}
		}
	}
	rSum = 0;
	gSum = 0;
	bSum = 0;
	numO = 0;
	return 0;
}

void filter1(vector<vector<vector<int>>> &vec) {
	//Get the number of rows, columns, and colors in this 3D vector
	size_t rows = vec.size();
	if (!rows) exit(1);
	size_t cols = vec.at(0).size();
	if (!cols) exit(1);
	size_t colors = vec.at(0).at(0).size();
	if (!colors) exit(1);

	//Crops the image to work with all pixels
	//for (int i = 0; i < vec.size()%cutout.size(); i++) vec.pop_back();

	//Do the image filtering on every row and column in this image...
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			//Make my banana yellow again
			/*
			vec.at(i).at(j).at(RED) *= 1.01; //Increase red value at every point by 50%
			vec.at(i).at(j).at(GREEN) *= 1.01; //Increase green at every point by 20%
			vec.at(i).at(j).at(BLUE) *= 0.09; //Reduce blue by 20%
			*/
			
			//Get the red, green and blue values at row i, col j:
			int r = vec[i][j][RED]; //Bounds check with .at the first time
			int g = vec[i][j][GREEN]; //Skip bounds check for speed
			int b = vec[i][j][BLUE];
			
			if (cutout[i % cutout.size()][j % cutout.size()] == '0') {
				vec[i][j][RED]   = (r * 0.393 + g * 0.769 + b * 0.189) *0.1; 
				vec[i][j][GREEN] = (r * 0.349 + g * 0.686 + b * 0.168) *0.1;	//Blends colors in background
				vec[i][j][BLUE]  = (r * 0.272 + g * 0.534 + b * 0.131) *0.1;
			}
			
			else if (cutout[i % cutout.size()][j % cutout.size()] == 'R') {	
				setColor(i, j, vec, tint);
				//vec[i][j][RED]   = (r * 0.393 + g * 0.769 + b * 0.189) *0.1; 
				//vec[i][j][GREEN] = (r * 0.349 + g * 0.686 + b * 0.168) *0.1;	//Gets rid of the dots inbetween the dots. TODO: Need to fix, uncomment for dots
				//vec[i][j][BLUE]  = (r * 0.272 + g * 0.534 + b * 0.131) *0.1;
			}
		}
	}

	/*
	   for (int i = 0; i < message.size(); i++) {
		for (int j = 0; j < message.at(i).size(); j++) {
			if (message.at(i).at(j) != ' ') {
				vec[j+6][i+6][RED]   = 0; 
				vec[j+6][i+6][GREEN] = 0;
				vec[j+6][i+6][BLUE]  = 0;
			}
		}
	}
	*/
}
