#include <stdio.h> 
#include <string> 
using namespace std; 
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
const char* str, int& pathLength, bool* visited); 
/***************************************** 
功能： 查找矩阵中是否含有 str 指定的字串 
参数说明： 
matrix 输入矩阵 
rows 
矩阵行数 
cols 
矩阵列数 
str 
要搜索的字符串 
返回值： 是否找到 true 是，false 否 
*******************************************/ 
bool hasPath(const char* matrix, int rows, int cols, const char* str) 
{ 
	if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) 
	return false; 
	bool *visited = new bool[rows * cols]; 
	memset(visited, 0, rows * cols); 
	int pathLength = 0; 
	//遍历矩阵中每个点，做为起点开始进行搜索 
	for(int row = 0; row < rows; ++row) 
	{ 
	for(int col = 0; col < cols; ++col) 
	{ 
	if(hasPathCore(matrix, rows, cols, row, col, str, 
	pathLength, visited)) 
	{ 
	return true; 
	} 
	} 
	}
	delete[] visited; 
	return false; 
}
/*探测下一个字符是否存在*/ 
bool hasPathCore(const char* matrix, int rows, int cols, int row, 
int col, const char* str, int& pathLength, bool* visited) 
{ 
	if(str[pathLength] == '\0') 
	return true; 
	bool hasPath = false; 
	if(row >= 0 && row < rows && col >= 0 && col < cols 
	&& matrix[row * cols + col] == str[pathLength] 
	&& !visited[row * cols + col]) 
{ 
	++pathLength; 
	visited[row * cols + col] = true; 
	hasPath = hasPathCore(matrix, rows, cols, row, col - 1, 
	str, pathLength, visited) 
	|| hasPathCore(matrix, rows, cols, row - 1, col, 
	str, pathLength, visited) 
	|| hasPathCore(matrix, rows, cols, row, col + 1, 
	str, pathLength, visited) 
	|| hasPathCore(matrix, rows, cols, row + 1, col, 
	str, pathLength, visited); 
	if(!hasPath) 
	{ 
	--pathLength; 
	visited[row * cols + col] = false; 
	} 
	}
	return hasPath; 
}
/*单元测试代码*/ 
void Test(const char* testName, const char* matrix, int rows, int cols, 
const char* str, bool expected) 
{ 
	if(testName != nullptr) 
	printf("%s begins: ", testName); 
	if(hasPath(matrix, rows, cols, str) == expected) 
	printf("Passed.\n"); 
	else
	printf("FAILED.\n"); 
} 
//ABTG 
//CFCS 
//JDEH 
//BFCE 
void Test1() 
{ 
	const char* matrix = "ABTGCFCSJDEH"; 
	const char* str = "ABTE"; 
	Test("功能测试 1", (const char*) matrix, 3, 4, str, true); 
}
//ABCE 
//SFCS 
//ADEE 
//SEE 
void Test2() 
{ 
	const char* matrix = "ABCESFCSADEE"; 
	const char* str = "SEE"; 
	Test("功能测试 2", (const char*) matrix, 3, 4, str, true); 
}
//ABTG 
//CFCS 
//JDEH 
//ABFB 
void Test3() 
{ 
	const char* matrix = "ABTGCFCSJDEH"; 
	const char* str = "ABFB"; 
	Test("功能测试 3", (const char*) matrix, 3, 4, str, false); 
}
//ABCEHJIG 
//SFCSLOPQ 
//ADEEMNOE 
//ADIDEJFM 
//VCEIFGGS 
//SLHECCEIDEJFGGFIE 
void Test4()
{ 
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS"; 
	const char* str = "SLHECCEIDEJFGGFIE"; 
	Test("功能测试 4", (const char*) matrix, 5, 8, str, true); 
}
//ABCEHJIG 
//SFCSLOPQ 
//ADEEMNOE 
//ADIDEJFM 
//VCEIFGGS 
//SGGFIECVAASABCEHJIGQEM 
void Test5() 
{ 
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS"; 
	const char* str = "SGGFIECVAASABCEHJIGQEM"; 
	Test("功能测试 5", (const char*) matrix, 5, 8, str, true); 
}
//ABCEHJIG 
//SFCSLOPQ 
//ADEEMNOE 
//ADIDEJFM 
//VCEIFGGS 
//SGGFIECVAASABCEEJIGOEM 
void Test6() 
{ 
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS"; 
	const char* str = "SGGFIECVAASABCEEJIGOEM"; 
	Test("功能测试 6", (const char*) matrix, 5, 8, str, false); 
}
//ABCEHJIG 
//SFCSLOPQ 
//ADEEMNOE 
//ADIDEJFM 
//VCEIFGGS 
//SGGFIECVAASABCEHJIGQEMS 
void Test7() 
{ 
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJI8G9Q7E9M4S3"; 
	Test("功能测试 7", (const char*) matrix, 5, 8, str, false); 
}
//AAAA 
//AAAA 
//AAAA 
//AAAAAAAAAAAA 
void Test8() 
{ 
	const char* matrix = "AAAAAAAAAAAA"; 
	const char* str = "AAAAAAAAAAAA"; 
	Test("边界值测试 8", (const char*) matrix, 3, 4, str, true); 
}
//AAAA 
//AAAA 
//AAAA 
//AAAAAAAAAAAAA 
void Test9() 
{ 
const char* matrix = "AAAAAAAAAAAA"; 
const char* str = "AAAAAAAAAAAAA"; 
Test("边界值测试 9", (const char*) matrix, 3, 4, str, false); 
}
//A 
//A 
void Test10() 
{ 
	const char* matrix = "A"; 
	const char* str = "A"; 
	Test("边界值测试 10", (const char*) matrix, 1, 1, str, true); 
}
//A 
//B 
void Test11() 
{ 
const char* matrix = "A"; 
const char* str = "B"; 
Test("边界值测试 11", (const char*) matrix, 1, 1, str, false); 
}

void Test12() 
{ 
	Test("特殊情况测试 12", nullptr, 0, 0, nullptr, false); 
}

int main(int argc, char* argv[]) 
{ 
	Test1(); 
	//Test2(); 
	//Test3(); 
	//Test4(); 
	//Test5(); 
	//Test6(); 
	//Test7(); 
	//Test8(); 
	//Test9(); 
	//Test10(); 
	//Test11(); 
	//Test12(); 

	system("pause"); 
	return 0; 
}
