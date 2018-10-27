#include <QApplication>
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkJPEGReader.h>
#include <vtkRenderer.h>

#include<QVTKWidget.h>

int main(int argc,char **argv)
{
    //QCoreApplication a(argc, argv);
    QApplication app(argc, argv);
    QVTKWidget widget;
    widget.resize(256,256);
    //Setupsphere
    vtkSmartPointer<vtkSphereSource>sphereSource=vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->Update();
    vtkSmartPointer<vtkPolyDataMapper>sphereMapper=vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    vtkSmartPointer<vtkActor>sphereActor= vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);
    //Setupwindow
    vtkSmartPointer<vtkRenderWindow>renderWindow=vtkSmartPointer<vtkRenderWindow>::New();
    //Setuprenderer
    vtkSmartPointer<vtkRenderer>renderer=vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);
    renderer->AddActor(sphereActor);
    renderer->ResetCamera();
    widget.SetRenderWindow(renderWindow);
    //mainWindow.setCentralWidget(widget);

    //mainWindow.show();
    widget.show();
    app.exec();
    return EXIT_SUCCESS;

}

