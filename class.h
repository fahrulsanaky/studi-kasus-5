
#include <iostream>
#include <fstream>
using namespace std;
class MataKuliah {
    private:
      struct Data {
        string matkul;
        int sks;
      };
      int dataListIndex = 0;
      Data dataList[256];
      string name;
      int nim;
    public:
      int totalMatkul;

      void getDataMahasiswa() {
        cout << "=================================\n";
        cout << "Masukan nama mahasiswa : ";
        cin >> name;
        cout << "Masukan NIM : ";
        cin >> nim;
        cout << "=================================\n";
      }

      void getMatkul() {
        cout << "Banyak Matkul : ";
        cin >> totalMatkul;
        cout << "=================================\n";
      }

      void getListMatkul(int n) {
        string tempMatkul;
        int tempSKS;
        if (n != 0) {
          cout << "Masukan matakuliah : ";
          cin >> tempMatkul;
          cout << "Masukan SKS : ";
          cin >> tempSKS;
          cout << "=================================\n";

          dataList[dataListIndex].matkul = tempMatkul;
          dataList[dataListIndex].sks = tempSKS;

          dataListIndex++;
          
          getListMatkul(n - 1);
        }
      }

      int calculatePrice() {
        int tempTotalSKS = 0 ;
        int tempTotalHarga = 0;

        for(int i = 0; i < dataListIndex + 1; i++ ) {
          tempTotalSKS += dataList[i].sks;
        }

        cout << tempTotalSKS;
        tempTotalHarga = tempTotalSKS * 125000;
        tempTotalHarga = tempTotalHarga - (tempTotalHarga * 0.10);
        tempTotalHarga = tempTotalHarga - (tempTotalHarga * 0.05);  
          
        return tempTotalHarga;
      }

      void printOutput() {
        ofstream txt("struk.txt");
        txt << "========================\n";
        txt << "UNIVERSITAS AHMAD DAHLAN\n";
        txt << "========================\n";
        txt << "Nama : " << name << endl;
        txt << "NIM  : " << nim << endl;
        txt << "========================\n";
        txt << "Daftar Matkul\t\t\t\tSKS \n";
        for(int i = 0; i < dataListIndex; i++ ) {
          txt << dataList[i].matkul << "\t\t\t\t\t\t\t\t" << dataList[i].sks << endl;
        } 
        txt << "========================\n";
        txt << "Total pembayaran  = Rp." << calculatePrice();
        txt.close();
      }
};