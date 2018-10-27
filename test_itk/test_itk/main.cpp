#include <QApplication>

#include <itkImage.h>
#include<iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    typedef itk::Image<unsigned short, 3>ImageType;
    ImageType::Pointer image = ImageType::New();
    int i;

    std::cout<<"ITK hello world !"<<std::endl;
    std::cin>>i;
    return a.exec();
}
