#include <iostream>
#include <string>
using namespace std;

/*����������� ��������� ����� ��� ������
� ���������. ����������� ���������
�������� �������� �������������
(�����������) ���� ��� ������� ��������
��� �����,
��� �����������, ���� �����.
����������� ������������� �������� ���������.*/

template<typename T>
class Array {
	T* str;
	int size;
public:
	Array() : Array(80) {} //����������� �������
	Array(int s) {
		size = s;
		str = new T[size];
	}
	Array(const Array& copys) { //����������� �����������
		size = copys.size;
		str = new T[size];
		for (int i = 0; i < size; i++) {
			str[i] = copys.str[i];
		}
	}

	~Array() {
		if (str) {
			delete[] str;
		}
	}

	T get_value(int);

	void set_value(T, int);
	Array operator + (const Array& plus) const;

	template<typename T>
	friend ostream& operator << (ostream& stream, const Array<T>& st);
};


template<typename T>
ostream& operator << (ostream& stream, const Array<T>& st) { //������� � �������� ��������� ����� �������
	stream << "[";
	for (int i = 0; i < st.size-1; i++) {
		stream << st.str[i] << ", ";
	} stream << st.str[st.size - 1] << "]";
	return stream;
}

template<typename T>
T Array<T>::get_value(int index) { //�������� �������� �� �������
	return this->str[index];
}

template<typename T>
void Array<T>::set_value(T x, int index) { //������ �������� �� �������
	this->str[index] = x;
}

template<typename T>
Array<T> Array<T>::operator + (const Array<T>& plus) const {
	Array temp(size + plus.size);
	int i = 0;
	for (; i < this->size; i++) {
		temp.str[i] = this->str[i];
		//cout << i << " " << temp.str[i] << endl;
	}
	for (int j = 0; j < plus.size; i++, j++) {
		temp.str[i] = plus.str[j];
		//cout << i << " " << temp.str[i] << endl;
	}
	return temp;
}

template<>
Array<int> Array<int>::operator + (const Array<int>& plus) const { //��������� ��������� �������� (���� ������������� ������(����������))
	int tsize;
	if (size >= plus.size) { //����� ������� �������(�� �������� �� 2)
		tsize = size;
	}
	else {
		tsize = plus.size;
	}
	Array<int> temp(tsize);

	for (int i = 0; i < tsize; i++) {
		temp.str[i] = this->str[i] + plus.str[i];
		//cout << this->str[i] << " " << plus.str[i] << endl;
	}
	
	return temp;
}


int main() {
	int size = 15;
	Array<int> arr1(size), arr2(size);

	for (int i = 0; i < size; i++) { //��������� ��������(����������� ������ ��� ��������)
		arr1.set_value(15, i);
		arr2.set_value(14, i);
	}

	cout << (arr1 + arr2);

}

