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

