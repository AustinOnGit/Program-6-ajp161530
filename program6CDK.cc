/*
  Austin Prochaska
  Program 6
  ajp161530
  ajp161530@utdallas.edu
  
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdint.h>
#include <sstream>
#include <string>
#include "cdk.h"


#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Content Matrix"

using namespace std;

class BinaryFileHeader
{
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

const int maxRecordStringLength = 25;

class BinaryFileRecord
{
public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
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
  
  BinaryFileHeader *myHeader = new BinaryFileHeader();
  BinaryFileRecord *myRecord = new BinaryFileRecord();
  BinaryFileRecord *myRecord2 = new BinaryFileRecord();
  BinaryFileRecord *myRecord3 = new BinaryFileRecord();
  BinaryFileRecord *myRecord4 = new BinaryFileRecord();



  ifstream binFile ("binaryFile.bin", ios::in | ios::binary);
  binFile.read((char *) myHeader, sizeof(BinaryFileHeader));
  binFile.read((char *) myRecord, sizeof(BinaryFileRecord));
  binFile.read((char *) myRecord2, sizeof(BinaryFileRecord));
  binFile.read((char *) myRecord3, sizeof(BinaryFileRecord));
  binFile.read((char *) myRecord4, sizeof(BinaryFileRecord));
  

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

  char magic[64];
  sprintf(magic, "%X", myHeader->magicNumber);
  
  char version[64];
  sprintf(version, "%u", myHeader->versionNumber);

  char numRec[64];
  sprintf(numRec, "%X", myHeader->numRecords);

   setCDKMatrixCell(myMatrix, 1, 1, magic);
   drawCDKMatrix(myMatrix, true);
 
   setCDKMatrixCell(myMatrix, 1, 2, version);
   drawCDKMatrix(myMatrix, true); 

   setCDKMatrixCell(myMatrix, 1, 3, numRec);
   drawCDKMatrix(myMatrix, true);


   char len1[64];
   sprintf(len1, "%u",myRecord->strLength);

   setCDKMatrixCell(myMatrix, 2, 1, len1);
   drawCDKMatrix(myMatrix, true);

   char len2[64];
   sprintf(len2, "%u",myRecord2->strLength);

   setCDKMatrixCell(myMatrix, 3, 1, len2);
   drawCDKMatrix(myMatrix, true);

   char len3[64];
   sprintf(len3, "%u",myRecord3->strLength);

   setCDKMatrixCell(myMatrix, 4, 1, len3);
   drawCDKMatrix(myMatrix, true);

   char len4[64];
   sprintf(len4, "%u",myRecord4->strLength);

   setCDKMatrixCell(myMatrix, 5, 1, len4);
   drawCDKMatrix(myMatrix, true);


   /*

    setCDKMatrixCell(myMatrix, 2, 1, "strlength: 10");
    drawCDKMatrix(myMatrix, true);

    setCDKMatrixCell(myMatrix, 3, 1, "strlength: 10");
    drawCDKMatrix(myMatrix, true);

    setCDKMatrixCell(myMatrix, 4, 1, "strlength: 16");
    drawCDKMatrix(myMatrix, true);

    setCDKMatrixCell(myMatrix, 5, 1, "strlength: 6");
    drawCDKMatrix(myMatrix, true);
   */




    setCDKMatrixCell(myMatrix, 2, 2, myRecord->stringBuffer);
    drawCDKMatrix(myMatrix, true);
  
    setCDKMatrixCell(myMatrix, 3, 2, myRecord2->stringBuffer);
    drawCDKMatrix(myMatrix, true);

    setCDKMatrixCell(myMatrix, 4, 2, myRecord3->stringBuffer);
    drawCDKMatrix(myMatrix, true);

    setCDKMatrixCell(myMatrix, 5, 2, myRecord4->stringBuffer);
    drawCDKMatrix(myMatrix, true);

    


  /* So we can see results, pause until a key is pressed. */
  unsigned char x;
  cin >> x;

  // Cleanup screen
  endCDK();
  binFile.close();
  
}
