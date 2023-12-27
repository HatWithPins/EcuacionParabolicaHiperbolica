# ValorCarateristico

:es: \
Implementación del método QR para la resolución de EDP parabólicas e hiperbólicas. Usa CMake para la compilación.

Para compilar en la línea de comandos:

`cmake CMakeList.txt` \
`cmake --build . --target EcuacionParabolicaHiperbolica`

Si se usa un IDE tipo Visual Studio, abre la carpeta como un proyecto y compila como cualquier otro proyecto. Asegúrate de que tienes la extensión para CMake.


`EcuacionParabolicaHiperbolica`

## Estructura de los archivos.
- EcuacionParabolicaHiperbolica contiene el main y las comprobaciones de los argumentos.
- MetodoQR contiene la clase que implementa el método QR.

:uk: \
Implementation of QRfor solving parabolical and hyperbolical PDE. Builds using cmake.

To build using command line:

`cmake CMakeList.txt` \
`cmake --build . --target EcuacionParabolicaHiperbolica`

In case you use and IDE like Visual Studio, open the folder as a project and build it like any other project. Ensure that your IDE has the extensions for CMake.


`EcuacionParabolicaHiperbolica`


## Folder structure.
- EcuacionParabolicaHiperbolica contains the main function and is in charge of checking parsed arguments.
- MetodoQR contains the class that implements QR method.