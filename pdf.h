#ifndef PDF_H
#define PDF_H

#include <QListWidget>
#include <vector>
#include <cstring>
#include <string>
#include <exception>
#include <hpdf.h>
#include <QMessageBox>

//class that creates the documents
class PDFCreator
{
private:
    std::vector<std::string> paths;

public:
    PDFCreator(QListWidget *widget);
    ~PDFCreator();

    void createPDF(std::string name);
};

#endif // PDF_H
