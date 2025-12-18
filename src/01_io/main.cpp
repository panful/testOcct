#include <BRepPrimAPI_MakeBox.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <TopoDS_Shape.hxx>
#include <iostream>

int main()
{
    try
    {
        // 1. 创建一个立方体 (100 x 100 x 100)
        TopoDS_Shape box = BRepPrimAPI_MakeBox(100.0, 100.0, 100.0).Shape();

        // 2. 导出 STEP 文件
        STEPControl_Writer writer;
        IFSelect_ReturnStatus status = writer.Transfer(box, STEPControl_AsIs);

        if (status != IFSelect_RetDone)
        {
            std::cerr << "Failed to transfer shape to STEP writer." << std::endl;
            retun 1;
        }

        status = writer.Write("box.step");
        if (status != IFSelect_RetDone)
        {
            std::cerr << "Failed to write STEP file." << std::endl;
            return 1;
        }

        std::cout << "STEP file 'box.step' exported successfully!" << std::endl;
    }
    catch (Standard_Failure& e)
    {
        std::cerr << "OCCT Error: " << e.GetMessageString() << std::endl;
        return 1;
    }

    return 0;
}
