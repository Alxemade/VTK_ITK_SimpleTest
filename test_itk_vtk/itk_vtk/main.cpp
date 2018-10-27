#include <itkImage.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
#include <itkImageFileReader.h>
#include <itkImageToVTKImageFilter.h>
#include <itkGDCMImageIO.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkImageFlip.h>
#include <vtkRenderer.h>
#include <vtkImageActor.h>
#include <vtkCamera.h>
#include <vtkImageMapper.h>
#include <string.h>
using namespace std;

int main()
{
        typedef itk::Image<unsigned char,2> ImageType;
        typedef itk::ImageFileReader<ImageType> ReaderType;
        ReaderType::Pointer reader = ReaderType::New();

        //获得DICOM文件读取对象
        typedef itk::GDCMImageIO ImageIOType;
        ImageIOType::Pointer gdcmImageIO = ImageIOType::New();

        //Filterofitkimagedatatovtkimagedata;
        typedef itk::ImageToVTKImageFilter<ImageType>FilterType;
        FilterType::Pointer connector = FilterType::New();

        //获得DICOM文件名并读取DICOM文件;
        const char *temp = "G://qt_problem//test_itk_vtk//dcm//brain_001.dcm";
        char *DICOMName =new char[strlen(temp)+1];
        strcpy(DICOMName, temp);
        //const char* DICOMName = "G://qt_problem//test_itk_vtk//dcm//brain_001.dcm";
        reader->SetFileName(DICOMName);
        reader->SetImageIO(gdcmImageIO);

        //ITK到VTK转化
        connector->SetInput(reader->GetOutput());
        connector->Update();

        vtkSmartPointer<vtkImageFlip> flip = vtkSmartPointer<vtkImageFlip>::New();
        //vtkSmartPointer<vtkImageMapper>
        flip->SetInputData(connector->GetOutput());
        flip->SetFilteredAxis(1);

        //需要进行上下翻转才能正确显示;
        flip->Update();


        vtkSmartPointer<vtkImageActor>actor = vtkSmartPointer<vtkImageActor>::New();
        actor->SetInputData(flip->GetOutput());
        actor->InterpolateOff();

        vtkSmartPointer<vtkRenderer>renderer = vtkSmartPointer<vtkRenderer>::New();
        renderer->AddActor(actor);


        vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
        renderWindow->AddRenderer(renderer);

        vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();

        iren->SetRenderWindow(renderWindow);
        iren->Initialize();
        iren->Start();

        return 0;
}
