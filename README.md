# HIT_data_structure
哈工大数据结构实验及部分数据结构实现

## 数据结构实现
- list
- tree
- graph
- sort_And_find

## 实验
- 实验1：迷宫问题求解
- 实验2：哈夫曼编码压缩文件及解压
- 实验3：Floyd_Warshall和dijkstra最短路径算法实现

## 使用方法
#### Linux或macOS系统 <br>
本项目中每个文件夹中都配置了相应的makefile文件。Linux和macOS系统中内置了g++和make，只需切换到想要执行的文件夹，使用命令：<br>
```
make
```
即可生成prog文件。使用命令：
```
./prog
```
即可执行编译完成的文件。

#### Windows系统 <br>
用管理员权限启动cmd.exe，输入以下指令安装chocolatey：
```
@powershell -NoProfile -ExecutionPolicy Bypass -Command "iex ((new-object net.webclient).DownloadString('https://chocolatey.org/install.ps1'))" && SET PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin
```
之后就可以用类似linux中apt-get的方式安装各种工具，此处用choco install安装make工具：<br>
```
choco install make
```
之后即可使用命令：
```
make
```
即可生成prog文件。使用命令：
```
./prog
```
即可执行编译完成的文件。