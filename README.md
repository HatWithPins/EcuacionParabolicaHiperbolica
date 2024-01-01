# ValorCarateristico

:es: \
Implementación del método QR para la resolución de EDP parabólicas e hiperbólicas. Usa CMake para la compilación.

Para compilar en la línea de comandos:

`cmake` \
`cmake --build .`

Si se usa un IDE tipo Visual Studio, abre la carpeta como un proyecto y compila como cualquier otro proyecto. Asegúrate de que tienes la extensión para CMake.


`EcuacionParabolicaHiperbolica boundary_left=0.0 boundary_right=0.0 N=10 T=10.0 L=1.0`

## Estructura de los archivos.
- EcuacionParabolicaHiperbolica contiene el main y las comprobaciones de los argumentos.
- MetodoQR contiene la clase que implementa el método QR.

:uk: \
Implementation of QRfor solving parabolical and hyperbolical PDE. Builds using cmake.

To build using command line:

`cmake` \
`cmake --build .`

In case you use and IDE like Visual Studio, open the folder as a project and build it like any other project. Ensure that your IDE has the extensions for CMake.


`EcuacionParabolicaHiperbolica  boundary_left=0.0 boundary_right=0.0 N=10 T=10.0 L=1.0`


## Folder structure.
- EcuacionParabolicaHiperbolica contains the main function and is in charge of checking parsed arguments.
- MetodoQR contains the class that implements QR method.