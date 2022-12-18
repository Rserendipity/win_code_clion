//
// Created by 22490 on 2022/12/18.
//

#ifndef INC_3_2__USER_LOG_H_
#define INC_3_2__USER_LOG_H_
#include "mysql.h"
#include <iostream>
#include <string>

class ReadUserInfo
{
 public:
	ReadUserInfo()
		: mysql(), res(nullptr), row(nullptr), _current(0), _every_day(0), _user_exist(false)
	{
		mysql_init(&mysql);
		if (!mysql_real_connect(&mysql, "1.15.113.185", "cjj", "Cjj020427@", "cjj", 3306, nullptr, 0))
		{
			std::cout << "连接数据库失败，请检查网络！" << std::endl;
			exit(-1);
		}
		else
		{
			std::cout << "数据库连接成功...." << std::endl;
		}
	}

	~ReadUserInfo()
	{
		mysql_free_result(res);
		mysql_close(&mysql);
	}

	int GetCurrent() const
	{
		return _current;
	}

	int GetEveryDay() const
	{
		return _every_day;
	}

	bool GetPauseWay() const
	{
		return _user_pause_way;
	}

	bool Exist() const
	{
		return _user_exist;
	}

	void ChangUser(const std::string& name, const std::string& password)
	{
		this->name = name;
		this->passwd = password;
		// 拼接 sql 语句
		_query = "select * from user_info where user_name like '";
		_query += name;
		_query += "' and user_password like '";
		_query += password;
		_query += "';";

		// std::cout << _query << std::endl; // 测试 sql 语句

		mysql_query(&mysql, _query.c_str());

		res = mysql_store_result(&mysql); // 获取结果集
		if (res->row_count) // 结果集中的行数，不为0的时候用户存在，读取用户的信息
		{
			_user_exist = true;
			row = mysql_fetch_row(res);
			_current = stoi(std::string(row[2]));
			_every_day = stoi(std::string(row[3]));
			_user_pause_way = stoi(std::string(row[4]));
		}
	}

	void GetWord()
	{
		std::string query("select * from word where id >= ");
		query += std::to_string(_current + 1);
		query += " and id <= ";
		query += std::to_string(_current + _every_day);
		query += ";";

		mysql_query(&mysql, "set names utf8");
		mysql_query(&mysql, query.c_str());
	}

	void Upload(int current, int today, bool isPause)
	{
		_query =  "update user_info set user_current_save=";
		_query += std::to_string(current);
		_query += ",user_everyday_num=";
		_query += std::to_string(today);
		_query += ",user_pause_way=";
		_query += isPause ? "true" : "false";
		_query += " where user_name like '";
		_query += name;
		_query += "';";

		mysql_query(&mysql, _query.c_str());
	}


 public:
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;

 private:
	bool _user_exist;
	bool _user_pause_way;
	int _current;
	int _every_day;
	std::string _query;
	std::string name;
	std::string passwd;
};

#endif //INC_3_2__USER_LOG_H_
