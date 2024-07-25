# MyProject

这是一个使用 KMP 算法的 C 语言示例工程，适用于 Windows 环境,采用 CMake 生成构建工程,conan管理依赖项,VSCode编辑器开发,ninja构建工程.

## 目录结构

```tree
CPROJECT_WIN
├───.cache
│   └───clangd
│       └───index
├───.vscode
├───build
│   └───Release
│       ├───CMakeFiles
│       │   ├───3.29.2
│       │   │   ├───CompilerIdC
│       │   │   │   └───tmp
│       │   │   └───CompilerIdCXX
│       │   │       └───tmp
│       │   ├───MyProject.dir
│       │   │   └───src
│       │   └───pkgRedirects
│       └───generators
├───include
├───out
└───src
```

## 依赖项

- [Conan](https://conan.io/)
官网下载
- [CMake](https://cmake.org/)
官网下载
- [Ninja](https://ninja-build.org/)

```powershell
pip install ninja
```

- 编译器:mingw64 gcc

## 构建和运行

### 1. 安装依赖项

首先，确保您已经安装了 Conan、CMake 和 Ninja。然后运行以下命令来安装项目依赖项：

```sh
conan install . --build=missing --profile=conan_profile_x64
```

### 2. 配置和构建项目

运行 build_x64.bat 脚本来配置和构建项目：

```powershell
build_x64.bat
```

### 3. 运行可执行文件

构建完成后，您可以在 out 目录下找到生成的可执行文件 MyProject.exe。运行它：

```powershell
cd out
.\MyProject.exe
```

## 项目文件说明

- main.c：主程序文件，包含 KMP 算法的实现。
- include/kmp.h：KMP 算法的头文件。
- src/kmp.c：KMP 算法的实现文件。
- .clangd: LSP 服务器配置文件。
- .vscode: Visual Studio Code 配置文件。
- CMakeLists.txt：CMake 构建脚本。
- conanfile.txt：Conan 依赖项配置文件。
- build_x64.bat：构建项目的脚本。
- conan_profile_x64：Conan 依赖项配置文件。
- README.md：项目说明文件。
- C project.code-workspace：VSCode 工作区配置文件。
