//
// Created by 22490 on 2022/12/18.
//

#ifndef INC_3_2_WORD_WORD_H_
#define INC_3_2_WORD_WORD_H_

#include "../user_log/ReadUserInfo.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include <fstream>


class Word
{
 public:
	const int MAX_WORD_SIZE = 4449;                  // 总共的单词数量
	const char Options[4] = { 'A', 'B', 'C', 'D' };  // 选项数组

	Word(ReadUserInfo& log_info);   // 构造，读取所有的单词信息
	~Word();  // 析构，销毁所有的单词信息

	void ChooseChinses();  // 选中文模式
	void ChooseEnglish();  // 选英文模式
	void InputEnglish();   // 输入英文模式
	void ChangPauseWay();  // 更改暂停方式
	void Flush();
	void Upload(ReadUserInfo& log_info);

 private:
	Word(const Word&);          //禁止拷贝构造

	void GetRandOptions();    // 获取随机数选项
	int GetCorrectOption();   // 获取正确的选项
	void SaveRecord();        // 保存记录
	void CheckOver();         // 检查是否已经背完，背完以后会自动清零

	std::string GetLineEnglish();  // 获取一行英文
	std::string GetFourChinese();  // 获取四行中文
	std::string GetLineChinese();  // 获取一行中文
	std::string GetFourEnglish();  // 获取四行英文

	int current;              // 记录
	int randArray[4];          // 获取随机数作为选项
	int save;
	int today;
	std::string* ch[4];              // 存储中文
	std::string* en[4];              // 存储英文

	bool isPause;
};

#endif //INC_3_2_WORD_WORD_H_
