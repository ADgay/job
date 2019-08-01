#include "inputHeader.h"
#include "core.h"

using namespace std;

//��֪���볤��
void test0() {
	int N;
	cin >> N;
	vector<int> nums;
	int val;
	while (N--) {
		cin >> val;
		nums.push_back(val);
	}
}

//δ֪���볤��
//��֪�������
void test1() {
	int N;
	cin >> N;
	vector<vector<int> > nums;
	vector<int> tmp;
	int val;
	string s;
	while (N--) {
		getline(cin, s);
		stringstream ss(s);
		while (ss >> val) {
			tmp.push_back(val);
			//...
		}
		nums.push_back(tmp);
		tmp.clear();
	}
}

//ɶ���ⶼ��֪��
void test2() {
	ifstream fin("file.txt");
	string s;
	int val;
	vector<int> tmp;
	while (getline(fin, s)) {
		stringstream ss(s);
		while (ss >> val) {
			tmp.push_back(val);
			//...
		}
		tmp.clear();
	}
}

void func1() {
	int a, b;
	while (cin >> a >> b)//ע��while������case
		cout << a + b << endl;
}

//��˵���ж��ٸ� Input���� EOF Ϊ������־
void func2() {
	
	int a, b;
	while (cin >> a >> b) {
		// ...
	}
}

//���벻˵���ж��ٸ� Input����ĳ����������Ϊ������־
void func3() {
	
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		// ...
	}
}

//ָʾ�� N �� Input
void func4() {
	
	int n;
	cin >> n;

	int a, b;
	while (n--) {
		cin >> a >> b;
	}
}

//������һ����
//�� char[] ���գ�C/C++��
void func5() {
	
	const int MAXN = 1000;
	char buff[MAXN];
	cin.getline(buff, MAXN);  // ����������Ĭ���� '\n'
	cin.getline(buff, MAXN, '\n');
	//�� string ���գ�C++��
	string s;
	getline(cin, s);          // ����������Ĭ���� '\n'
	getline(cin, s, '\n');
}

//�����Ƕ��У������ո�
void func6() {
	
	int n;
	cin >> n;
	cin.get();  // ��һ����ָ���ƶ���'\n'֮ǰ��cin.get()���Զ���������з�������getline�����ȡһ�����С�

	while (n--) {
		string s;
		getline(cin, s);
	}
}

//���ļ���ȡ
void func7() {
	
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	int a, b;
	while (fin >> a >> b) {
		fout << a + b << endl;
	}

	fin.close();
	fout.close();
}

//���ļ���ȡ������Ϣ������
//��δָ��ÿ�г���ʱ�Ƚ�����
void func8() {
	ifstream fin("file.txt");
	string s;
	int tmp;
	while (getline(fin, s)) {//����ǰ�ж����ַ���s
		stringstream ss(s);//���ַ���sת��Ϊistream������
		while (ss >> tmp) {//��ss�������е��ַ����뵽tmp�С�
			//...
		}
	}
}