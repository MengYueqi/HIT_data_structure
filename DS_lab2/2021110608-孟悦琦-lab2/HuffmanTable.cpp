//
// Created by 孟繁兴 on 2022/10/11.
//

#include "HuffmanTable.h"

// 设置某个位置的Huffman编码
void HuffmanTable::setcode(int n) {
    std::string code;
    char c;
    while (!s.empty()){
        c = s.top();
        s.pop();
        code.push_back(c);
    }
    HuffTable[n].code = code;
    HuffTable[n].c = (char)0x0A+n;
}

// 更新Huffman编码表
void HuffmanTable::update_HFTable(HuffmanTree HFTree) {
    for (int i = 0; i < 0x80-0x0A; ++i) {
        int j=i;  // 用j对储存的数组进行遍历
        while (HFTree.getparent(j) != -1) {
            // 如果处在左支，那么取0，如果处在右支，那么取1
            if(j == HFTree.getlchild(HFTree.getparent(j))) {
                s.push('0');
            } else if(j == HFTree.getrchild(HFTree.getparent(j))){
                s.push('1');
            }
            j = HFTree.getparent(j);
        }
        setcode(i);
    }
}

// 打印编码表
void HuffmanTable::printTable() {
    for (int i = 0; i < 0x80-0x0A; ++i) {
        std::cout << HuffTable[i].c << "  " << HuffTable[i].code << std::endl;
    }
}

// 对某个文件，根据本哈夫曼表进行编码
std::string HuffmanTable::encode(std::string name) {
    // 创建流对象
    std::ifstream ifs;
    ifs.open(name,std::ios::out);

    char c;
    int cnt = 0; // 记录结尾所剩的字符数
    int byte_num = 0; // 记录输入的十六进制字符的个数
    std::string pre_code; // 返回的编码预处理
    std::string code; // 返回的编码
    std::string half_byte; // 半个字节的数据
    int i = 0;
    bool flag = false;
    while ((c=ifs.get()) != EOF) {
        i = 0;
        while (true) {
            if (c == i + 0x0A) {
                std::string s = HuffTable[i].code;
                pre_code.append(HuffTable[i].code); // 字符串连接
                break;
            }
            if(i+0x0A > 0x80) {
                flag = true;
                break;
            }
            i++;
        }
    }

    // 如果存在非法字符，则输出提醒用户的文字
    if (flag) {
        std::cout << "Do not have some letters' pre_code" << std::endl;
    }

    // 关闭文件
    ifs.close();

    // 调试用输出
    std::cout << pre_code << std::endl;

    // 将01文件压缩成16进制文件
    while (pre_code.size() != 0) {
        if (pre_code.size() >= 4) {
            half_byte = pre_code.substr(0, 4);
            pre_code.erase(0, 4);

            // 将半个byte的01字符串转为16进制字符
            for (int i = 0; i < 16; ++i) {
                if (half_byte.compare(full[i]._01code) == 0) {
                    code.append(full[i]._16code);
                    byte_num++;
                }
            }
        } else {
            half_byte = pre_code;
            pre_code.clear();
            cnt = half_byte.size();

            // 对于不满四个字符的01字符串，在前面补0，并转为16进制
            for (int i = 0; i < 14; ++i) {
                if (half_byte.compare(lack[i]._01code) == 0) {
                    code.append(lack[i]._16code);
                }
            }
        }
    }

    // 判断cnt的大小，并将尾部所剩字符存储在第一个字节
    switch (cnt) {
        case 0:
            code.insert(0,"00");
            break;
        case 1:
            code.insert(0,"01");
            break;
        case 2:
            code.insert(0,"02");
            break;
        case 3:
            code.insert(0,"03");
            break;
    }

    // 两种情况，一种是写了偶数个，剩下最后奇数个半字符，另外一种是正好写了奇数个半字符
    if (byte_num % 2 == 0 || (byte_num%2==1 && cnt==0)) {
        code[0] = '1'; // 如果有偶数个，则说明生成的16进制字符串未满，将首位置为1
    } else {
        code[0] = '0';
    }

    // 将编码写入二进制文件中
    pre_code = code;
    unsigned char p;
    std::string char_byte; // int所占的4个字节
    // 创造向二进制文件写的输出流
    std::ofstream outfile ( "/Users/mengfanxing/Desktop/DS_lab2/code.dat", std::ios::out | std::ios::binary );

    // 判断是否打开
    if (!outfile) {
        std::cerr << "open error!" << std::endl;
        return code;
    }

    while (pre_code.size() != 0) {
        char_byte = pre_code.substr(0, 2);
        pre_code.erase(0,2);
        p = std::stoi(char_byte, 0, 16);
        outfile.write((char *)&p,sizeof (p));
    }

    return code;
}

