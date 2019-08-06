#include "sort.h"

using namespace std;

// ��̬��Ա������Ҫ�ڴ˳�ʼ���������ض����£�����vector��Ĭ�Ϲ��캯����
vector<vector<int> > sort::vecRandom;
vector<vector<int> > sort::vecLabel;

//��ȡ���ݲ����Ϸ���
bool sort::initialize(string dir)
{
	//read data from file and store the random list and label list to vectors.
	//check the size of two vectors.
	ifstream fin(dir);
	string label;
	string testCase;
	int tmp;
	vector<int> tmpVec;
	while (getline(fin, testCase)) {
		stringstream s1(testCase);
		cout << testCase << endl;
		while (s1 >> tmp) {
			tmpVec.push_back(tmp);
		}
		vecRandom.push_back(tmpVec);
		tmpVec.clear();

		getline(fin, label);
		stringstream s2(label);
		cout << label << endl;
		while (s2 >> tmp) {
			tmpVec.push_back(tmp);
		}
		vecLabel.push_back(tmpVec);
		tmpVec.clear();

		cout << endl;
	}
	fin.close();
	

	if (vecLabel.size() != vecRandom.size()) {
		//cout << vecLabel.size() <<"  "<< vecRandom.size() << endl;
		return false;
	}

	for (int i = 0;i < vecLabel.size();++i) {
		if (vecLabel[i].size() != vecRandom[i].size()) {
			//cout << vecLabel[i].size() <<"  "<< vecRandom[i].size() << endl;
			return false;
		}
	}
	return true;
}

//�ж�����vector�Ƿ����
bool sort::checkCore(vector<int> random, vector<int> label)
{
	if (random.size() != label.size()) return false;
	if (random.empty() && label.empty()) return true;
	for (int i = 0;i < random.size();++i) {
		if (random[i] != label[i]) return false;
	}
	return true;
}

//�ж�sort�����Ƿ�ͨ����������
void sort::check(pf p)
{
	vector<int> res;
	for (int i = 0;i < vecLabel.size();++i) {
		res = p(vecRandom[i]);
		if (!checkCore(res, vecLabel[i])) {
			cout << "wrong!" << i << endl;

			cout << "the random input : " << endl;
			for (int j = 0;j < vecRandom[i].size();++j) {
				cout << vecRandom[i][j] << ' ';
			}
			cout << endl;

			cout << "the result : " << endl;
			for (int j = 0;j < res.size();++j) {
				cout << res[j] << ' ';
			}
			cout << endl;

			cout << "the label : " << endl;
			for (int j = 0;j < vecLabel[i].size();++j) {
				cout << vecLabel[i][j] << ' ';
			}
			cout << endl;
		}
			
	}
	cout << "finish" << endl;
}

//����vector������Ԫ��
void sort::exch(vector<int>& random, int index1, int index2)
{
	int tmp = random[index1];
	random[index1] = random[index2];
	random[index2] = tmp;
	return;
}

//ѡ������
//- ÿ��ѡһ����С�ķŵ�����ǰ��
//- ����ʱ���������޹أ���ҪN^2/2�αȽ���N�ν�����
//- �����ƶ����٣�
vector<int> sort::select(vector<int> nums)
{
	if (nums.empty()) return nums;

	int N = nums.size();
	for (int i = 0;i < N;++i) {
		int min_val = nums[i];
		for (int j = i;j < N;++j) {
			if (nums[j] < min_val) {
				min_val = nums[j];
				exch(nums, i, j);
			}
		}
	}
	return nums;
}

//��������
//- �����ٶ������ݷֲ��йأ������ݲ�������ʱ�ٶȽϿ�
//- ��Ҫ�϶�Ľ�������
vector<int> sort::insert(vector<int> nums) {
	int N = nums.size();
	for (int i = 1;i < N;++i) {
		int j = i;
		while (nums[j] < nums[j - 1] && j >= 1) {
			exch(nums, j-1, j);
			--j;
		}
	}
	return nums;
}

//ϣ������
//- Ψһ�޷�׼ȷ��������������������������
//- һ���ƶ���Զ�ľ��룬����������ٶ�.
//- ���������������ر��ʱ���ٶȽ��ȸ߼�������һ���������Ҵ���򵥣������ռ䣮
vector<int> sort::shell(vector<int> A)
{
	int N = A.size();
	int h = 0;
	while (h < N / 3) h = h * 3 + 1;
	while (h >= 1) {
		for (int i = h;i < N;++i) {
			int j = i;
			while (A[j] < A[j - h] && j >= h) {
				exch(A, j, j - h);
				j -= h;
			}
		}
		h /= 3;
	}
	return A;
}



vector<int> sort::quick(vector<int> nums)
{
	return vector<int>();
}
