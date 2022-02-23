#include "pdf.h"
#define ERROR_STR1 "File: "
#define ERROR_STR2 " cannot be loaded"

PDFCreator::PDFCreator(QListWidget *widget)
{
    //converting to c-like strings
    for (int i = 0; i < widget->count(); i++)
    {
        QString text = widget->item(i)->text();
        this->paths.push_back(text.toStdString());
    }
}

PDFCreator::~PDFCreator() { }

static std::string buildErrorMessage(std::string path)
{
    std::string res = ERROR_STR1;
    res += path;
    res += ERROR_STR2;
    return res;
}

//creates and save the document
void PDFCreator::createPDF(std::string name)
{
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    std::vector<std::string> errors;
    QMessageBox info; //for displaying informations

    for (auto &path: this->paths)
    {
        HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf, path.c_str());
        if (!image) //image didn't load
        {
            errors.push_back(buildErrorMessage(path.c_str()));
            continue;
        }

        //calculating image dimensions
        auto width = (float)HPDF_Image_GetWidth(image) * 0.75f;
        auto height = (float)HPDF_Image_GetHeight(image) * 0.75f;

        //creating the page
        HPDF_Page page = HPDF_AddPage(pdf);
        HPDF_Page_SetWidth(page, width);
        HPDF_Page_SetHeight(page, height);
        HPDF_Page_DrawImage(page, image, 0.f, 0.f, width, height);
    }

    HPDF_SaveToFile(pdf, name.c_str());
    HPDF_Free(pdf);

    //if errors occured
    if (errors.size()) {
        std::string errorString = "The following errors occured:\n";
        for (auto &error: errors)
            errorString += error + '\n';
        info.setText(QString(errorString.c_str()));
    } else { //success
        info.setText("PDF created succesfully");
    }

    info.exec();
}