// 根据文件的操作暂时搁置
// 根据次编码表译码
std::string HuffmanTable::decode(std::string name) {

    // 获取文章大小
    long size = 0;
    FILE *fp = fopen(name.c_str(), "r");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    std::string pre_code;
    std::string code;
    unsigned char c;
    FILE *fin = fopen(name.c_str(), "r");

    // 从二进制文件中读出16进制字符串
    for (int i = 0; i < size/ sizeof(unsigned char); ++i) {
        c = fgetc(fin);
        pre_code.append(CHARTO16STR(c));
    }
    fclose(fin);

    // 字符串译码预处理
    int cnt; // 01字符串编码时最后一位剩余的字符数
    int flag; // 做尾处理的flag
    std::string s; // 读取一个16进制字符编码
    flag = atoi(pre_code.substr(0,1).c_str());
    pre_code.erase(0,1);
    cnt = atoi(pre_code.substr(0,1).c_str());
    pre_code.erase(0,1);

    // 字符串译码
    while (pre_code.size() > 2) {
        s = pre_code.substr(0,1);
        pre_code.erase(0,1);
        // 匹配16进制字符串，并将其转译为01字符串
        for (int i = 0; i < 16; ++i) {
            if (s == full[i]._16code) {
                s = full[i]._01code;
                break;
            }
        }
        code.append(s);
    }

    // 对尾部进行最后的译码
    std::string tail;

    // 将尾部字符添加到tail字符串里进行后序处理
    while (pre_code.size() > 0) {
        s = pre_code.substr(0, 1);
        pre_code.erase(0, 1);
        for (int i = 0; i < 16; ++i) {
            if (s == full[i]._16code) {
                s = full[i]._01code;
                break;
            }
        }
        tail.append(s);
    }

    // flag标记了结尾是否只有一个16进制字符
    if (flag == 1) {
        tail.erase(0,4);
    }

    // 对0的处理，全部输出，其余仅保留cnt位
    if (cnt != 0) {
        if (flag == 1) {
            tail.erase(0, 4 - cnt);
        } else {
            tail.erase(4, 4 - cnt);
        }
    }
    code.append(tail);

    pre_code = code;
    code.clear();
    // 开始译为字符编码
    int i;
    while (!pre_code.empty()) {
        for (i = 0; i < 0x80-0x0A; ++i) {
            if (pre_code.substr(0,HuffTable[i].code.size()).compare(HuffTable[i].code) == 0) {
                code.append(1,HuffTable[i].c);
                pre_code.erase(0,HuffTable[i].code.size());
                break;
            }
        }
        if (i == 0x80-0x0A) {
            std::cerr << "Can't find the Huffman code!" << std::endl;
        }
    }
    return code;
}

std::string CHARTO16STR(unsigned char c) {

// 十六进制结果
    std::string result;

// 十六进制数字表
    char hex_digits[16] = {
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            'a',
            'b',
            'c',
            'd',
            'e',
            'f',
    };


// 用do while可以支持对0的转换
    do {
        // 因为转换是反向取余，所以每次得出的十六进制数字要插入到最开头
        result.insert(0, std::string() + hex_digits[c % 16]);
        c /= 16;
    } while (c > 0);

    // 统一使一个字节为两位0-f码
    while (result.size() < 2) {
        result.insert(0,"0");
    }

    return result;
}

