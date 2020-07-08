# OpenCV dnn SuperResolution

## Introduction 
This repository is a first approach of using the OpenCV deep neural network for superresolution imaging. 
The final goal is a program (SuperResDNN) for testing different neural models and implementations performance, as well as being able to execute the super-resolution process on a set of images, 
either as a final result or as a "pre-cleaning" for another imaging process.


## Contents
- [How to install SuperResDNN program?](#How_to_install_SuperResDNN_program?)
- [For developers](#For_developers)
- [CMake configuration for Visual Studio](#CMake_configuration_for_Visual_Studio)
- [Build OpenCV libs](#Build_OpenCV_libs)
- [Visual Studio configuration](#Visual_Studio_configuration)
- [References and special thanks](#References_and_special_thanks)


## How to install the SuperResDNN program?
SuperResDNN is an executable program (prompt console), follow the next steps: 
1. Download the executable version according to your platform architecture (currently only x64 version).
2. Download resources folder.
3. Place the executable and the unzipped resources into the same destination folder.
4. Configure SuperResDNN.conf. This file contains configuration parameters like imagen file name, model to use, paths, etc. By default the program will upscale the image “Example.jpg” with the model “FSRCNN_x4.pb”.
5. Run the executable SuperResDNN.exe.


## For developers
This project is made with OpenCV 4.3.0 and extra contributed module DNN superres. OpenCV framework was compiled as static .libs to build light programs. 


## CMake configuration for Visual Studio 
We use CMake 3.16.0-rc4 to build a solution project for Visual Studio 16 (2019) and x64 platform architecture. 

1. In CMake(GUI) we select source and build folders, click configure button and select Visual Studio version and platform architecture (SuperResDNN is currently only in x64).

2. Once configuration is complete, the parameters are the default except the following:

   - BUILD_SHARED_LIBS : uncheck (off)
   - OPENCV_EXTRA_MODULES_PATH: path to opencv_contrib/modules

    Uncheck “Test” are optional but make it easy posterior build configuration of the .libs
   - BUILD_TESTS:uncheck (off)
   - BUILD_PERF_TESTS: uncheck (off)

3. Click the generate button to build Visual Studio OpenCV libs solution.

## Build OpenCV libs
Open the solution in the destination folder. Select the Release mode and the platform (x64). Make sure the project “INSTALL” is checked in the configuration manager so it will be compiled. 
The compilation could take long.

## Visual Studio configuration
- After cloning this repository Visual Studio project must be configured with the path of the OpenCV .lib and include .hcc.
- project properties -> VC++ Directories-> Library Directories -> add path to OpenCV libraries (example [destination folder]\install\x64\vc16\staticlib).
- project properties -> C/C++ ->General -> Additional Include Directories -> add path to OpenCV includes (example [destination folder]\install\include\opencv2).
- project properties -> C/C++ -> Code Generation -> Runtime Library -> Select Multi-threaded MT (MTd for debug).
- project properties -> Linker -> Additional Dependencies -> Add OpenCV libraries file name, at least, for this project:
	
  - ippicvmt.lib
  - opencv_dnn_superres430.lib
  - opencv_imgcodecs430.lib
  - opencv_core430.lib
  - opencv_dnn430.lib
  - opencv_imgproc430.lib
  - libjpeg-turbo.lib
  - libtiff.lib
  - libpng.lib
  - libjasper.lib
  - libwebp.lib
  - libprotobuf.lib
  - ittnotify.lib
  - ippiw.lib
  - zlib.lib
  - IlmImf.lib

*For debug, OpenCV libraries are written with “d” at the end ( [destination folder]\lib\Debug).


## References and special thanks

- [OpenCV](https://github.com/opencv) & CV Community
- [Xavier Weber](https://github.com/Saafke) (Code and models references)
- [Fanny Monori](https://github.com/fannymonori) (models references)


