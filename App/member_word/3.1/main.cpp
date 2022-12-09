#include "./test/test_user_log.h"
using namespace std;

int main()
{
	test_user_log();



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

	return 0;

}
