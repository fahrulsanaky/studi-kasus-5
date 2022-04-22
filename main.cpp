#include "class.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  MataKuliah MT;

  MT.getDataMahasiswa();
  MT.getMatkul();
  MT.getListMatkul(MT.totalMatkul);
  MT.printOutput();

  return 0;
}