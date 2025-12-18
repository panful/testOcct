#include <iostream>
#include <Standard_Version.hxx>
#include <gp_Pnt.hxx>

int main()
{
    std::cout << "OCCT is alive." << std::endl;

    // 1. 打印 OCCT 版本
    std::cout << "OCCT version (string): "
              << OCC_VERSION_STRING << std::endl;

    std::cout << "OCCT version (major.minor.maint): "
              << OCC_VERSION_MAJOR << "."
              << OCC_VERSION_MINOR << "."
              << OCC_VERSION_MAINTENANCE << std::endl;

    // 2. 创建一个最基础的几何对象
    gp_Pnt p(1.0, 2.0, 3.0);

    std::cout << "gp_Pnt created: ("
              << p.X() << ", "
              << p.Y() << ", "
              << p.Z() << ")" << std::endl;

    std::cout << "Everything looks fine." << std::endl;

    return 0;
}
