/*
  Austin Prochaska
  Program 6
  ajp161530
  ajp161530@utdallas.edu
  
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "cdk.h"

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Binary File Content Matrix"

using namespace std;

class BinaryFileRecord
{
public: double myVal;

};


int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           

  const char 		*rowTitles[] = {"R0", "R1", "R2", "R3", "R4", "R5"};
  const char 		*columnTitles[] = {"C0", "C1", "C2", "C3", "C4", "C5"};
  int		boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};
  
  BinaryFileRecord *myRecord = new BinaryFileRecord();
  ifstream binFile ("binaryFile.bin", ios::in | ios::binary);
  cout << binFile.read((char *) myRecord, sizeof(BinaryFileRecord)) << endl;


  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  for(int i = 1; i < 4; i++)
  {
    setCDKMatrixCell(myMatrix, 1, i, "Header");
    drawCDKMatrix(myMatrix, true);    /* required  */
  }

  for(int i = 2; i < 6; i++)
  {
    setCDKMatrixCell(myMatrix, i, 1, "column1");
    drawCDKMatrix(myMatrix, true);
  }

  for(int i = 2; i < 6; i++)
  {
    setCDKMatrixCell(myMatrix, i, 2, "column2");
    drawCDKMatrix(myMatrix, true);
  }
  
  /* So we can see results, pause until a key is pressed. */
  unsigned char x;
  cin >> x;

  // Cleanup screen
  endCDK();
  binFile.close();
  
}
