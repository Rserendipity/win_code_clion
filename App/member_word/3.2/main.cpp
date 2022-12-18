/* 整体逻辑如下：
 * 1、用户登录，使用 ReadUserInfo 类，判断用户输入合法后转为 mysql 语句，通过 sql 语句返回值判断是否存在用户
 * 2、登录成功以后需要通过 ReadUserInfo 类获取用户的信息：当前的记录，每天需要背的个数
 * 3、进行背单词的逻辑
 * 4、背完以后记录，上传至 mysql
 *
 * */

#include <iostream>
#include "user_log/ReadUserInfo.h"
#include "word/word.h"

using namespace std;

void UserLogIn(ReadUserInfo& log_info)
{
	string userName;
	string userPasswd;
	while (true)
	{
		cout << "请输入用户名：" << endl;
		cin >> userName;
		for (auto& ch : userName)
		{
			if (!(isdigit(ch) || isalpha(ch)))
			{
				cout << "用户名非法！" << endl;
				continue;
			}
		}

		cout << "请输入密码：" << endl;
		cin >> userPasswd;
		for (auto& ch : userPasswd)
		{
			if (!(isdigit(ch) || isalpha(ch)))
			{
				cout << "密码非法！" << endl;
				continue;
			}
		}

		log_info.ChangUser(userName, userPasswd);
		break;
	}
}


int main()
{
	system("chcp 65001"); // 更改字符集为utf-8
	system("cls");

	ReadUserInfo log_info;

	while (true)
	{
		UserLogIn(log_info);

		if (log_info.Exist())
		{
			system("cls");
			cout << "登录成功！" << endl;
			cout << "当前进度：" << log_info.GetCurrent() + 1 << endl;
			break;
		}
		else
		{
			cout << "用户名或密码错误" << endl;
			system("pause");
			system("cls");
		}
	}

	// 2
	cout << "正在加载你的单词数据........" << endl;
	Word word(log_info);
	cout << "加载完成......" << endl;
	system("pause");
	system("cls");

	word.ChooseEnglish();
	word.Flush();
	word.ChooseChinses();
	word.Upload(log_info);

	return 0;
}
