#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class TokoElektronik {
private:
    string etalase[3];

    string at(size_t index) {
        if (index >= 3) {
            throw out_of_range("Error");
        }
        return etalase[index];
    }

public:
    TokoElektronik() {
        etalase[0] = "Televisi";
        etalase[1] = "Kulkas";
        etalase[2] = "Mesin Cuci";
    }

    string ambilProduk(size_t nomorRak) {
        try {
            return at(nomorRak);
        }
        catch (const out_of_range& e) {
            if (nomorRak == 5) {
                throw "Gagal Mengambil Barang : Rak nomor 5 kosong atau tidak tersedia!";
            } else {
                throw "Gagal Mengambil Barang : Rak kosong atau tidak tersedia!";
            }
        }
    }
};

void readGudang() {
    ifstream infile("gudang.txt");
    string baris;
    cout << "\n=== DAFTAR BARANG DI GUDANG ===" << endl;
    int i = 1;
    while (getline(infile, baris)) {
        cout << i++ << ". " << baris << endl;
    }
    infile.close();
}

void createBarang() {
    ofstream outfile("gudang.txt", ios::app);
    string barang;
    cout << "Nama barang baru: "; 
    cin.ignore(); getline(cin, barang);
    outfile << barang << endl;
    outfile.close();
    cout << "Berhasil ditambah!" << endl;
}

void updateBarang() {
    ifstream infile("gudang.txt");
    string data[100], baris;
    int n = 0;
    while (getline(infile, baris)) data[n++] = baris;
    infile.close();

    int pilih;
    cout << "Pilih nomor yang diupdate: "; 
    cin >> pilih;
    if (pilih > 0 && pilih <= n) {
        cout << "Nama baru: "; 
        cin.ignore(); getline(cin, data[pilih-1]);
        
        ofstream outfile("gudang.txt");
        for (int i = 0; i < n; i++) outfile << data[i] << endl;
        outfile.close();
        cout << "Berhasil diupdate!" << endl;
    }
}

void deleteBarang() {
    ifstream infile("gudang.txt");
    string data[100], baris;
    int n = 0;
    while (getline(infile, baris)) data[n++] = baris;
    infile.close();

    int pilih;
    cout << "Pilih nomor yang dihapus: "; 
    cin >> pilih;
    if (pilih > 0 && pilih <= n) {
        ofstream outfile("gudang.txt");
        for (int i = 0; i < n; i++) if (i != pilih-1) outfile << data[i] << endl;
        outfile.close();
        cout << "Berhasil dihapus!" << endl;
    }
}

int main() {
    TokoElektronik toko;
    int pilihan;

    do {
        cout << "\n--- MENU TOKO ELEKTRONIK GIBRAN JAYA ---" << endl;
        cout << "1. Create (Tambah Barang)" << endl;
        cout << "2. Read (Lihat Gudang)" << endl;
        cout << "3. Update Barang" << endl;
        cout << "4. Delete Barang" << endl;
        cout << "5. Simulasi Etalase" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: createBarang(); 
                    break;
            case 2: readGudang(); 
                    break;
            case 3: updateBarang(); 
                    break;
            case 4: deleteBarang(); 
                    break;
            case 5: {
                try {
                    cout << "Skenario 1 (Rak 1): " << toko.ambilProduk(1) << endl;
                    cout << "Skenario 2 (Rak 5): " << toko.ambilProduk(5) << endl;
                } catch (const char* e) { 
                    cout << e << endl; }
                break;
            }
        }
    } while (pilihan != 6);

    return 0;
}