//
// Created by 22490 on 2022/12/18.
//

#include "word.h"
#include "mysql.h"

using namespace std;

Word::Word(ReadUserInfo& info)
{
	srand((size_t)(time(nullptr)));

	// 为中文意思开空间
	for (auto& ps : this->ch)
	{
		ps = new string[MAX_WORD_SIZE];
	}

	// 为英文开空间
	for (auto& ps : this->en)
	{
		ps = new string[MAX_WORD_SIZE];
	}

	// 从数据库读取今天的单词
	info.GetWord();
	info.res = mysql_store_result(&info.mysql); // 获取结果集
	unsigned int num_columns = mysql_field_count(&info.mysql); // 结果集中 列数
	info.row = mysql_fetch_row(info.res); // 检索结果集的下一行 每行有 num_columns 列
	while (info.row)
	{
		int now = stoi(string(info.row[0])) - 1;

		for (int i = 1; i < 5; i++)
		{
			en[i - 1][now] = info.row[i];
		}
		for (int i = 5; i < num_columns; i++)
		{
			ch[i - 5][now] = info.row[i];
		}

		info.row = mysql_fetch_row(info.res);
	}

	// 读取记录
	save = current = info.GetCurrent();

	// 每天多少个
	today = info.GetEveryDay();

	// 读取暂停方式
	isPause = info.GetPauseWay();

	// 获取随机的选项
	GetRandOptions();
}

Word::~Word()
{
	// 销毁保存中文的string
	for (auto& i : ch)
	{
		delete[] i;
	}
	// 销毁保存英文的string
	for (auto& i : en)
	{
		delete[] i;
	}
}

void Word::GetRandOptions()
{
	// 获取0~3的不重复的随机数，作为选项
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		randArray[i] = -1; // 先给上-1，以免重复
	}
	i = 0;
	while (i < 4)
	{
		int temp = rand() % 4;
		if (randArray[0] != temp && randArray[1] != temp && randArray[2] != temp && randArray[3] != temp)
		{
			// 获取到的随机值和数组的其他值都不同的时候给数组赋值，然后 i++
			randArray[i] = temp;
			i++;
		}
	}
}

void Word::ChooseChinses()
{
	for (int i = 0; i < today; i++)
	{
		CheckOver();
		cout << "******************************************" << endl;
		cout << "  中文选择模式，输入exit可以退出当前模式" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "英文为：" << this->GetLineEnglish() << " (" << this->current + 1 << "/4449)\n" << endl;
		cout << this->GetFourChinese() << endl;

		this->current++;

		while (true)
		{
			string input;
			cin.clear();
			cout << "请输入选项：";
			cin >> input;

			if (toupper(input[0]) == (this->Options[this->GetCorrectOption()]))
			{
				if (isPause)
				{
					system("pause");
				}
				system("cls");
				break;
			}
			else if (input.compare("exit") == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "不是这个选项哦" << endl;
			}
		}

		this->GetRandOptions();
		this->SaveRecord();
	}
}

void Word::ChooseEnglish()
{
	for (int i = 0; i < today; i++)
	{
		CheckOver();
		cout << "******************************************" << endl;
		cout << "  英文选择模式，输入exit可以退出当前模式" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "中文为：" << this->GetLineChinese() << " (" << this->current + 1 << "/4449)\n" << endl;
		cout << this->GetFourEnglish() << endl;

		this->current++;

		while (true)
		{
			string input;
			cin.clear();
			cout << "请输入选项：";
			cin >> input;

			if (toupper(input[0]) == (this->Options[this->GetCorrectOption()]))
			{
				if (isPause)
				{
					system("pause");
				}
				system("cls");
				break;
			}
			else if (input.compare("exit") == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "不是这个选项哦" << endl;
			}
		}

		this->GetRandOptions();
		this->SaveRecord();
	}
}

void Word::InputEnglish()
{
	while (true)
	{
		CheckOver();
		cout << "******************************************" << endl;
		cout << "    输入模式，输入exit可以退出当前模式" << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << "中文意思为：" << this->GetLineChinese() << " (" << this->current + 1 << "/4449)\n" << endl;

		string getEnglish = this->GetLineEnglish();
		// this->current++;

		string input;
		while (true)
		{
			cin.clear();
			cout << "请输入:>";
			cin >> input;

			if (input.compare(getEnglish) == 0)
			{
				if (isPause)
				{
					system("pause");
				}
				system("cls");
				break;
			}
			else if (input.compare("next") == 0)
			{
				cout << "这个单词是：" << getEnglish << endl;
				system("pause");
				system("cls");
				break;
			}
			else if (input.compare("exit") == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "这个单词不是这样拼的哦(不会的话可以输入next跳过当前的，直接下一个)" << endl;
			}
		}

		this->SaveRecord();
	}
}

void Word::ChangPauseWay()
{
	system("cls");
	cout << "原有方式：";
	if (isPause)
	{
		cout << "背完后暂停" << endl;
	}
	else
	{
		cout << "背完后不暂停" << endl;
	}

	this->isPause = !this->isPause;

	cout << "现在方式：";
	if (isPause)
	{
		cout << "背完后暂停" << endl;
	}
	else
	{
		cout << "背完后不暂停" << endl;
	}

	system("pause");
}

int Word::GetCorrectOption()
{
	int correct = -1;
	for (int i = 0; i < 4; i++)
	{
		if (randArray[i] == 0)
		{
			correct = i;
			break;
		}
	}
	return correct;
}

string Word::GetLineEnglish()
{
	return this->en[0][current];
}

string Word::GetFourChinese()
{
	string s;
	for (int i = 0; i < 4; i++)
	{
		s += Options[i];
		s += "：";
		s += ch[randArray[i]][current];
		s += '\n';
	}
	return s;
}

string Word::GetLineChinese()
{
	return this->ch[0][current];
}

string Word::GetFourEnglish()
{
	string s;
	for (int i = 0; i < 4; i++)
	{
		s += Options[i];
		s += "：";
		s += en[randArray[i]][current];
		s += '\n';
	}
	return s;
}

void Word::SaveRecord()
{

}

void Word::CheckOver()
{
	if (current >= MAX_WORD_SIZE)
	{
		current = 0;
		cout << "恭喜，已经背完了哦，将自动把记录归零" << endl;
		system("pause");
		system("cls");
	}
}

void Word::Flush()
{
	current = save;
}

void Word::Upload(ReadUserInfo& log_info)
{
	log_info.Upload(save + today, today, isPause);
}
