#include <iostream>
#include <bits/stdc++.h>
#include <mysql.h>
using namespace std;

bool Connect(MYSQL& mysql)
{
	mysql_init(&mysql);
	//if (!mysql_real_connect(&mysql, "localhost", "root", "123456", "cjj", 3306, nullptr, 0))
	if (!mysql_real_connect(&mysql, "1.15.113.185", "cjj", "Cjj020427@", "cjj", 3306, nullptr, 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	std::string query;
	int flag, t;

	if (Connect(mysql))
	{
		cout << "Connect success" << endl;
	}
	else
	{
		cout << "Failed to connect to Mysql!" << endl;
		exit(-1);
	}

	char* tmp = new char[2000];
	fstream fen0("F:\\code\\tmp\\111\\data\\en0.txt", ios::in);
	fstream fen1("F:\\code\\tmp\\111\\data\\en1.txt", ios::in);
	fstream fen2("F:\\code\\tmp\\111\\data\\en2.txt", ios::in);
	fstream fen3("F:\\code\\tmp\\111\\data\\en3.txt", ios::in);

	fstream fch0("F:\\code\\tmp\\111\\data\\ch0.txt", ios::in);
	fstream fch1("F:\\code\\tmp\\111\\data\\ch1.txt", ios::in);
	fstream fch2("F:\\code\\tmp\\111\\data\\ch2.txt", ios::in);
	fstream fch3("F:\\code\\tmp\\111\\data\\ch3.txt", ios::in);

	vector<string> v;
	v.resize(4449);

	for (int i = 0; i < 4449; i++)
	{
		v[i] += "insert into word values (";
		fen0.getline(tmp, 2000);
		v[i] += to_string(i + 1);
		v[i] += ",";
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}
	for (int i = 0; i < 4449; i++)
	{
		fen1.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}
	for (int i = 0; i < 4449; i++)
	{
		fen2.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}
	for (int i = 0; i < 4449; i++)
	{
		fen3.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}

	for (int i = 0; i < 4449; i++)
	{
		fch0.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}
	for (int i = 0; i < 4449; i++)
	{
		fch1.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}
	for (int i = 0; i < 4449; i++)
	{
		fch2.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\",";
	}
	for (int i = 0; i < 4449; i++)
	{
		fch3.getline(tmp, 2000);
		v[i] += "\"";
		v[i] += tmp;
		v[i] += "\");";
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << "now is :" << i << endl;
		string& s = v[i];
		flag = mysql_query(&mysql, s.c_str());

		if (flag)
		{
			cout << s << endl;
			cout << mysql_error(&mysql) << endl;
			cout << "err!" << endl;
			return 0;
		}
	}

//	cout << v[1231] << endl;



//	for (int j = 0; j < 4449; j++)
//	{
//		query += "insert into word values (";
//		for (int i = '0'; i < '4'; i++)
//		{
//			string en;
//
//			en += "F:\\code\\tmp\\111\\data\\en";
//			en += i;
//			en += ".txt";
//			fen.getline(tmp, 2000);
//			query += "\'";
//			query += tmp;
//			query += "\'";
//			query += ",";
//		}
//		for (int i = '0'; i < '4'; i++)
//		{
//			string en;
//
//			en += "F:\\code\\tmp\\111\\data\\ch";
//			en += i;
//			en += ".txt";
//			fstream fen(en, ios::in);
//			fen.getline(tmp, 2000);
//			query += "\'";
//			query += tmp;
//			query += "\'";
//			if (i != '3')
//				query += ",";
//		}
//		query += ");";
//		cout << query << endl;
//		// flag = mysql_real_query(&mysql, query.c_str(), query.length());
//
//		flag = mysql_query(&mysql, query.c_str());
//
//		if (flag)
//		{
//			cout << mysql_error(&mysql) << endl;
//			cout << "err!" << endl;
//			return 0;
//		}
//
//		query.clear();
//	}

	// query = "insert into word values ('remind','map','insight','accompany','vt. 提醒；使想起','n. 猜测；推测 vi. 猜；推测；猜中 vt. 猜测；认为；推测；猜中 n. 盖尔斯（美国服装品牌）','n. 运动；练习；运用；操练；礼拜；典礼 vt. 锻炼；练习；使用；使忙碌；使惊恐 vi. 运动；练习','n. 脸；表面；面子；面容；外观；威信 vi. 向；朝 vt. 面对；面向；承认；抹盖 ');";

//	flag = mysql_real_query(&mysql, query.c_str(), query.length());
//	if (flag)
//	{
//		cout << "err!" << endl;
//		return 0;
//	}

//	res = mysql_store_result(&mysql); // 获取结果集
//	unsigned int num_columns = mysql_field_count(&mysql); // 结果集中 列数
//	unsigned int num_rows = res->row_count; // 结果集中 行数
//	printf("num_columns = %d\n", num_columns);
//	printf("num_rows = %d\n", num_rows);
//	row = mysql_fetch_row(res); // 检索结果集的下一行 每行有 num_columns 列
//	std::string result;
//	int index = 0;
//	while (row)
//	{
//		printf("%d\t", ++index);
//
//		for (t = 0; t < num_columns; t++)
//			printf("%s\t", row[t]);
//		printf("\n");
//		row = mysql_fetch_row(res);
//	}
//	printf("index = %d\n", index);
//	mysql_free_result(res);
//	mysql_close(&mysql);

	cout << "send success" << endl;
	return 0;

}
