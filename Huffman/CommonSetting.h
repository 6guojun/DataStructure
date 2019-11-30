#pragma once

//引入外部库
#include <iostream>
#include <string>
#include <fstream> //文件读取
#include <stack>   //栈的头文件

//引入命名空间
using namespace std;

//如果只有英文，则ByteSize为128
//而中文的ASCII码为复数，因此范围扩大一倍，为256
#define ByteSize 512
#define MAXSIZE ByteSize * 2