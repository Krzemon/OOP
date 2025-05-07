#ifndef BARCODEREADER_H
#define BARCODEREADER_H

#include <string>
#include <vector>

class BarcodeReader {
private:
    std::string _filename;
    std::vector<std::string> _barcodes;

    /**
     * @brief wypisze zawartość wektora _barcodes
     */
    void decode();

public:
    BarcodeReader(std::string filename = "default.txt") : _filename(filename) {}
    /**
     * @brief usuwa dane z _barcodes
     */
    void clear();

    /**
     * @brief wczytuje dane z pliku o nazwie _filename
     * moze sie przydac klasa std::ifstream
     */
    void readFile();

    /**
     * @brief ustawia nazwe pliku _filename
    */
    void setFile(std::string filename);

    /**
     * @brief wypisze zawartość wektora _barcodes
     */
    void dumpFile();




    // ~BarcodeReader();
    // void initialize();
    // void startReading();
    // void stopReading();
    // void processBarcode(const char* barcode);
};


#endif // BARCODEREADER_H