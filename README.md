![Server Architecture](https://raw.githubusercontent.com/ArkGame/ArkGameFrame/master/Docs/asserts/imgs/ArkGameFrame.png)

##### Copyright © [https://github.com/ArkGame](https://github.com/ArkGame "Ark Game")

[![Gitter chat](https://badges.gitter.im/gitterhq/node-gitter.png)](https://gitter.im/ArkGame/Lobby)

Website: https://arkgame.net
<br>
Github: https://github.com/ArkGame/ArkGameFrame
<br>
Gitee(码云): https://gitee.com/ArkGame/ArkGameFrame

## ArkGameFrame
ArkGameFrame is a lightweight, fast, scalable, distributed plugin framework written in C++，make it easier to create game server. 



##### Wanna get the newest features? Please switch to the develop branch.

**<font color=red>If you wanna commit PR or report issue, please refer to [Contribution Guide](https://github.com/ArkGame/ArkGameFrame/blob/master/CONTRIBUTING.md)</font>**

## Contact

- QQ Group: 540961187
- mail: arkgametech@163.com

## Features

- General abstract data system
- Interface-oriented programming (IOP)
- Event-driven and data-driven
- Extensible apps, plugins, and modules
- High concurrency and performance by using actor model (Theron)
- Based on the event-driven and attribute-driven can make business more clear and easy to maintenance
- Based on C++ standard, easy to handle and learn
- Cross platform (Include Windows and Linux)
- Distributed server architecture
- Use Excel as configuration files, easier for users
- With existed Unity3D client for rapid development

### FAQ

Please [create a new issue](https://github.com/ArkGame/ArkGameFrame/issues) to ask a question.

### Unity3D client

[Unity3D Client](https://github.com/ArkGame/ArkClient-Unity3D)

## Architecture

### App Architecture:

![App Architecture](https://raw.githubusercontent.com/ArkGame/ArkGameFrame/master/Docs/asserts/imgs/AppArchitecture.png)

### Server Architecture

![Server Architecture](https://raw.githubusercontent.com/ArkGame/ArkGameFrame/master/Docs/asserts/imgs/ServerArchitecture.png)

## Get the Sources:

git clone https://github.com/ArkGame/ArkGameFrame.git

or

svn checkout https://github.com/ArkGame/ArkGameFrame

## Dependencies

- libevent master
- easylogging++ 9.80
- mysql++ 3.2.2
- google protobuf 2.7.0
- pybind11 1.2
- redis-cpp-client
- curl 7.37.1
- evpp 0.7.0

## Supported Compilers

- GCC >= 4.8 (**<font color=red>Recommend</font>. Tested in Ubuntu 15.04**)
- MSVC >= VS2015 update 3 (**<font color=red>Recommend</font>. Tested in Win7/10**)

## Build and Install

### Windows

##### Prerequisites:

- Windows 10, 8.1, or 7
- Visual Studio 2017 or Visual Studio 2015 Update 3
- Git
- CMake 3.9.1+

##### Step:
Using Visual Studio
1. Pull all source
2. Run `Dep/build_dep.bat`
3. Open the solution: `Frame/Ark.sln`
4. Build the solution`Ark.sln`
5. Run `GenerateConfigXML.bat` to generate configuration files
6. Run the binary file by `Bin/Server/Debug/Run.bat`

Using CMake
1. Pull all source
2. Run `Dep/build_dep.bat`
3. Use command line
```batch
cd path/to/ArkGameFrame
md build
cd build
cmake -G "Visual Studio 14 Win64" ..
```
4. Start `ARK.sln`

### linux

We are still working on this platform, please wait for a while.


>> ### CodeBlocks >= 13.1(Only in linux)
>> 1. Git pull all source
>> 2. Run `Dep/build_dep.sh`
>> 3. Open the solution with CodeBlocks: `Frame/Ark.workspace`
>> 4. Check `C++11` option in CodeBlocks compiler setting
>> 5. Build `Ark.workspace`
>> 6. Run `bash ./GenerateConfigXML.sh` to generate configuration files
>> 7. Run the binary file by `Bin/Server/Debug/rund.sh`

## Documents

[English](https://github.com/ArkGame/ArkGameFrame/blob/master/Docs/doc_EN.md)

[Mandarin](https://github.com/ArkGame/ArkGameFrame/blob/master/Docs/doc_ZH.md)

## Examples

Please see `Frame/Examples`.

## License

The ArkGameFrame project is currently available under the [Apache License](https://github.com/ArkGame/ArkGameFrame/blob/master/LICENSE).

----------
### C# Project

Still working on it, maybe use Akka.net or Orleans

----------
Our team has always specialized in the agile development and try to help different teams to develop game project quickly and easily. After years of development, we create this frame which is a fast, scalable, distributed game server framework, can be used as a real-time multiplayer game engine. We are still improving it.

----------

#### Plan

View our [lastest plan](https://github.com/ArkGame/ArkGameFrame/blob/master/Docs/plan.md)

----------

#### The relationship with NF

This branch come from [NF](https://github.com/ketoo/NoahGameFrame), we used to be the **CORE DEVELOPERS** of NF. We create **ArkGameFrame** because some different design philosophies, through our new ideas and modifications, now this project is a fresh project which has many different features.