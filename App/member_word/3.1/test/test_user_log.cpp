//
// Created by 22490 on 2022/12/9.
//

#include "test_user_log.h"
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

void test_user_log()
{
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	std::string query("select * from user_info where user_name like \"");
	string tmp;
	if (Connect(mysql))
	{
		std::cout << "Connect success!" << std::endl;
	}

	cin >> tmp;
	query += tmp;
	query += "\" and user_password like \"";
	cin >> tmp;
	query += tmp;
	query += "\"";


	mysql_query(&mysql, query.c_str());

	// 查询结果集中的行数
	res = mysql_store_result(&mysql); // 获取结果集
	unsigned int num_rows = res->row_count; // 结果集中 行数
	printf("num_rows = %d\n", num_rows);


}